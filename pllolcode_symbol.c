/*
 * PL/LOLCODE Symbol table functions
 * $Id: pllolcode_symbol.c,v 1.15 2009/05/03 04:35:21 eggyknap Exp $
 */

#include "pllolcode.h"
#include "postgres.h"
#include "executor/spi.h"
#include "commands/trigger.h"
#include "fmgr.h"
#include "access/heapam.h"
#include "utils/syscache.h"
#include "catalog/pg_proc.h"
#include "catalog/pg_type.h"
#include "utils/lsyscache.h"
#include "utils/memutils.h"
#include "utils/builtins.h"
#include "pllolcode_lang.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOL_MAX_VARS 255

lolIdent *IT;
/* TODO : Change this to some other implementation without a limited number of variables */
lolIdent lolVars[LOL_MAX_VARS];
int lolVarCount;

void
printSymbolTable(void)
{
    int i;
    elog(INFO, "Count; %d", lolVarCount);
    for (i = 0; i < lolVarCount; i++)
    {
        elog(INFO, "Name: %s", lolVars[i].name);
        switch (lolVars[i].type) {
            case ident_YARN:
                elog(INFO, "Yarn, value %s", lolVars[i].value.yarnVal);
                break;
            case ident_NUMBR:
                elog(INFO, "Numbr, value %d", lolVars[i].value.numbrVal);
                break;
            case ident_NUMBAR:
                elog(INFO, "Numbar value %f", lolVars[i].value.numbarVal);
                break;
            case ident_TROOF:
                elog(INFO, "Troof, value %s", (lolVars[i].value.numbrVal == 1) ? "WIN" : "FAIL");
                break;
            case ident_NOOB:
                elog(INFO, "NOOB value");
                break;
            default:
                elog(INFO, "Unknown type %d", lolVars[i].type);
        }
    }
}

void
lolInitVars()
{
    NodeVal val;

    val.numbrVal = 0;
    IT = &(lolVars[0]);
    IT->name = pstrdup("IT");
    IT->type = ident_NUMBR;
    IT->value = val;
    lolVarCount = 1;

/*    printSymbolTable(); */
}

/* TODO: Make lolGetVar() and lolSetVar() use the same code to scan the variable list */
lolIdent *
lolGetVar(char *name)
{
    int i;

    if (name == NULL) return NULL;
    for (i = 0; i < lolVarCount; i++)
    {
        if (strncmp(name, lolVars[i].name, 255) == 0)
            return &(lolVars[i]);
    }
    return NULL;
}

void
lolSetVar(char *name, IdentType type, NodeVal value)
{
    int i;

    for(i = 0; i < lolVarCount; i++)
    {
        if (strncmp(name, lolVars[i].name, 255) == 0)
            break;
    }
    if (i >= lolVarCount)
        elog(INFO, "Tried to set PL/LOLCODE variable %s without declaring it first", name);
    if (lolVars[i].type == ident_YARN && lolVars[i].value.yarnVal != NULL)
        pfree(lolVars[i].value.yarnVal);
    lolVars[i].type = type;
    lolVars[i].value = value;
    elog(DEBUG3, "Just set %s", name);
    /*printSymbolTable(); */
}

void
lolDeclareVar(char *name)
{
    if (lolVarCount >= LOL_MAX_VARS)
        elog(ERROR, "Too many variables required for LOLCODE function");
    lolVarCount++;
    elog(DEBUG3, "Declaring %s as variable # %d", name, lolVarCount);
    lolVars[lolVarCount-1].name = pstrdup(name);
    lolVars[lolVarCount-1].type = ident_NOOB;
    /* printSymbolTable(); */
}

/* Handle string type casting */
/* The _expl_ argument describes whether or not this cast was called
 * explicitly. NOOB values cannot be implicitly cast to anything but TROOF
 * values, so we need to know if this cast was explicit */
char *
lolVarGetString(lolIdent *var, bool expl)
{
    char *tmpString;

    /* TODO: Handle strings of more than 255 chars */
    tmpString = palloc(255);
    memset(tmpString, 0, 255);

    if (var == NULL) return NULL;
    switch (var->type) {
        case ident_YARN:
            return var->value.yarnVal;
        case ident_NUMBR:
            NUMBR2YARN(var->value.numbrVal, tmpString, 255);
            return tmpString;
        case ident_NUMBAR:
            NUMBAR2YARN(var->value.numbarVal, tmpString, 255);
            return tmpString;
        case ident_TROOF:
            TROOF2YARN(var->value.numbrVal, tmpString, 255);
            return tmpString;
        case ident_NOOB:
            if (expl) return tmpString;
            else elog(WARNING, "PL/LOLCODE: Cannot implicitly cast NOOB value to YARN in variable %s", var->name);
    }
    return NULL;
}

/* TODO: Error checking */
/* Type cast to NUMBR */
int
lolVarGetNumbr(lolIdent *var, bool expl) {
    if (var == NULL) return 0;
    switch (var->type) {
        case ident_NUMBR:
            return var->value.numbrVal;
        case ident_NUMBAR:
            return NUMBAR2NUMBR(var->value.numbarVal);
        case ident_TROOF:
            return TROOF2NUMBR(var->value.numbrVal);
        case ident_YARN:
            return YARN2NUMBR(var->value.yarnVal);
        case ident_NOOB:
            if (expl) return 0;
            else elog(WARNING, "PL/LOLCODE: Cannot implicitly cast NOOB value to NUMBR in variable %s", var->name);
    }
    return 0;
}

