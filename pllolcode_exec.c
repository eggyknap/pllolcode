/*
 * $Id: pllolcode_exec.c,v 1.1 2009/05/04 15:04:55 eggyknap Exp $
 */

#include "pllolcode.h"
#include "pllolcode_lang.h"
#include "executor/spi.h"

bool executeList(lolNodeList *list);
bool executeNode(lolNode *node);
void yarnNode(lolNode *node);
void numbrNode(lolNode *node);
void numbarNode(lolNode *node);
void troofNode(lolNode *node);
void visibleNode(lolNode *node);
void foundyrNode(lolNode *node);
void identNode(lolNode *node);
void declareNode(lolNode *node);
lolIdent arithNode(lolNode *node, lolIdent a, lolIdent b);
lolIdent boolNode(lolNode *node, lolIdent a, lolIdent b);
lolIdent comparisonNode(lolNode *node, lolIdent a, lolIdent b);
void binaryOprNode(lolNode *node);
void assignNode(lolNode *node);
void unaryOprNode(lolNode *node);
void smooshNode(lolNode *node);
void allOfNode(lolNode *node);
void anyOfNode(lolNode *node);
void castNode(lolNode *node);
bool orlyNode(lolNode *node);
void wtfNode(lolNode *node);
void iminyrNode(lolNode *node);
void SPInode(lolNode *node);

void
executeProgram(lolNodeList *prg)
{
    elog(DEBUG3, "Executing program");
    if (prg == NULL)  {
        elog(INFO, "NULL parse tree");
        return;
    }
    executeList(prg);
}

void
visibleNode(lolNode *node)
{
    /* TODO: Try printing a NOOB, and seeing what happens. Might crash the server */
    executeList(node->list);
    elog(node->nodeVal.numbrVal, "%s", lolVarGetString(lolGetVar("IT"), false));
}

void
foundyrNode(lolNode *node)
{
    executeList(node->list);
    returnVal = lolGetVar("IT");
}

void
yarnNode(lolNode *node)
{
    lolSetVar("IT", ident_YARN, node->nodeVal);
}

void
numbrNode(lolNode *node) 
{
    lolSetVar("IT", ident_NUMBR, node->nodeVal);
}

void
numbarNode(lolNode *node)
{
    lolSetVar("IT", ident_NUMBAR, node->nodeVal);
}

void
troofNode(lolNode *node)
{
    lolSetVar("IT", ident_TROOF, node->nodeVal);
}

void
identNode(lolNode *node)
{
    lolIdent *cur;
    NodeVal val;

    cur = lolGetVar(node->nodeVal.yarnVal);
    if (cur != NULL)
        lolSetVar("IT", cur->type, cur->value);
    else 
    {
        val.numbrVal = 0;
        lolSetVar("IT", ident_NUMBR, val);
    }
}

lolIdent
arithNode(lolNode *node, lolIdent a, lolIdent b)
{
    lolIdent result;
    double x, y, answer;

    result.type = ident_NUMBAR;

    /* Arithmetic with NULL values leaves non-null value unchanged */
    if (a.type == ident_NOOB) 
        return b;
    if (b.type == ident_NOOB) 
        return a;

    if (a.type == ident_NUMBR && b.type == ident_NUMBR)
        result.type = ident_NUMBR;

    x = lolVarGetNumbar(&a, false);
    y = lolVarGetNumbar(&b, false);

    switch (node->node_type) {
        case SUMOF:
            answer = x + y;
            break;
        case DIFFOF:
            answer = x - y;
            break;
        case PRODUKTOF:
            answer = x * y;
            break;
        case QUOSHUNTOF:
            if (y == 0) 
                elog(ERROR, "Division by zero");
            answer = x / y;
            break;
        case MODOF:
            if (result.type != ident_NUMBR)
                elog(DEBUG1, "Casting to integers for modulo operation");
            answer = (int) x % (int) y;
            break;
        case BIGGROF:
            answer = (x > y) ? x : y;
            break;
        case SMALLROF:
            answer = (x < y) ? x : y;
            break;
        default:
            result.type = ident_NOOB;
            answer = 0;
            elog(DEBUG1, "Strange node type passed to arithNode");
    }
    if (result.type == ident_NUMBR) 
        result.value.numbrVal = (int) answer;
    else 
        result.value.numbarVal = answer;
    return result;
}

