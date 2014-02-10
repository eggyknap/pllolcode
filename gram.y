%{

/*
 Parser for PL/LOLCODE
 $Id: gram.y,v 1.38 2009/05/04 15:52:24 eggyknap Exp $
*/

/* TODO: Make error messages return line number */
#define YYPARSE_PARAM result
#include "pllolcode.h"
#include <stdio.h>
#include <string.h>

int  pllolcode_yylex(void);
void pllolcode_yyerror(char *s);
int  pllolcode_yyparse(void *result);

lolNode *lolMakeNode(NodeType typ, NodeVal nodeVal, lolNodeList *list);
void printNodeList(lolNodeList *list);
void printNode(lolNode *cur);

NodeVal tmpnval;
lolNodeList *curList;
bool debugList = 0;
%}

/* BISON Declarations */ %name-prefix="pllolcode_yy"

%expect 30

%union  {
    int numbrVal;
    double numbarVal;
    char *yarnVal;
    struct lolNodeList *nodeList;
    struct lolNode *node;
}

%type <nodeList> lol_program lol_cmdblock lol_orly_block lol_wtf_block
%type <node> lol_const lol_var lol_cmd lol_xaryoprgroup lol_expression
%type <yarnVal> YARN
%type <yarnVal> IDENTIFIER
%type <numbrVal> NUMBR
%type <numbarVal> NUMBAR
%type <numbrVal> VISDEBUG VISLOG VISNOTICE VISINFO VISWARNING VISEXCEPTION lol_visibleLevel
%type <numbrVal> lol_binaryopr lol_unaryopr lol_xaryopr lol_typename

%token HAI KTHXBYE EXPREND
%token YARN IDENTIFIER NUMBR NUMBAR
%token TROOFWIN TROOFFAIL TROOF
%token VISIBLE VISDEBUG VISLOG VISNOTICE VISINFO VISWARNING VISEXCEPTION
%token FOUNDYR IHASA ITZ R
%token SUMOF DIFFOF PRODUKTOF QUOSHUNTOF MODOF BIGGROF SMALLROF AN
%token BOTHOF EITHEROF WONOF NOT ALLOF ANYOF SMOOSH MKAY
%token BOTHSAEM DIFFRINT
%token MAEK A TROOFTYPE NUMBRTYPE YARNTYPE NUMBARTYPE NOOBTYPE ISNOWA
%token GIMMEH OUTTADATABUKKIT
%token ORLY OIC YARLY NOWAI MEBBE
%token WTF OMG OMGWTF GTFO IMINYR IMOUTTAYR

/* Debugging tokens. These aren't part of the language, but I'm sticking 'em in to help me debug stuff */
%token YRVARZ

/* scan.l doesn't, at ths point, ever use these tokens, but we use them as types
 * of node in the parse "tree", so I'm declaring them here (instead of as separate
 * DEFINEs) so that their integer equivalents don't end up matching one of the other
 * tokens */
%token IDENT CMDBLOCK DECL MEBBEBLOCK

%%
lol_program:
    HAI EXPREND lol_cmdblock KTHXBYE EXPREND
                { yylval.nodeList = (lolNodeList *) $3; }
    ;

lol_cmdblock:
    lol_cmdblock lol_cmd    { $$ = lolListAppend($1, $2); }
    | lol_cmd         { $$ = lolMakeList($1); }
    ;

lol_cmd:
    lol_expression EXPREND    { $$ = $1; }
    | ORLY EXPREND lol_orly_block OIC EXPREND
                { $$ = lolMakeNode(ORLY, tmpnval, $3); }
    | WTF EXPREND lol_wtf_block OIC EXPREND
                { $$ = lolMakeNode(WTF, tmpnval, $3); }
    | IMINYR IDENTIFIER EXPREND lol_cmdblock IMOUTTAYR IDENTIFIER EXPREND
                { 
                    /* TODO: Check $2 and $7 for equality */
                    $$ = lolMakeNode(IMINYR, tmpnval, $4);
                }
    ;

