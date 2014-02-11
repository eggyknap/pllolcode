/*
 * $Id: pllolcode.c,v 1.33 2009/11/03 22:07:23 eggyknap Exp $
 */

 /* TODO: LOL-ify error messages :) */
 /* TODO: Add function line numbers to error messages */

#include "pllolcode.h"
#include "access/htup_details.h"
#include "executor/spi.h"
#include "commands/trigger.h"
#include "fmgr.h"
#include "funcapi.h"
#include "access/heapam.h"
#include "utils/syscache.h"
#include "catalog/pg_proc.h"
#include "catalog/pg_type.h"
#include "utils/lsyscache.h"
#include "utils/memutils.h"
#include "utils/builtins.h"
#include "pllolcode_lang.h"
#include "postgres.h"

    /* Who could ever want more? :) This doesn't have to be terribly precise,
     * as it's used only to initialize the function hash table */
const int LOLCODE_FUNCS_PER_USER = 2;  

PG_MODULE_MAGIC;

extern int  pllolcode_yyparse(void *result);
lolProgram *lolFindProgram(FunctionCallInfo fcinfo);
lolProgram *lolHashTableSearch(Oid funcoid, int numargs, Oid *argtypes);
Datum       lolRunProgram(FunctionCallInfo fcinfo, lolProgram *program);
Datum       pl_lolcode_call_handler(PG_FUNCTION_ARGS);
Datum       pl_lolcode_validator(PG_FUNCTION_ARGS);
void        lolHashTableStore(FunctionCallInfo fcinfo, lolProgram *program);

PG_FUNCTION_INFO_V1(pl_lolcode_call_handler);
PG_FUNCTION_INFO_V1(pl_lolcode_validator);

lolIdent *returnVal;

static HTAB *pl_lolcode_HashTable = NULL;

void _PG_init(void) {
    /* mostly code stolen from PL/pgSQL */
    HASHCTL ctl;

    memset(&ctl, 0, sizeof(ctl));
    ctl.keysize = sizeof(pl_lolcode_HashKey);
    ctl.entrysize = sizeof(pl_lolcode_HashEnt);
    ctl.hash = tag_hash;
    pl_lolcode_HashTable = hash_create("PL/LOLCODE function cache",
            LOLCODE_FUNCS_PER_USER,
            &ctl,
            HASH_ELEM | HASH_FUNCTION);
}

Datum
lolRunProgram(FunctionCallInfo fcinfo, lolProgram *program) {
    char *tmp, *rettmp;
    int i;
    Datum retval = (Datum) NULL;

    if (SPI_connect() != SPI_OK_CONNECT) 
        ereport(ERROR, (errcode(ERRCODE_CONNECTION_EXCEPTION),
            errmsg("Couldn't connect to SPI"))); 


    lolInitVars();

    /* Set a lolIdent variable for each input argument */
    /* TODO: I already have argument types (and modes, if I ever care to use them), so pass them to LOLifyDatum instead of 
     * making it find them out itself */
    for (i = 0; i < program->numargs; i++)
        LOLifyDatum(fcinfo->arg[i], fcinfo->argnull[i], program->argtypes[i], program->argnames[i]);

    executeProgram(program->parsetree);

    rettmp = NULL;
    if (program->returntype != VOIDOID) {
        if (returnVal != NULL) {
            if (returnVal->type == ident_NOOB) fcinfo->isnull = true;
            else {
                if (program->returntype == BOOLOID)
                    retval = InputFunctionCall(&program->ret_flinfo, lolVarGetTroof(returnVal) == lolWIN ? "T" : "F", program->returnTypeIOParam, -1);
                else {
                    tmp = lolVarGetString(returnVal, true);
                    i = strlen(tmp) + 1;
                    rettmp = SPI_palloc(i);
                    memcpy(rettmp, tmp, i);
                }
            }
        }
        else fcinfo->isnull = true;
    }

    SPI_finish();

    if (program->returntype != BOOLOID && rettmp != NULL && program->returntype != VOIDOID) 
        retval = InputFunctionCall(&program->ret_flinfo, rettmp, program->returnTypeIOParam, -1);

    return retval;
}

lolProgram *
lolHashTableSearch(Oid funcoid, int numargs, Oid *argtypes) {
    pl_lolcode_HashKey  key;
    pl_lolcode_HashEnt *entry;

    MemSet(&key, 0, sizeof(pl_lolcode_HashKey));
    key.funcoid = funcoid;
    key.isTrigger = false;
    key.trigrelOid = 0;
    memcpy(key.argtypes, argtypes, sizeof(Oid) * numargs);

    entry = (pl_lolcode_HashEnt *) hash_search(pl_lolcode_HashTable,
                                                (void*) &key,
                                                HASH_FIND,
                                                NULL);
    if (entry == NULL)
        return NULL;
    else {
        elog(NOTICE, "Found PL/LOLCODE proc in hash table");
        return entry->program;
    }
}