lolIdent
boolNode(lolNode *node, lolIdent a, lolIdent b)
{
    bool x, y;
    lolIdent result;

    x = lolVarGetBool(&a);
    y = lolVarGetBool(&b);
    result.type = ident_TROOF;
    switch (node->node_type) {
        case BOTHOF:
            result.value.numbrVal = x && y;
            break;
        case EITHEROF:
            result.value.numbrVal = x || y;
            break;
        case WONOF:
            result.value.numbrVal = (x && !y) || (y && !x);
            break;
    }
    return result;
}

lolIdent
comparisonNode(lolNode *node, lolIdent a, lolIdent b)
{
    lolIdent result;
    double x, y;

    result.type = ident_TROOF;
    result.value.numbrVal = 0;
    if (a.type != b.type) {
        if ((a.type == ident_NUMBR && b.type == ident_NUMBAR) || 
            (a.type == ident_NUMBAR && b.type == ident_NUMBR)) {
            if (a.type == ident_NUMBR)
                x = NUMBR2NUMBAR(a.value.numbrVal);
            else x = a.value.numbarVal;
            if (b.type == ident_NUMBR)
                y = NUMBR2NUMBAR(b.value.numbrVal);
            else y = b.value.numbarVal;
            result.value.numbrVal = ( x == y ) ? 1 : 0;
        }
    }
    else switch (a.type) {
        case ident_TROOF:
            if ((a.value.numbrVal > 0 && b.value.numbrVal > 0) || (a.value.numbrVal == 0 && b.value.numbrVal == 0))
                result.value.numbrVal = 1;
            break;
        case ident_NUMBR:
            if (a.value.numbrVal == b.value.numbrVal)
                result.value.numbrVal = 1;
            break;
        case ident_NOOB:
            break;
        case ident_NUMBAR:
            if (a.value.numbarVal == b.value.numbarVal)
                result.value.numbrVal = 1;
            break;
        case ident_YARN:
            result.value.numbrVal = (strcmp(b.value.yarnVal, a.value.yarnVal) == 0 ? 1 : 0);
            break;
    }
    if (node->node_type == DIFFRINT)
        result.value.numbrVal = (result.value.numbrVal == 1) ? 0 : 1;
    return result;
}

void
assignNode(lolNode *node)
{
    /* Variable name is in node->nodeVal.yarnVal, and value is in the list */
    lolIdent *IT;

    executeNode(node->list->head);
    IT = lolGetVar("IT");
    lolSetVar(node->nodeVal.yarnVal, IT->type, IT->value);
}

void
binaryOprNode(lolNode *node)
{
    lolNode *cur;
    lolIdent a, b;
    lolIdent *pIT;

    /* Assume we've got a list of two nodes. Execute each node in turn, and
       retrieve the results in a and b */
    if (node->list == NULL) return;
    cur = node->list->head;
    executeNode(cur);
    pIT = lolGetVar("IT");
    a.type = pIT->type;
    a.value = pIT->value;
    cur = cur->next;
    if (cur == NULL) return;
    executeNode(cur);
    pIT = lolGetVar("IT");
    b.type = pIT->type;
    b.value = pIT->value;

    switch (node->node_type) {
        case SUMOF:
        case DIFFOF:
        case PRODUKTOF:
        case QUOSHUNTOF:
        case MODOF:
        case BIGGROF:
        case SMALLROF:
            a = arithNode(node, a, b);
            break;
        case BOTHOF:
        case EITHEROF:
        case WONOF:
            a = boolNode(node, a, b);
            break;
        case BOTHSAEM:
        case DIFFRINT:
            a = comparisonNode(node, a, b);
            break;
        default:
            return;
    }
    lolSetVar("IT", a.type, a.value);
}

void
unaryOprNode(lolNode *node)
{
    /* So far, NOT is the only unary operator I know of. So I'm making this very NOT-specific */
    NodeVal tmpVal;

    executeList(node->list);
    tmpVal.numbrVal = lolVarGetBool(lolGetVar("IT")) ? 0 : 1;
    lolSetVar("IT", ident_TROOF, tmpVal);
}