lol_expression:
        /* TODO: From the spec: It has infinite arity and implicitly
         * concatenates all of its arguments after casting them to
         * YARNs. It is terminated by the statement delimiter (line end
         * or comma).  The output is automatically terminated with a
         * carriage return (:)), unless the final token is terminated
         * with an exclamation point (!), in which case the carriage
         * return is suppressed. */

    VISIBLE lol_visibleLevel lol_expression
                {
                    tmpnval.numbrVal = $2;
                    $$ = lolMakeNode(VISIBLE, tmpnval, lolMakeList($3));
                }
    | VISIBLE lol_expression
                { 
                    tmpnval.numbrVal = NOTICE;
                    $$ = lolMakeNode(VISIBLE, tmpnval, lolMakeList($2));
                }
    | FOUNDYR lol_expression    { $$ = lolMakeNode(FOUNDYR, tmpnval, lolMakeList($2)); }
    | IHASA lol_var ITZ lol_expression
                {
                    $$ = lolMakeNode(DECL, ($2)->nodeVal, lolMakeList($4));
                }
    | IHASA lol_var        { $$ = lolMakeNode(DECL, ($2)->nodeVal, NULL); }
    | lol_var R lol_expression
                { $$ = lolMakeNode(R, ($1)->nodeVal, lolMakeList($3)); }
        /* Note that MAEK syntax is MAEK lol_expression, not MAEK lol_var, because
           MAEK casts the value of an expression, and changes the type of IT */
    | MAEK lol_expression lol_typename
                {
                    tmpnval.numbrVal = $3;
                    $$ = lolMakeNode(MAEK, tmpnval, lolMakeList($2));
                }
    | MAEK lol_expression A lol_typename
                {
                    tmpnval.numbrVal = $4;
                    $$ = lolMakeNode(MAEK, tmpnval, lolMakeList($2));
                }
    | lol_var ISNOWA lol_typename
                {
                    tmpnval.numbrVal = $3;
                    $$ = lolMakeNode(ISNOWA, tmpnval, lolMakeList($1));
                }
    | GIMMEH YRVARZ        { $$ = lolMakeNode(YRVARZ, tmpnval, NULL); }
    | GIMMEH lol_var OUTTADATABUKKIT lol_expression
                {
                    $$ = lolMakeNode(OUTTADATABUKKIT, ($2)->nodeVal, lolMakeList($4));
                }
    | GIMMEH OUTTADATABUKKIT lol_expression
                {
                    tmpnval.yarnVal = pstrdup("IT");
                    $$ = lolMakeNode(OUTTADATABUKKIT, tmpnval, lolMakeList($3));
                }
    | GTFO            { $$ = lolMakeNode(GTFO, tmpnval, NULL); }
    | lol_xaryoprgroup MKAY    { $$ = $1; }
    | lol_binaryopr lol_expression AN lol_expression
                {
                    $$ = lolMakeNode($1, tmpnval, lolMakeTwoNodeList($2, $4));
                }
    | lol_binaryopr lol_expression lol_expression
                {
                    $$ = lolMakeNode($1, tmpnval, lolMakeTwoNodeList($2, $3));
                }
    | lol_unaryopr lol_expression    { $$ = lolMakeNode($1, tmpnval, lolMakeList($2)); }
    | lol_xaryoprgroup     { $$ = $1; }
    | lol_const        { $$ = $1; }
    | lol_var        { $$ = $1; }
    ;

lol_orly_block:
    YARLY EXPREND lol_cmdblock    { $$ = lolMakeList(lolMakeNode(YARLY, tmpnval, $3)); }
        /* Structure of a MEBBE node in the parse tree:
        *    The MEBBE node points to a two-node list. The first node is the parse tree of the MEBBE expression.
        *    The second node is a MEBBEBLOCK node, whose list points to the lol_cmdblock to be executed if the
        *    expression is true */
    | lol_orly_block MEBBE lol_expression EXPREND lol_cmdblock
                    { $$ = lolListAppend($1, lolMakeNode(MEBBE, tmpnval, lolMakeTwoNodeList($3, lolMakeNode(MEBBEBLOCK, tmpnval, $5)))); }
    | lol_orly_block NOWAI EXPREND lol_cmdblock
                    { $$ = lolListAppend($1, lolMakeNode(NOWAI, tmpnval, $4)); }
    ;