void
lolHashTableStore(FunctionCallInfo fcinfo, lolProgram *program) {
    pl_lolcode_HashKey key;
    pl_lolcode_HashEnt *entry;
    bool found;

    /* Build key */
    /* Make sure key is zeroed out, first -- this is IMPORTANT */
    MemSet(&key, 0, sizeof(pl_lolcode_HashKey));
    key.funcoid = fcinfo->flinfo->fn_oid;
    key.isTrigger = false;   /* TODO: Change this when we support triggers */
    key.trigrelOid = 0;
    memcpy(key.argtypes, program->argtypes, sizeof(Oid) * program->numargs);

    entry = (pl_lolcode_HashEnt *) hash_search(pl_lolcode_HashTable,
                                                (void *) &key,
                                                HASH_ENTER,
                                                &found);
    
    if (found)
        elog(WARNING, "trying to insert a function that already exists");

    elog(DEBUG3, "Storing function in hash table");
    /* Build entry */
    entry->program = program;
}

lolProgram *
lolFindProgram(FunctionCallInfo fcinfo) {
    Form_pg_type typeStruct;
    Form_pg_proc procStruct;
    HeapTuple typeTup;
    HeapTuple procTup;
    MemoryContext orig_cxt, lol_cxt;
    Datum procsrcdatum;
    lolProgram *program;
    bool isnull;
    char *proc_source;
    char **argnames;
    char *argmodes;
    Oid *argtypes;
    int parseres, numargs, i;

    /* Must get the proc tuple, then find argument and return type information, and proc source */

    /* Get procedure tuple */
    procTup = SearchSysCache(PROCOID, ObjectIdGetDatum(fcinfo->flinfo->fn_oid), 0, 0, 0);
    if (!HeapTupleIsValid(procTup)) elog(ERROR, "Cache lookup failed for procedure %u", fcinfo->flinfo->fn_oid);
    procStruct = (Form_pg_proc) GETSTRUCT(procTup);

    /* Get proc's number of arguments, argument types, and argument names */
    numargs = get_func_arg_info(procTup, &argtypes, &argnames, &argmodes);

    /* look for program in hash table, and return it if if already exists */
    program = lolHashTableSearch(fcinfo->flinfo->fn_oid, numargs, argtypes);
    if (program == NULL) {
        /* It doesn't already exist, so do the time-consuming stuff */
        /* Create long-lived memory context */
        lol_cxt = AllocSetContextCreate(TopMemoryContext,
                        "PL/LOLCODE function context",
                        ALLOCSET_DEFAULT_MINSIZE,
                        ALLOCSET_DEFAULT_INITSIZE,
                        ALLOCSET_DEFAULT_MAXSIZE);

        orig_cxt = MemoryContextSwitchTo(lol_cxt);

        /* Create and fill program object */
        program = (lolProgram *) palloc(sizeof(lolProgram));
        program->numargs = numargs;
        program->argtypes = palloc(sizeof(Oid) * numargs);
        memcpy(program->argtypes, argtypes, sizeof(Oid) * numargs);
        if (argmodes != NULL)
            program->argmodes = pstrdup(argmodes);
        else
            program->argmodes = NULL;
        program->argnames = palloc(sizeof(char *) * numargs);
        for (i = 0; i < numargs; i++)
            program->argnames[i] = pstrdup(argnames[i]);

        /* Get return type tuple */
        typeTup = SearchSysCache(TYPEOID, ObjectIdGetDatum(procStruct->prorettype), 0, 0, 0);
        if (!HeapTupleIsValid(typeTup)) elog(ERROR, "Cache lookup failed for type %u", procStruct->prorettype);
        typeStruct = (Form_pg_type) GETSTRUCT(typeTup);
    
        /* Using TopMemoryContext here isn't the greatest thing, but PL/Perl does
        * it (admitting all along that it's not the best thing... */
        fmgr_info_cxt(typeStruct->typinput, &program->ret_flinfo, TopMemoryContext);
        program->returnTypeIOParam = getTypeIOParam(typeTup);
        program->returntype = procStruct->prorettype;

        ReleaseSysCache(typeTup);

        /* Get proc source */
        procsrcdatum = SysCacheGetAttr(PROCOID, procTup, Anum_pg_proc_prosrc, &isnull);
        if (isnull)
            elog(ERROR, "Function source is null");

#ifdef TextDatumGetCString
        proc_source = TextDatumGetCString(procsrcdatum);
#else
        /* For PostgreSQL versions 8.3 and prior */
        proc_source = DatumGetCString(DirectFunctionCall1(textout, procsrcdatum));
#endif
        elog(DEBUG3, "Function source: %s", proc_source);

        /* Done spelunking through the catalogs */

        /* Parse code */
        pllolcode_scanner_init(proc_source);
        parseres = pllolcode_yyparse(NULL);
        if (parseres != 0)
            elog(ERROR, "parser returned %d", parseres);
        program->parsetree = pllolcode_yylval.nodeList;
        pllolcode_scanner_finish();
        pfree(proc_source);
        if (program->parsetree == NULL)
            elog(ERROR, "program parse tree is null");

        /* Store code in hash table */
        lolHashTableStore(fcinfo, program);

        /* Get out of long-lived context */
        MemoryContextSwitchTo(orig_cxt);
    }
    ReleaseSysCache(procTup);
    return program;
}