void
smooshNode(lolNode *node)
{
    lolNode *cur;
    NodeVal tmpVal;
    char *result = palloc(255);
    int len = 0;

    memset(result, 0, 255 * sizeof(char));
    if (node->list == NULL) return;
    cur = node->list->head;
    while (cur != NULL) {
        executeNode(cur);
        strncat(result, lolVarGetString(lolGetVar("IT"), false), 254 - len);
        len = strnlen(result, 254);
    }
    tmpVal.yarnVal = result;
    lolSetVar("IT", ident_YARN, tmpVal);
}

void
allOfNode(lolNode *node)
{
    lolNode *cur;
    NodeVal tmpVal;

    if (node->list == NULL) return;
    cur = node->list->head;
    while (cur != NULL) {
        executeNode(cur);
        if (!lolVarGetBool(lolGetVar("IT"))) {
            tmpVal.numbrVal = 0;
            lolSetVar("IT", ident_TROOF, tmpVal);
            return;
        }
        cur = cur->next;
    }
    tmpVal.numbrVal = 1;
    lolSetVar("IT", ident_TROOF, tmpVal);
}

void
anyOfNode(lolNode *node)
{
    lolNode *cur;
    NodeVal tmpVal;

    if (node->list == NULL) return;
    cur = node->list->head;
    while (cur != NULL) {
        executeNode(cur);
        if (lolVarGetBool(lolGetVar("IT"))) {
            tmpVal.numbrVal = 1;
            lolSetVar("IT", ident_TROOF, tmpVal);
            return;
        }
        cur = cur->next;
    }
    tmpVal.numbrVal = 0;
    lolSetVar("IT", ident_TROOF, tmpVal);
}

void
castNode(lolNode *node)
{
    lolIdent *var;
    NodeVal nodeVal;
    char tmpString[255];
    NodeType newType;

    /* The list one node, containing a variable name; this node's
     * nodeVal.numbrVal is the type the variable is supposed to be cast to.
     * The node can be a MAEK node, in which case the result gets stuck in
     * IT, or a ISNOWA node, which means the variable itself will be
     * modified.  Note that an ISNOWA node will also modify IT. */

    if (node->list == NULL || node->list->head == NULL) {
        elog(DEBUG1, "PL/LOLCODE: Empty node list in cast operation");
        return;
    }
    var = lolGetVar(node->list->head->nodeVal.yarnVal);
    newType = node->nodeVal.numbrVal;
    if (var->type == newType) {
        elog(DEBUG3, "PL/LOLCODE: Casting to same type");
        return;
    }

    switch (newType) {
        case ident_YARN:
            switch (var->type) {
                case ident_NUMBR:
                    NUMBR2YARN(var->value.numbrVal, tmpString, 255);
                    nodeVal.yarnVal = pstrdup(tmpString);
                    break;
                case ident_NUMBAR:
                    NUMBAR2YARN(var->value.numbarVal, tmpString, 255);    
                    nodeVal.yarnVal = pstrdup(tmpString);
                    break;
                case ident_TROOF:
                    if (nodeVal.numbrVal)
                        nodeVal.yarnVal = pstrdup("WIN");
                    else
                        nodeVal.yarnVal = pstrdup("FAIL");
                    break;
                case ident_NOOB:
                    nodeVal.yarnVal = pstrdup("");
                    break;
                default:
                    break;
            }
            break;
        case ident_NUMBR:
            switch (var->type) {
                case ident_NUMBAR:
                    nodeVal.numbrVal = NUMBAR2NUMBR(var->value.numbarVal);
                    break;
                case ident_YARN:
                    nodeVal.numbrVal = YARN2NUMBR(var->value.yarnVal);
                    break;
                case ident_TROOF:
                    nodeVal.numbrVal = var->value.numbrVal;
                    break;
                case ident_NOOB:
                    nodeVal.numbrVal = 0;
                    break;
                default:
                    break;
            }
            break;
        case ident_NUMBAR:
            switch (var->type) {
                case ident_NUMBR:
                    nodeVal.numbarVal = NUMBR2NUMBAR(var->value.numbrVal);
                    break;
                case ident_YARN:
                    nodeVal.numbarVal = YARN2NUMBAR(var->value.yarnVal);
                    break;
                case ident_TROOF:
                    nodeVal.numbarVal = (double) var->value.numbrVal;
                    break;
                case ident_NOOB:
                    nodeVal.numbarVal = 0;
                    break;
                default:
                    break;
            }
            break;
        case ident_TROOF:
            switch (var->type) {
                case ident_NUMBR:
                    nodeVal.numbrVal = (var->value.numbrVal != 0) ? 1 : 0;
                    break;
                case ident_NUMBAR:
                    nodeVal.numbrVal = (var->value.numbarVal != 0) ? 1 : 0;
                    break;
                case ident_YARN:
                    nodeVal.numbrVal = (strlen(var->value.yarnVal) > 0) ? 1 : 0;
                    break;
                case ident_NOOB:
                    nodeVal.numbrVal = 0;
                    break;
                default:
                    break;
            }
            break;
        case ident_NOOB:
            nodeVal.numbrVal = 0;
            break;
        default:
            break;
    }
    lolSetVar("IT", newType, nodeVal);

    if (node->node_type == ISNOWA) 
    {
        var->type = newType;
        var->value = nodeVal;
    }
}