lol_wtf_block:
    OMG lol_const EXPREND lol_cmdblock
                {
                    ($2)->list = $4;
                    tmpnval.numbrVal = 0;
                    $$ = lolMakeList(lolMakeNode(OMG, tmpnval, lolMakeList($2)));
                }
                /*
    | OMG lol_const EXPREND lol_cmdblock GTFO EXPREND
                {
                    ($2)->list = $4;
                    tmpnval.numbrVal = 1;
                    $$ = lolMakeList(lolMakeNode(OMG, tmpnval, lolMakeList($2)));
                } */
    | lol_wtf_block OMG lol_const EXPREND lol_cmdblock
                {
                    ($3)->list = $5;
                    tmpnval.numbrVal = 0;
                    $$ = lolListAppend($1, lolMakeNode(OMG, tmpnval, lolMakeList($3)));
                }
                /* 
    | lol_wtf_block OMG lol_const EXPREND lol_cmdblock GTFO EXPREND
                {
                    ($3)->list = $5;
                    tmpnval.numbrVal = 1;
                    $$ = lolListAppend($1, lolMakeNode(OMG, tmpnval, lolMakeList($3)));
                }
                */
    | lol_wtf_block OMGWTF EXPREND lol_cmdblock
                { $$ = lolListAppend($1, lolMakeNode(OMGWTF, tmpnval, $4)); }
    ;

lol_typename:
    TROOFTYPE        { $$ = ident_TROOF; }
    | NUMBRTYPE        { $$ = ident_NUMBR; }
    | NUMBARTYPE        { $$ = ident_NUMBAR; }
    | YARNTYPE        { $$ = ident_YARN; }
    | NOOBTYPE        { $$ = ident_NOOB; }
    ;

lol_var:
    IDENTIFIER        {
                    tmpnval.yarnVal = pstrdup(pllolcode_yytext);
                    $$ = lolMakeNode(IDENT, tmpnval, NULL);
                }
    ;

    /* Most notations refer to these operators as n-ary. Calling the
     * related functions naryOpr* makes them 
     * too close in name to binaryOpr* and especially unaryOpr* for my
     * liking -- too easy to confuse them that way. So I'm calling these
     * operators x-ary operators */

lol_xaryoprgroup:
    lol_xaryopr lol_expression
                { $$ = lolMakeNode($1, tmpnval, lolMakeList($2)); }
    | lol_xaryoprgroup lol_expression    { lolListAppend(($1)->list, $2); $$ = $1; }
    | lol_xaryoprgroup AN lol_expression    { lolListAppend(($1)->list, $3); $$ = $1; }
    ;

lol_xaryopr:
    ALLOF        { $$ = ALLOF; }
    | ANYOF        { $$ = ANYOF; }
    | SMOOSH       { $$ = SMOOSH; }
    ;

lol_unaryopr:
    NOT        { $$ = NOT; }
    ;

lol_binaryopr:
    SUMOF        { $$ = SUMOF; }
    | DIFFOF    { $$ = DIFFOF; }
    | PRODUKTOF    { $$ = PRODUKTOF; }
    | QUOSHUNTOF    { $$ = QUOSHUNTOF; }
    | MODOF        { $$ = MODOF; }
    | BIGGROF    { $$ = BIGGROF; }
    | SMALLROF    { $$ = SMALLROF; }
    | BOTHOF    { $$ = BOTHOF; }
    | EITHEROF    { $$ = EITHEROF; }
    | WONOF        { $$ = WONOF; }
    | BOTHSAEM    { $$ = BOTHSAEM; }
    | DIFFRINT    { $$ = DIFFRINT; }
    ;

lol_const:
    YARN            {
                    tmpnval.yarnVal = pstrdup($1);
                    $$ = lolMakeNode(YARN, tmpnval, NULL);
                }
    | NUMBAR        { tmpnval.numbarVal = $1; $$ = lolMakeNode(NUMBAR, tmpnval, NULL); }
    | NUMBR            { tmpnval.numbrVal = $1; $$ = lolMakeNode(NUMBR, tmpnval, NULL); }
    | TROOFWIN        { tmpnval.numbrVal = 1; $$ = lolMakeNode(TROOF, tmpnval, NULL); }
    | TROOFFAIL        { tmpnval.numbrVal = 0; $$ = lolMakeNode(TROOF, tmpnval, NULL); }
    ;

lol_visibleLevel:
    VISDEBUG        { $$ = DEBUG1; }
    | VISLOG        { $$ = LOG; }
    | VISNOTICE        { $$ = NOTICE; }
    | VISINFO        { $$ = INFO; }
    | VISWARNING        { $$ = WARNING; }
    | VISEXCEPTION        { $$ = ERROR; }
    ;
%%

void
pllolcode_yyerror(char *s)
{
    elog(ERROR, "Error %s at line number %d", s, lineNumber);
}

/*extern int pllolcode_yy_flex_debug; */

