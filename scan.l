%{
#include "pllolcode_lang.h"
#include "pllolcode.h"
#include "postgres.h"
#include <string.h>
#include <stdlib.h>
#define LOL_LEX_DEBUG 1

#define YYSTACK_FREE pfree
#define YYSTACK_MALLOC palloc
#define YYFREE pfree
#define YYMALLOC palloc
#define YY_NO_INPUT

static YY_BUFFER_STATE scanbufhandle;
static char *scanbuf;

int  pllolcode_yylex(void);
void pllolcode_yyerror(char *);

/* These declarations get rid of compiler warnings */
FILE *pllolcode_yyget_in(void);
FILE *pllolcode_yyget_out(void);
int   pllolcode_yyget_leng(void);
char *pllolcode_yyget_text(void);
void  pllolcode_yyset_lineno(int);
int   pllolcode_yyget_lineno(void);
void  pllolcode_yyset_in(FILE *);
void  pllolcode_yyset_out(FILE *);
int   pllolcode_yyget_debug(void);
void  pllolcode_yyset_debug(int);
void  inline lol_lex_debug(char *s);

void pllolcode_scanner_init(const char *str);
void pllolcode_scanner_finish(void);

char *pllolcode_get_string_value(void);

int lineNumber = 0;

%}

%option nodefault
%option nounput
%option prefix="pllolcode_yy"
/* %option debug */

%x LOL_STRING
%x LOL_LINECOMMENT
%x LOL_BLOCKCMT

%%
    /* todo: make this more robust (e.g. buffer length checking) */
    /* OLD STRING HANDLING
    char *stringptr = NULL; */

    /* Reworked string handling, copied from plpgsql */
    char *start_charpos = NULL;

\"            { 
                /* TODO: Quit using stringbuf, use yytext. alloc a new char*
                 * for the contents and stick it in pllolcode_yyval.yarnVal */
                BEGIN LOL_STRING;
                start_charpos = yytext;
                /* OLD STRING HANDLING
                memset(stringbuf, 0, 255);
                stringptr = stringbuf; */
            }
 /* OLD STRING HANDLING : note that this decoding now happens in pllolcode_get_string
<LOL_STRING>\\n        { *stringptr++ = '\n'; }
<LOL_STRING>\\t        { *stringptr++ = '\t'; }
<LOL_STRING>\\\"    { *stringptr++ = '\"'; } */
<LOL_STRING>\\.        { }
<LOL_STRING>\\        { }
<LOL_STRING>\n        { lol_lex_debug("invalid string -- newline before closing quotes"); lineNumber++; exit(1); }
<LOL_STRING>\"        { 
                /* OLD STRING HANDLING
                *stringptr = 0;
                lol_lex_debug("yylex found string"); lol_lex_debug(stringbuf); */

                yyleng += (yytext - start_charpos);
                yytext = start_charpos;
                pllolcode_yylval.yarnVal = pllolcode_get_string_value();
                BEGIN 0;
                return YARN;
            }
<LOL_STRING>.        {}
 /* OLD STRING HANDLING 
<LOL_STRING>.        { *stringptr++ = *yytext; } */

BTW            { BEGIN LOL_LINECOMMENT; }
<LOL_LINECOMMENT>\n    { BEGIN 0; lol_lex_debug("yylex: line comment"); lineNumber++; }
<LOL_LINECOMMENT>.    {}

OBTW            { BEGIN LOL_BLOCKCMT; }
<LOL_BLOCKCMT>TLDR    { BEGIN 0; lol_lex_debug("yylex: block comment"); }
<LOL_BLOCKCMT>\n    { lineNumber++; }
<LOL_BLOCKCMT>.        {}

HAI            { lol_lex_debug("yylex: HAI"); return HAI; }
KTHXBYE            { lol_lex_debug("yylex: KTHXBYE"); return KTHXBYE; }