bool
orlyNode(lolNode *node)
{
    lolNode *cur;
    bool blockDone = 0;
    bool gtfo = false;

    if (node->list == NULL) return false;
    cur = node->list->head;

    while (cur != NULL) {
        switch (cur->node_type) {
            case YARLY:
                if (lolVarGetTroof(lolGetVar("IT"))) {
                    gtfo = executeList(cur->list);
                    blockDone = 1;
                }
                break;
            case MEBBE:
                if (cur->list == NULL || cur->list->head->next == NULL) {
                    elog(ERROR, "Invalid construction of MEBBE node -- missing execute list for MEBBE or MEBBEBLOCK");
                    return false;
                }
                executeNode(cur->list->head);
                if (lolVarGetTroof(lolGetVar("IT"))) {
                    gtfo = executeNode(cur->list->head->next);
                    blockDone = 1;
                }
                break;
            case NOWAI:
                if (!blockDone) {
                    gtfo = executeList(cur->list);
                }
                break;
            default:
                elog(ERROR, "Invalid block type %d in O RLY parse tree", cur->node_type);
        }
        cur = cur->next;
    }
    return gtfo;
}

void
wtfNode(lolNode *node)
{
    lolNode *cur;
    bool foundMatch = 0, gtfo = 0;
    lolIdent *tmp = lolGetVar("IT");
    lolIdent myIT, compResult;
    lolNode myNode;

    if (node->list == NULL) return;
    cur = node->list->head;
    myIT.type = tmp->type;
    myIT.value = tmp->value;
    myNode.node_type = BOTHSAEM;

    while (cur != NULL && !gtfo) {
        if (cur->node_type == OMG) {
            if (cur->list == NULL) return;

            /* The code block should be executed if one of the following is true:
                1) the included literal matches the original value of IT
                2) some earlier literal matched IT and no GTFO has been reached since then */
            if (!foundMatch) { 
                /* Note: This handling will have to be reworked when I make IT behave properly. I can't just go resetting IT all over */
                executeNode(cur->list->head);
                tmp = lolGetVar("IT");
                compResult = comparisonNode(&myNode, myIT, *tmp);
            }

            if ((foundMatch && !gtfo) || compResult.value.numbrVal == 1) {
                foundMatch = 1;
                lolSetVar("IT", myIT.type, myIT.value);
                gtfo = executeList(cur->list->head->list);
            }
        }
        else if (cur->node_type == OMGWTF) {
            if (!foundMatch || (foundMatch && !gtfo)) {
                executeList(cur->list);
            }
        }
        else {
            elog(ERROR, "Unknown node type %d in WTF list in parse tree", node->node_type);
            return;
        }
        cur = cur->next;
    }
}

void
iminyrNode(lolNode *node)
{
    bool endLoop = false;

    if (node == NULL) return;

    while (!endLoop)
        endLoop = executeList(node->list);
}