lolNodeList *
lolMakeTwoNodeList(lolNode *node1, lolNode *node2)
{
    lolNodeList *list = lolMakeList(node1);
    return lolListAppend(list, node2);
}

lolNodeList *
lolListAppend(lolNodeList *list, lolNode *node)
{
    if (list == NULL) { elog(DEBUG1, "list is null in lolListAppend"); return NULL; }
    if (node == NULL) { elog(DEBUG1, "node is null in lolListAppend"); return NULL; }
    node->next = NULL;
    if (list->tail == NULL) {
        list->head = node;
        list->tail = node;
        list->length = 1;
        return list;
    }
    list->tail->next = node;
    list->tail = node;
    list->length++;
    if (debugList) printNodeList(list);
    return list;
}

lolNodeList *
lolMakeList(lolNode *node)
{
    lolNodeList *list;
    
    list = palloc(sizeof(lolNodeList));
    list->head = node;
    list->tail = node;
    list->length = 1;
    if (debugList) printNodeList(list);
    return list;    
} 
lolNode *
lolMakeNode(NodeType typ, NodeVal nodeVal, lolNodeList *list)
{
    lolNode *node;

    node = palloc(sizeof(lolNode));
    node->node_type = typ;
    node->nodeVal = nodeVal;
    node->list = list;
    node->next = NULL;
    return node;
}
void
printNode(lolNode *cur)
{
    char tmpString[255];

    if (cur == NULL) {
        elog(INFO, "NULL node");
        return;
    }
    switch (cur->node_type) {
        case CMDBLOCK:
            elog(INFO, "CMDBLOCK");
            printNodeList(cur->list);
            break;
        case VISIBLE:
            elog(INFO, "VISIBLE");
            printNodeList(cur->list);
            break;
        case YARN:
            elog(INFO, "YARN");
            snprintf(tmpString, 255, "value: %s", cur->nodeVal.yarnVal);
            elog(INFO, "%s", tmpString);
            break;
        case NUMBR:
            elog(INFO, "NUMBR");
            snprintf(tmpString, 255, "value: %d", cur->nodeVal.numbrVal);
            elog(INFO, "%s", tmpString);
            break;
        case NUMBAR:
            elog(INFO, "NUMBAR");
            snprintf(tmpString, 255, "value: %f", cur->nodeVal.numbarVal);
            elog(INFO, "%s", tmpString);
            break;
        case FOUNDYR:
            elog(INFO, "FOUNDYR");
            printNodeList(cur->list);
            break;
        case IDENT:
            elog(INFO, "IDENT: name = %s", cur->nodeVal.yarnVal);
            break;    
        case ORLY:
            elog(INFO, "ORLY");
            printNodeList(cur->list);
            break;
        case YARLY:
            elog(INFO, "YA RLY");
            printNodeList(cur->list);
            break;
        case MEBBE:
            elog(INFO, "MEBBE");
            printNodeList(cur->list);
            break;
        case MEBBEBLOCK:
            elog(INFO, "MEBBEBLOCK");
            printNodeList(cur->list);
            break;
        case NOWAI:
            elog(INFO, "NOWAI");
            printNodeList(cur->list);
            break;
        case BOTHSAEM:
            elog(INFO, "BOTH SAEM");
            break;
        case WTF:
            elog(INFO, "WTF");
            printNodeList(cur->list);
            break;
        case OMG:
            elog(INFO, "OMG");
            if (cur->nodeVal.numbrVal) elog(INFO, "  This OMG node has a GTFO");
            printNode(cur->list->head);
            if (cur->list != NULL && cur->list->head != NULL)
                printNodeList(cur->list->head->list);
            else elog(INFO, "ERROR: Badly constructed OMG node");
            break;
        case OMGWTF:
            elog(INFO, "OMGWTF");
            printNodeList(cur->list);
            break;
        default:
            elog(INFO, "Unknown node type %d", cur->node_type);
    }
}

void
printNodeList(lolNodeList *list)
{
    lolNode *cur;

    elog(INFO, "Start of list");
    if (list == NULL) 
    {
        elog(INFO, "NULL node list");
        return;
    }
    cur = list->head;
    if (cur == NULL) {
        elog(INFO, "NULL first node");
        return;
    }
    while (cur->next != NULL) {
        elog(INFO, "List Node");
        printNode(cur);
        cur = cur->next;
    }
    printNode(cur);
    elog(INFO, "End of list");
}
