/*
 * $Id: pllolcode.h,v 1.26 2009/05/04 15:52:24 eggyknap Exp $
 */

#ifndef PLLOLCODE_H
#define PLLOLCODE_H
#include "postgres.h"
#include "fmgr.h"


#define NUMBR2YARN(orig, res, reslen)    snprintf(res, reslen, "%d", orig)
#define NUMBAR2YARN(orig, res, reslen)    snprintf(res, reslen, "%f", orig)
#define TROOF2YARN(orig, res, reslen)    ((orig != 0) ? snprintf(res, reslen, "WIN") : snprintf(res, reslen, "FAIL"))

#define NUMBAR2NUMBR(val)    ((int) val)
#define TROOF2NUMBR(val)    ((val != 0) ? 1 : 0)
#define YARN2NUMBR(val)        ((int) strtol(val, NULL, 10))

#define NUMBR2NUMBAR(val)    ((double) val)
#define TROOF2NUMBAR(val)    ((val != 0) ? 1.0 : 0.0)
#define YARN2NUMBAR(val)    (strtod(val, NULL))

#define NUMBAR2TROOF(val)    ((val != 0) ? lolWIN : lolFAIL)
/* TODO: Error checking */
#define YARN2TROOF(val)        ((strlen(val) > 0) ? lolWIN : lolFAIL)
#define N00B2TROOF        (lolFAIL)

extern void pllolcode_scanner_init(const char *);
extern void pllolcode_scanner_finish(void);
extern void _PG_init(void);

typedef int NodeType;

typedef union {
        int numbrVal;
        double numbarVal;
        char *yarnVal;
    } NodeVal;

typedef struct lolNode lolNode;

typedef struct lolNodeList {
    int length;
    lolNode *head;
    lolNode *tail;
} lolNodeList;    

extern void executeProgram(lolNodeList *prg);

struct lolNode {
    NodeType node_type;
    struct lolNode *next;
    /* list for sub-nodes */
    lolNodeList *list;
    NodeVal nodeVal;
};

typedef struct lol_program {
    lolNodeList *parsetree;
    char **argnames;
    char *argmodes;
    Oid *argtypes;
    int numargs;
    Oid returntype;
    Oid returnTypeIOParam;
    FmgrInfo ret_flinfo;
} lolProgram;

/* Hash table stuff */

typedef struct pl_lolcode_hashkey {
    Oid funcoid;
    bool isTrigger;
    Oid trigrelOid;
    Oid argtypes[FUNC_MAX_ARGS];
} pl_lolcode_HashKey;

typedef struct pl_lolcode_hashent {
    pl_lolcode_HashKey key;
    lolProgram *program;
    /* TODO: add function argument types, etc. here */
} pl_lolcode_HashEnt;

/* Symbol table related stuff */

typedef enum { ident_YARN, ident_NUMBR, ident_NUMBAR, ident_TROOF, ident_NOOB } IdentType;

typedef struct lolIdent {
    char *name;
    IdentType type;
    NodeVal value;
} lolIdent;

typedef enum { lolFAIL, lolWIN } lolTroof;

extern lolIdent *returnVal;
extern int lineNumber;

extern void lolSetVar(char *name, IdentType type, NodeVal value);
extern lolIdent *lolGetVar(char *name);
extern void lolDeclareVar(char *name);
extern void lolInitVars(void);
extern char *lolVarGetString(lolIdent *var, bool expl);
extern double lolVarGetNumbar(lolIdent *var, bool expl);
extern int lolVarGetNumbr(lolIdent *var, bool expl);
extern lolTroof lolVarGetTroof(lolIdent *var);
extern bool lolVarGetBool(lolIdent *var);

extern lolIdent *IT;

/* extern char *scanbuf; */
char stringbuf[255];
extern char *pllolcode_yytext;

extern lolNodeList *lolListAppend(lolNodeList *list, lolNode *node);
extern lolNodeList *lolMakeList(lolNode *node);
extern lolNodeList *lolMakeTwoNodeList(lolNode *node1, lolNode *node2);
extern void printSymbolTable(void);

extern void LOLifyDatum(Datum val, bool isnull, Oid typeoid, char *lolVarName);
extern void LOLifyString(char *str, Oid typeoid, char *lolVarName);

extern int   pllolcode_yylex_destroy(void);

/* Executor stuff */
extern void executeProgram(lolNodeList *prg);
extern void printNode(lolNode *);
#endif