VISIBLE            { lol_lex_debug("yylex: VISIBLE"); return VISIBLE; }
DEBUG            { lol_lex_debug("yylex: VISDEBUG"); return VISDEBUG; }
LOG            { lol_lex_debug("yylex: VISLOG"); return VISLOG; }
NOTICE            { lol_lex_debug("yylex: VISNOTICE"); return VISNOTICE; }
INFO            { lol_lex_debug("yylex: VISINFO"); return VISINFO; }
WARNING            { lol_lex_debug("yylex: VISWARNING"); return VISWARNING; }
EXCEPTION        { lol_lex_debug("yylex: VISEXCEPTION"); return VISEXCEPTION; }

WIN            { lol_lex_debug("yylex: TROOFWIN"); return TROOFWIN; }
FAIL            { lol_lex_debug("yylex: TROOFFAIL"); return TROOFFAIL; }

    /* Arithmetic functions */
"SUM OF"        { lol_lex_debug("yylex: SUMOF"); return SUMOF; }
"DIFF OF"        { lol_lex_debug("yylex: DIFFOF"); return DIFFOF; }
"PRODUKT OF"        { lol_lex_debug("yylex: PRODUKTOF"); return PRODUKTOF; }
"QUOSHUNT OF"        { lol_lex_debug("yylex: QUOSHUNTOF"); return QUOSHUNTOF; }
"MOD OF"        { lol_lex_debug("yylex: MODOF"); return MODOF; }
"BIGGR OF"        { lol_lex_debug("yylex: BIGGROF"); return BIGGROF; }
"SMALLR OF"        { lol_lex_debug("yylex: SMALLROF"); return SMALLROF; }
AN            { lol_lex_debug("yylex: AN"); return AN; }

    /* Operators */
"BOTH OF"        { lol_lex_debug("yylex: BOTHOF"); return BOTHOF; }
"EITHER OF"        { lol_lex_debug("yylex: EITHEROF"); return EITHEROF; }
"WON OF"        { lol_lex_debug("yylex: WONOF"); return WONOF; }
NOT            { lol_lex_debug("yylex: NOT"); return NOT; }
"ALL OF"        { lol_lex_debug("yylex: ALLOF"); return ALLOF; }
"ANY OF"        { lol_lex_debug("yylex: ANYOF"); return ANYOF; }
SMOOSH          { lol_lex_debug("yylex: SMOOSH"); return SMOOSH; }
MKAY            { lol_lex_debug("yylex: MKAY"); return MKAY; }

    /* Comparison */
"BOTH SAEM"        { lol_lex_debug("yylex: BOTHSAEM"); return BOTHSAEM; }
DIFFRINT        { lol_lex_debug("yylex: DIFFRINT"); return DIFFRINT; }
"O RLY?"        { lol_lex_debug("yylex: O RLY?"); return ORLY; }
"YA RLY"        { lol_lex_debug("yylex: YA RLY"); return YARLY; }
"NO WAI"        { lol_lex_debug("yylex: NO WAI"); return NOWAI; }
MEBBE            { lol_lex_debug("yylex: MEBBE"); return MEBBE; }
OIC            { lol_lex_debug("yylex: OIC"); return OIC; }

    /* Case */
"WTF?"            { lol_lex_debug("yylex: WTF?"); return WTF; }
OMG            { lol_lex_debug("yylex: OMG"); return OMG; }
OMGWTF            { lol_lex_debug("yylex: OMGWTF"); return OMGWTF; }
GTFO            { lol_lex_debug("yylex: GTFO"); return GTFO; }

    /* Loop */
"IM IN YR"        { lol_lex_debug("yylex: IM IN YR"); return IMINYR; }
"IM OUTTA YR"        { lol_lex_debug("yylex: IM OUTTA YR"); return IMOUTTAYR; }

    /* Assignment, declaration */