bool
executeNode(lolNode *node)
{
    bool gtfo = false;
    lolIdent *tmpVar;
    if (node == NULL) return false;
    switch (node->node_type) {
        case VISIBLE:
            visibleNode(node);
            break;
        case YARN:
            yarnNode(node);
            break;
        case NUMBR:
            numbrNode(node);
            break;
        case NUMBAR:
            numbarNode(node);
            break;
        case TROOF:
            troofNode(node);
            break;
        case FOUNDYR:
            foundyrNode(node);
            break;
        case IDENT:
            identNode(node);
            break;    
        case SUMOF:
        case DIFFOF:
        case PRODUKTOF:
        case QUOSHUNTOF:
        case MODOF:
        case BIGGROF:
        case SMALLROF:
        case BOTHOF:
        case EITHEROF:
        case WONOF:
        case BOTHSAEM:
        case DIFFRINT:
            binaryOprNode(node);
            break;
        case NOT:
            unaryOprNode(node);
            break;
        case SMOOSH:
            smooshNode(node);
            break;
        case ALLOF:
            allOfNode(node);
            break;
        case ANYOF:
            anyOfNode(node);
            break;
        case DECL:
            /* Variable name is in this nodes value, node->list, if not null, contains the expression to assign it to */
            lolDeclareVar(node->nodeVal.yarnVal);
            if (node->list != NULL) {
                executeNode(node->list->head);
                tmpVar = lolGetVar("IT");
                lolSetVar(node->nodeVal.yarnVal, tmpVar->type, tmpVar->value);
            }            
            break;
        case MAEK:
        case ISNOWA:
            castNode(node);
            break;
        case R:
            assignNode(node);
            break;
        case OUTTADATABUKKIT:
            SPInode(node);
            break;
        case ORLY:
            gtfo = orlyNode(node);
            break;
        case MEBBEBLOCK:
            executeList(node->list);
            break;
        case WTF:
            wtfNode(node);
            break;
        case IMINYR:
            iminyrNode(node);
            break;

            /* Debugging stuff */
        case YRVARZ:
            printSymbolTable();
            break;

        default:
            elog(INFO, "Cannot execute node type");
            printNode(node);
            break;
    }
    return gtfo;
}

void
SPInode(lolNode *node) 
{
    char *SPIval;

    /*| GIMMEH lol_var OUTTADATABUKKIT lol_expression
                {
                    $$ = lolMakeNode(OUTTADATABUKKIT, ($2)->nodeVal, lolMakeList($4)); */
    int res;
    if (node->list == NULL) {
        elog(NOTICE, "GIMMEH ... OUTTA DATABUKKIT needs a query to pass to the databukkit.");
        return;
    }
    executeList(node->list);
    /* The query is now in IT */
    res = SPI_exec(lolVarGetString(IT, false), 0);
    switch (res) {
        case SPI_OK_SELECT:
        case SPI_OK_INSERT_RETURNING:
        case SPI_OK_DELETE_RETURNING:
        case SPI_OK_UPDATE_RETURNING:
            elog(DEBUG3, "PL/LOLCODE SPI: Processed %d rows", SPI_processed);
            if (SPI_processed < 1) {
                elog(DEBUG5, "PL/LOLCODE SPI: No rows returned");
                return;
            }
            SPIval = SPI_getvalue(SPI_tuptable->vals[0], SPI_tuptable->tupdesc, 1);
            LOLifyString(SPIval, SPI_gettypeid(SPI_tuptable->tupdesc, 1), node->nodeVal.yarnVal);
            break;

        case SPI_ERROR_ARGUMENT:
            elog(ERROR, "SPI_execute returned SPI_ERROR_ARGUMENT. Please provide a proper query to retrieve.");
            break;
        case SPI_ERROR_COPY:
            elog(ERROR, "PL/LOLCODE can't copy to STDOUT or from STDIN");
            break;
        case SPI_ERROR_TRANSACTION:
            elog(ERROR, "Transaction's cannot be manipulated using GIMMEH ... OUTTA DATABUKKIT");
            break;
        case SPI_ERROR_OPUNKNOWN:
            elog(ERROR, "Something bad's going on -- SPI return SPI_ERROR_OPUNKNOWN.");
            break;
        case SPI_ERROR_UNCONNECTED:
            elog(ERROR, "Disconnected from SPI. No idea why.");
            break;
        default:
            break;
    }
}

bool
executeList(lolNodeList *list)
{
    lolNode *cur;
    bool gtfo = false;

    if (list == NULL) return false;
    cur = list->head;
    while (cur != NULL) {
        if (cur->node_type == GTFO) return true;
        gtfo = executeNode(cur);
        cur = cur->next;
    }
    return gtfo;
}