/* Type cast to NUMBAR */
double
lolVarGetNumbar(lolIdent *var, bool expl) {
    if (var == NULL) return 0;
    switch (var->type) {
        case ident_NUMBAR:
            return var->value.numbarVal;
        case ident_NUMBR:
            return NUMBR2NUMBAR(var->value.numbrVal);
        case ident_TROOF:
            return TROOF2NUMBAR(var->value.numbrVal);
        case ident_YARN:
            return YARN2NUMBAR(var->value.yarnVal);
        case ident_NOOB:
            if (expl) return 0.0;
            else elog(WARNING, "PL/LOLCODE: Cannot implicitly cast NOOB value to NUMBAR in variable %s", var->name);
            
    }
    return 0.0;
}

/* Type cast to TROOF */
/* Note that this function does *not* take an argument called "expl" like
 * the other lolVarGet_type_ functions. This is because NOOBs *can* be
 * implicitly cast to TROOF */
lolTroof
lolVarGetTroof(lolIdent *var) {
    if (var == NULL) return lolFAIL;
    switch (var->type) {
        case ident_TROOF:
        case ident_NUMBR:
            return (var->value.numbrVal != 0) ? lolWIN : lolFAIL;
        case ident_NUMBAR:
            return NUMBAR2TROOF(var->value.numbarVal);
            /* return (var->value.numbarVal != 0) ? lolWIN : lolFAIL; */
        case ident_YARN:
            return YARN2TROOF(var->value.yarnVal);
            /* return (strlen(var->value.yarnVal) > 0) ? lolWIN : lolFAIL; */
        case ident_NOOB:
            return lolFAIL;
    }
    return lolFAIL;
}

/* Type cast to TROOF, convert to standard bool */
/* TODO : Convert to macro */
bool
lolVarGetBool(lolIdent *var) {
    return lolVarGetTroof(var) == lolWIN ? true : false;
}

void
LOLifyString(char *str, Oid typeoid, char *lolVarName)
{
    NodeVal nodeVal;
    if (str == NULL) {
        nodeVal.numbrVal = 0;
        lolSetVar(lolVarName, ident_NOOB, nodeVal);
    }
    else {
        /* Note: because the OutputFunctionCall gives me the
         * data as a string, and because most casts happen
         * implicitly so this shouldn't really bother anyone,
         * I'm keeping the input data as a string. For now. */

        SPI_push();
        nodeVal.yarnVal = str;
        SPI_pop();
        switch (typeoid) {
            case BOOLOID:
                if (nodeVal.yarnVal[0] == 't')
                    nodeVal.numbrVal = 1;
                else
                    nodeVal.numbrVal = 0;
                    lolSetVar(lolVarName, ident_TROOF, nodeVal);        
                break;
            case INT2OID:
            case INT4OID:
            case INT8OID:
                nodeVal.numbrVal = YARN2NUMBR(nodeVal.yarnVal);
                lolSetVar(lolVarName, ident_NUMBR, nodeVal);
                break;
            case FLOAT4OID:
            case FLOAT8OID:
            case NUMERICOID:
                nodeVal.numbarVal = YARN2NUMBAR(nodeVal.yarnVal);
                lolSetVar(lolVarName, ident_NUMBAR, nodeVal);
                break;
            default:
                lolSetVar(lolVarName, ident_YARN, nodeVal);
        }
    }
}

void
LOLifyDatum(Datum val, bool isnull, Oid typeoid, char *lolVarName)
{
    HeapTuple typeTup;
    FmgrInfo tmp_flinfo;
    Form_pg_type typeStruct;
    NodeVal nodeVal;
    char *str;
    
    typeTup = SearchSysCache(TYPEOID, ObjectIdGetDatum(typeoid), 0, 0, 0);
    if (!HeapTupleIsValid(typeTup))
        elog(ERROR,"Cache lookup failed for type %u", typeoid);
    typeStruct = (Form_pg_type) GETSTRUCT(typeTup);
    /* TODO: improve support for non-basic types */
    if (typeStruct->typtype != 'b') 
        elog(ERROR, "Cannot support pseudo-types, domain types, or composite types as function arguments, specifically %s", 
            format_type_be(typeoid));
    fmgr_info_cxt(typeStruct->typoutput, &tmp_flinfo, CurTransactionContext);    
    ReleaseSysCache(typeTup);

    lolDeclareVar(lolVarName);
    if (isnull) {
        /* Initialize this to something */
        nodeVal.numbrVal = 0;
        lolSetVar(lolVarName, ident_NOOB, nodeVal);
    }
    else {
        /* Note: because the OutputFunctionCall gives me the
         * data as a string, and because most casts happen
         * implicitly so this shouldn't really bother anyone,
         * I'm keeping the input data as a string. For now. */

        SPI_push();
        str = OutputFunctionCall(&tmp_flinfo, val);
        SPI_pop();
        LOLifyString(str, typeoid, lolVarName);
    }
}