Datum
pl_lolcode_call_handler(PG_FUNCTION_ARGS) {
    /* TODO: return error if you try to use this as a trigger, for now */
    lolProgram *program;
    Datum retval;

    returnVal = NULL;
    program = lolFindProgram(fcinfo);
    retval = lolRunProgram(fcinfo, program);
    return retval;
}

Datum
pl_lolcode_validator(PG_FUNCTION_ARGS) {
    /* This just tries to parse the source. There's probably more we really could check...
       Note that it also violates Don't Repeat Yourself, as it's largely copied from
       lolFindProgram */

    Oid procoid = PG_GETARG_OID(0);
    HeapTuple procTup;
    Form_pg_proc procStruct;
    Datum procsrcdatum;
    char *proc_source;
    bool isnull;
    int parseres;

    /* Must get the proc tuple, then proc source */
    /* Get procedure tuple */
    procTup = SearchSysCache(PROCOID, procoid, 0, 0, 0);
    if (!HeapTupleIsValid(procTup)) elog(ERROR, "Cache lookup failed for procedure %u", procoid);
    procStruct = (Form_pg_proc) GETSTRUCT(procTup);

    /* Get proc source */
    procsrcdatum = SysCacheGetAttr(PROCOID, procTup, Anum_pg_proc_prosrc, &isnull);
    if (isnull)
        elog(ERROR, "Function source is null");

#ifdef TextDatumGetCString
    proc_source = TextDatumGetCString(procsrcdatum);
#else
    /* For PostgreSQL versions 8.3 and prior */
    proc_source = DatumGetCString(DirectFunctionCall1(textout, procsrcdatum));
#endif
    elog(DEBUG3, "Function source: %s", proc_source);
    ReleaseSysCache(procTup);

    /* Done spelunking through the catalogs */

    /* Parse code */
    pllolcode_scanner_init(proc_source);
    parseres = pllolcode_yyparse(NULL);
    if (parseres != 0)
        elog(ERROR, "parser returned %d", parseres);
    pllolcode_scanner_finish();
    pfree(proc_source);
    PG_RETURN_VOID();
}

#if PG_VERSION_NUM >= 80500
Datum pl_lolcode_inline_handler(PG_FUNCTION_ARGS);
PG_FUNCTION_INFO_V1(pl_lolcode_inline_handler);

Datum
pl_lolcode_inline_handler(PG_FUNCTION_ARGS)
{
    int parseres;
    InlineCodeBlock *codeblock = (InlineCodeBlock *) DatumGetPointer(PG_GETARG_DATUM(0));
    FunctionCallInfoData fake_fcinfo;  /* Thanks, plpgsql */
    FmgrInfo flinfo;
    lolProgram program;
    Datum retval;

    elog(NOTICE, "Using PL/LOLCODE inline handler");

    MemSet(&fake_fcinfo, 0, sizeof(fake_fcinfo));                                                            
    MemSet(&flinfo, 0, sizeof(flinfo));                                                                      
    MemSet(&program, 0, sizeof(program));
    fake_fcinfo.flinfo = &flinfo;                                                                            
    flinfo.fn_oid = InvalidOid;                                                                              
    flinfo.fn_mcxt = CurrentMemoryContext; 
    program.returntype = VOIDOID;

    pllolcode_scanner_init(codeblock->source_text);
    parseres = pllolcode_yyparse(NULL);
    if (parseres != 0)
        elog(ERROR, "parser returned %d", parseres);
    program.parsetree = pllolcode_yylval.nodeList;
    pllolcode_scanner_finish();
    retval = lolRunProgram(&fake_fcinfo, &program);
    return retval;
}
#endif