"I HAS A"        { lol_lex_debug("yylex: IHASA"); return IHASA; }
ITZ            { lol_lex_debug("yylex: ITZ"); return ITZ; }
R            { lol_lex_debug("yylex: R"); return R; }
"FOUND YR"        { lol_lex_debug("yylex: FOUNDYR"); return FOUNDYR; }

    /* Casting */
MAEK            { lol_lex_debug("yylex: MAEK"); return MAEK; }
"IS NOW A"        { lol_lex_debug("yylex: ISNOWA"); return ISNOWA; }
A            { lol_lex_debug("yylex: A"); return A; }
TROOF            { lol_lex_debug("yylex: TROOFTYPE"); return TROOFTYPE; }
NUMBR            { lol_lex_debug("yylex: NUMBRTYPE"); return NUMBRTYPE; }
NUMBAR            { lol_lex_debug("yylex: NUMBARTYPE"); return NUMBARTYPE; }
YARN            { lol_lex_debug("yylex: YARNTYPE"); return YARNTYPE; }
NOOB            { lol_lex_debug("yylex: NOOBTYPE"); return NOOBTYPE; }

    /* SPI */
GIMMEH            { lol_lex_debug("yylex: GIMMEH"); return GIMMEH; }
"OUTTA DATABUKKIT"    { lol_lex_debug("yylex: OUTTADATABUKKIT"); return OUTTADATABUKKIT; }

    /* debugging commands */
"YR VARZ"        { lol_lex_debug("yylex: YRVARZ"); return YRVARZ; }

[A-Za-z][A-Za-z0-9_]+        { lol_lex_debug("yylex: IDENTIFIER"); return IDENTIFIER; }
[\+-]?[0-9]+            {
                    lol_lex_debug("yylex: NUMBR");
                    pllolcode_yylval.numbrVal = atoi(yytext);
                    return NUMBR;
                }
[\+-]?[0-9\.]+            {
                    lol_lex_debug("yylex: NUMBAR");
                    pllolcode_yylval.numbarVal = strtod(yytext, NULL);
                    return NUMBAR;
                }

^[\n]            { lineNumber++; }
[,\n]+            { lol_lex_debug("EXPREND"); lineNumber++; return EXPREND; }
[ \t]+        ;
.            { pllolcode_yyerror("Parse error: Unrecognized character"); }
%%

void lol_lex_debug(char *s) {
    if (LOL_LEX_DEBUG)
        elog(NOTICE, "%s", s);
}

int pllolcode_yywrap(void) {
    return 1;
}

char *pllolcode_get_string_value(void) {
    int len = 0;
    char *cp, *result;

    result = (char *) palloc(yyleng + 1);
    for (cp = yytext + 1; *cp; cp++) {
        if (*cp == '\\')
        {
            if (cp[1] == 'n') 
                result[len++] = '\n';
            else if (cp[1] == 't')
                result[len++] = '\t';
            else if (cp[1] == '"')
                result[len++] = '"';
            else if (cp[1] == '\\')
                result[len++] = '\\';
            cp++;
            /* Note that this code won't raise errors if you escape something invalid. TODO: Change that fact */
        }
        else if (*cp != '"') result[len++] = *cp;
    }
    result[len] = '\0';
    return result;
}

void pllolcode_scanner_init(const char *str) {
    /* More copying from PL/pgSQL */
    Size slen;
    slen = strlen(str);
/*    if (YY_CURRENT_BUFFER)
        pllolcode_yy_delete_buffer(YY_CURRENT_BUFFER); */
    scanbuf = palloc(slen + 2);
    memcpy(scanbuf, str, slen);
    scanbuf[slen] = scanbuf[slen + 1] = YY_END_OF_BUFFER_CHAR;
    scanbufhandle = pllolcode_yy_scan_buffer(scanbuf,slen + 2);

    BEGIN(INITIAL);
}

void
pllolcode_scanner_finish(void)
{
    pllolcode_yy_delete_buffer(scanbufhandle);
    pfree(scanbuf);
}
