/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse pllolcode_yyparse
#define yylex   pllolcode_yylex
#define yyerror pllolcode_yyerror
#define yylval  pllolcode_yylval
#define yychar  pllolcode_yychar
#define yydebug pllolcode_yydebug
#define yynerrs pllolcode_yynerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     HAI = 258,
     KTHXBYE = 259,
     EXPREND = 260,
     YARN = 261,
     IDENTIFIER = 262,
     NUMBR = 263,
     NUMBAR = 264,
     TROOFWIN = 265,
     TROOFFAIL = 266,
     TROOF = 267,
     VISIBLE = 268,
     VISDEBUG = 269,
     VISLOG = 270,
     VISNOTICE = 271,
     VISINFO = 272,
     VISWARNING = 273,
     VISEXCEPTION = 274,
     FOUNDYR = 275,
     IHASA = 276,
     ITZ = 277,
     R = 278,
     SUMOF = 279,
     DIFFOF = 280,
     PRODUKTOF = 281,
     QUOSHUNTOF = 282,
     MODOF = 283,
     BIGGROF = 284,
     SMALLROF = 285,
     AN = 286,
     BOTHOF = 287,
     EITHEROF = 288,
     WONOF = 289,
     NOT = 290,
     ALLOF = 291,
     ANYOF = 292,
     SMOOSH = 293,
     MKAY = 294,
     BOTHSAEM = 295,
     DIFFRINT = 296,
     MAEK = 297,
     A = 298,
     TROOFTYPE = 299,
     NUMBRTYPE = 300,
     YARNTYPE = 301,
     NUMBARTYPE = 302,
     NOOBTYPE = 303,
     ISNOWA = 304,
     GIMMEH = 305,
     OUTTADATABUKKIT = 306,
     ORLY = 307,
     OIC = 308,
     YARLY = 309,
     NOWAI = 310,
     MEBBE = 311,
     WTF = 312,
     OMG = 313,
     OMGWTF = 314,
     GTFO = 315,
     IMINYR = 316,
     IMOUTTAYR = 317,
     YRVARZ = 318,
     IDENT = 319,
     CMDBLOCK = 320,
     DECL = 321,
     MEBBEBLOCK = 322
   };
#endif
/* Tokens.  */
#define HAI 258
#define KTHXBYE 259
#define EXPREND 260
#define YARN 261
#define IDENTIFIER 262
#define NUMBR 263
#define NUMBAR 264
#define TROOFWIN 265
#define TROOFFAIL 266
#define TROOF 267
#define VISIBLE 268
#define VISDEBUG 269
#define VISLOG 270
#define VISNOTICE 271
#define VISINFO 272
#define VISWARNING 273
#define VISEXCEPTION 274
#define FOUNDYR 275
#define IHASA 276
#define ITZ 277
#define R 278
#define SUMOF 279
#define DIFFOF 280
#define PRODUKTOF 281
#define QUOSHUNTOF 282
#define MODOF 283
#define BIGGROF 284
#define SMALLROF 285
#define AN 286
#define BOTHOF 287
#define EITHEROF 288
#define WONOF 289
#define NOT 290
#define ALLOF 291
#define ANYOF 292
#define SMOOSH 293
#define MKAY 294
#define BOTHSAEM 295
#define DIFFRINT 296
#define MAEK 297
#define A 298
#define TROOFTYPE 299
#define NUMBRTYPE 300
#define YARNTYPE 301
#define NUMBARTYPE 302
#define NOOBTYPE 303
#define ISNOWA 304
#define GIMMEH 305
#define OUTTADATABUKKIT 306
#define ORLY 307
#define OIC 308
#define YARLY 309
#define NOWAI 310
#define MEBBE 311
#define WTF 312
#define OMG 313
#define OMGWTF 314
#define GTFO 315
#define IMINYR 316
#define IMOUTTAYR 317
#define YRVARZ 318
#define IDENT 319
#define CMDBLOCK 320
#define DECL 321
#define MEBBEBLOCK 322




/* Copy the first part of user declarations.  */
#line 1 "gram.y"


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


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 31 "gram.y"
{
    int numbrVal;
    double numbarVal;
    char *yarnVal;
    struct lolNodeList *nodeList;
    struct lolNode *node;
}
/* Line 187 of yacc.c.  */
#line 272 "gram.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 285 "gram.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   414

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNRULES -- Number of states.  */
#define YYNSTATES  126

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   322

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     9,    12,    14,    17,    23,    29,    37,
      41,    44,    47,    52,    55,    59,    63,    68,    72,    75,
      80,    84,    86,    89,    94,    98,   101,   103,   105,   107,
     111,   117,   122,   127,   133,   138,   140,   142,   144,   146,
     148,   150,   153,   156,   160,   162,   164,   166,   168,   170,
     172,   174,   176,   178,   180,   182,   184,   186,   188,   190,
     192,   194,   196,   198,   200,   202,   204,   206,   208,   210,
     212
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      69,     0,    -1,     3,     5,    70,     4,     5,    -1,    70,
      71,    -1,    71,    -1,    72,     5,    -1,    52,     5,    73,
      53,     5,    -1,    57,     5,    74,    53,     5,    -1,    61,
       7,     5,    70,    62,     7,     5,    -1,    13,    82,    72,
      -1,    13,    72,    -1,    20,    72,    -1,    21,    76,    22,
      72,    -1,    21,    76,    -1,    76,    23,    72,    -1,    42,
      72,    75,    -1,    42,    72,    43,    75,    -1,    76,    49,
      75,    -1,    50,    63,    -1,    50,    76,    51,    72,    -1,
      50,    51,    72,    -1,    60,    -1,    77,    39,    -1,    80,
      72,    31,    72,    -1,    80,    72,    72,    -1,    79,    72,
      -1,    77,    -1,    81,    -1,    76,    -1,    54,     5,    70,
      -1,    73,    56,    72,     5,    70,    -1,    73,    55,     5,
      70,    -1,    58,    81,     5,    70,    -1,    74,    58,    81,
       5,    70,    -1,    74,    59,     5,    70,    -1,    44,    -1,
      45,    -1,    47,    -1,    46,    -1,    48,    -1,     7,    -1,
      78,    72,    -1,    77,    72,    -1,    77,    31,    72,    -1,
      36,    -1,    37,    -1,    38,    -1,    35,    -1,    24,    -1,
      25,    -1,    26,    -1,    27,    -1,    28,    -1,    29,    -1,
      30,    -1,    32,    -1,    33,    -1,    34,    -1,    40,    -1,
      41,    -1,     6,    -1,     9,    -1,     8,    -1,    10,    -1,
      11,    -1,    14,    -1,    15,    -1,    16,    -1,    17,    -1,
      18,    -1,    19,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    72,    72,    77,    78,    82,    83,    85,    87,   103,
     108,   113,   114,   118,   119,   123,   128,   133,   138,   139,
     143,   148,   149,   150,   154,   158,   159,   160,   161,   165,
     170,   172,   177,   190,   204,   209,   210,   211,   212,   213,
     217,   230,   232,   233,   237,   238,   239,   243,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     262,   266,   267,   268,   269,   273,   274,   275,   276,   277,
     278
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "HAI", "KTHXBYE", "EXPREND", "YARN",
  "IDENTIFIER", "NUMBR", "NUMBAR", "TROOFWIN", "TROOFFAIL", "TROOF",
  "VISIBLE", "VISDEBUG", "VISLOG", "VISNOTICE", "VISINFO", "VISWARNING",
  "VISEXCEPTION", "FOUNDYR", "IHASA", "ITZ", "R", "SUMOF", "DIFFOF",
  "PRODUKTOF", "QUOSHUNTOF", "MODOF", "BIGGROF", "SMALLROF", "AN",
  "BOTHOF", "EITHEROF", "WONOF", "NOT", "ALLOF", "ANYOF", "SMOOSH", "MKAY",
  "BOTHSAEM", "DIFFRINT", "MAEK", "A", "TROOFTYPE", "NUMBRTYPE",
  "YARNTYPE", "NUMBARTYPE", "NOOBTYPE", "ISNOWA", "GIMMEH",
  "OUTTADATABUKKIT", "ORLY", "OIC", "YARLY", "NOWAI", "MEBBE", "WTF",
  "OMG", "OMGWTF", "GTFO", "IMINYR", "IMOUTTAYR", "YRVARZ", "IDENT",
  "CMDBLOCK", "DECL", "MEBBEBLOCK", "$accept", "lol_program",
  "lol_cmdblock", "lol_cmd", "lol_expression", "lol_orly_block",
  "lol_wtf_block", "lol_typename", "lol_var", "lol_xaryoprgroup",
  "lol_xaryopr", "lol_unaryopr", "lol_binaryopr", "lol_const",
  "lol_visibleLevel", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    68,    69,    70,    70,    71,    71,    71,    71,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    73,
      73,    73,    74,    74,    74,    75,    75,    75,    75,    75,
      76,    77,    77,    77,    78,    78,    78,    79,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      81,    81,    81,    81,    81,    82,    82,    82,    82,    82,
      82
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     1,     2,     5,     5,     7,     3,
       2,     2,     4,     2,     3,     3,     4,     3,     2,     4,
       3,     1,     2,     4,     3,     2,     1,     1,     1,     3,
       5,     4,     4,     5,     4,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,    60,    40,    62,    61,    63,
      64,     0,     0,     0,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    47,    44,    45,    46,    58,    59,
       0,     0,     0,     0,    21,     0,     0,     4,     0,    28,
      26,     0,     0,     0,    27,    65,    66,    67,    68,    69,
      70,    10,     0,    11,    13,     0,     0,    18,     0,     0,
       0,     0,     0,     3,     5,     0,     0,     0,    22,    42,
      41,    25,     0,     9,     0,     0,    35,    36,    38,    37,
      39,    15,    20,     0,     0,     0,     0,     0,     0,     2,
      14,    17,    43,     0,    24,    12,    16,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,    29,     6,
       0,     0,     0,     7,     0,     0,     0,    31,     0,    32,
       0,    34,     0,    30,    33,     8
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    36,    37,    38,    85,    87,    81,    39,    40,
      41,    42,    43,    44,    52
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -82
static const yytype_int16 yypact[] =
{
       6,     5,    11,   184,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   240,   354,     9,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     354,    -5,    12,    13,   -82,    33,    89,   -82,    15,   -16,
     278,   354,   354,   354,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   354,   -82,    21,     4,   354,   -82,     2,     1,
      -1,    54,    55,   -82,   -82,   354,   -20,   354,   -82,   -82,
     -82,   -82,   316,   -82,   354,   -20,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   354,    63,   -18,    56,   -45,   184,   -82,
     -82,   -82,   -82,   354,   -82,   -82,   -82,   -82,   184,    64,
      65,   354,    66,    68,    56,    70,   127,   -82,   184,   -82,
     184,    72,   184,   -82,    73,   184,    74,   184,   184,   184,
     184,   184,    75,   184,   184,   -82
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -82,   -82,   -76,   -32,   -11,   -82,   -82,   -60,   -10,   -82,
     -82,   -82,   -82,   -81,   -82
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      51,    53,     6,    54,    63,   102,    91,    65,   103,     1,
       3,     4,   106,   104,   105,    96,     6,    59,    60,    55,
      64,    58,   108,   114,    76,    77,    78,    79,    80,    69,
      70,    71,    72,    66,   117,    99,   119,   100,   101,   121,
      61,    73,   123,    74,   124,    82,    56,    75,    76,    77,
      78,    79,    80,    83,    90,    84,    92,    86,    57,    88,
      89,    94,     5,    95,     7,     8,     9,    10,    98,   109,
     110,   112,    97,   113,    63,   115,    63,   118,   120,     0,
     125,   122,   107,     0,     0,    63,     0,    63,     0,    63,
     111,    63,    63,    62,     0,     5,     6,     7,     8,     9,
      10,     0,    11,     0,     0,     0,     0,     0,     0,    12,
      13,     0,     0,    14,    15,    16,    17,    18,    19,    20,
       0,    21,    22,    23,    24,    25,    26,    27,     0,    28,
      29,    30,     0,     5,     6,     7,     8,     9,    10,    31,
      11,    32,     0,     0,     0,     0,    33,    12,    13,    34,
      35,    14,    15,    16,    17,    18,    19,    20,     0,    21,
      22,    23,    24,    25,    26,    27,     0,    28,    29,    30,
       0,     0,     0,     0,     0,     0,     0,    31,     0,    32,
       0,     0,     0,     0,    33,     0,     0,    34,    35,   116,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,     0,     0,     0,    12,    13,     0,     0,    14,    15,
      16,    17,    18,    19,    20,     0,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    29,    30,     0,     0,     0,
       0,     0,     0,     0,    31,     0,    32,     0,     0,     0,
       0,    33,     0,     0,    34,    35,     5,     6,     7,     8,
       9,    10,     0,    11,    45,    46,    47,    48,    49,    50,
      12,    13,     0,     0,    14,    15,    16,    17,    18,    19,
      20,     0,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,     0,     5,     6,     7,     8,     9,    10,
      31,    11,     0,     0,     0,     0,     0,     0,    12,    13,
      34,     0,    14,    15,    16,    17,    18,    19,    20,    67,
      21,    22,    23,    24,    25,    26,    27,    68,    28,    29,
      30,     0,     5,     6,     7,     8,     9,    10,    31,    11,
       0,     0,     0,     0,     0,     0,    12,    13,    34,     0,
      14,    15,    16,    17,    18,    19,    20,    93,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,     0,
       5,     6,     7,     8,     9,    10,    31,    11,     0,     0,
       0,     0,     0,     0,    12,    13,    34,     0,    14,    15,
      16,    17,    18,    19,    20,     0,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    29,    30,     0,     0,     0,
       0,     0,     0,     0,    31,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    34
};

static const yytype_int8 yycheck[] =
{
      11,    12,     7,    13,    36,    86,    66,    23,    53,     3,
       5,     0,    88,    58,    59,    75,     7,     5,     5,    30,
       5,    31,    98,   104,    44,    45,    46,    47,    48,    40,
      41,    42,    43,    49,   110,    53,   112,    55,    56,   115,
       7,    52,   118,    22,   120,    56,    51,    43,    44,    45,
      46,    47,    48,    51,    65,    54,    67,    58,    63,     5,
       5,    72,     6,    74,     8,     9,    10,    11,     5,     5,
       5,     5,    83,     5,   106,     5,   108,     5,     5,    -1,
       5,     7,    93,    -1,    -1,   117,    -1,   119,    -1,   121,
     101,   123,   124,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    -1,    -1,    24,    25,    26,    27,    28,    29,    30,
      -1,    32,    33,    34,    35,    36,    37,    38,    -1,    40,
      41,    42,    -1,     6,     7,     8,     9,    10,    11,    50,
      13,    52,    -1,    -1,    -1,    -1,    57,    20,    21,    60,
      61,    24,    25,    26,    27,    28,    29,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    -1,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    52,
      -1,    -1,    -1,    -1,    57,    -1,    -1,    60,    61,    62,
       6,     7,     8,     9,    10,    11,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    -1,    -1,    24,    25,
      26,    27,    28,    29,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    -1,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    52,    -1,    -1,    -1,
      -1,    57,    -1,    -1,    60,    61,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    24,    25,    26,    27,    28,    29,
      30,    -1,    32,    33,    34,    35,    36,    37,    38,    -1,
      40,    41,    42,    -1,     6,     7,     8,     9,    10,    11,
      50,    13,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      60,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    -1,     6,     7,     8,     9,    10,    11,    50,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    60,    -1,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    40,    41,    42,    -1,
       6,     7,     8,     9,    10,    11,    50,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    60,    -1,    24,    25,
      26,    27,    28,    29,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    -1,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    69,     5,     0,     6,     7,     8,     9,    10,
      11,    13,    20,    21,    24,    25,    26,    27,    28,    29,
      30,    32,    33,    34,    35,    36,    37,    38,    40,    41,
      42,    50,    52,    57,    60,    61,    70,    71,    72,    76,
      77,    78,    79,    80,    81,    14,    15,    16,    17,    18,
      19,    72,    82,    72,    76,    72,    51,    63,    76,     5,
       5,     7,     4,    71,     5,    23,    49,    31,    39,    72,
      72,    72,    72,    72,    22,    43,    44,    45,    46,    47,
      48,    75,    72,    51,    54,    73,    58,    74,     5,     5,
      72,    75,    72,    31,    72,    72,    75,    72,     5,    53,
      55,    56,    81,    53,    58,    59,    70,    72,    70,     5,
       5,    72,     5,     5,    81,     5,    62,    70,     5,    70,
       5,    70,     7,    70,    70,     5
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 73 "gram.y"
    { yylval.nodeList = (lolNodeList *) (yyvsp[(3) - (5)].nodeList); ;}
    break;

  case 3:
#line 77 "gram.y"
    { (yyval.nodeList) = lolListAppend((yyvsp[(1) - (2)].nodeList), (yyvsp[(2) - (2)].node)); ;}
    break;

  case 4:
#line 78 "gram.y"
    { (yyval.nodeList) = lolMakeList((yyvsp[(1) - (1)].node)); ;}
    break;

  case 5:
#line 82 "gram.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 6:
#line 84 "gram.y"
    { (yyval.node) = lolMakeNode(ORLY, tmpnval, (yyvsp[(3) - (5)].nodeList)); ;}
    break;

  case 7:
#line 86 "gram.y"
    { (yyval.node) = lolMakeNode(WTF, tmpnval, (yyvsp[(3) - (5)].nodeList)); ;}
    break;

  case 8:
#line 88 "gram.y"
    { 
                    /* TODO: Check $2 and $7 for equality */
                    (yyval.node) = lolMakeNode(IMINYR, tmpnval, (yyvsp[(4) - (7)].nodeList));
                ;}
    break;

  case 9:
#line 104 "gram.y"
    {
                    tmpnval.numbrVal = (yyvsp[(2) - (3)].numbrVal);
                    (yyval.node) = lolMakeNode(VISIBLE, tmpnval, lolMakeList((yyvsp[(3) - (3)].node)));
                ;}
    break;

  case 10:
#line 109 "gram.y"
    { 
                    tmpnval.numbrVal = NOTICE;
                    (yyval.node) = lolMakeNode(VISIBLE, tmpnval, lolMakeList((yyvsp[(2) - (2)].node)));
                ;}
    break;

  case 11:
#line 113 "gram.y"
    { (yyval.node) = lolMakeNode(FOUNDYR, tmpnval, lolMakeList((yyvsp[(2) - (2)].node))); ;}
    break;

  case 12:
#line 115 "gram.y"
    {
                    (yyval.node) = lolMakeNode(DECL, ((yyvsp[(2) - (4)].node))->nodeVal, lolMakeList((yyvsp[(4) - (4)].node)));
                ;}
    break;

  case 13:
#line 118 "gram.y"
    { (yyval.node) = lolMakeNode(DECL, ((yyvsp[(2) - (2)].node))->nodeVal, NULL); ;}
    break;

  case 14:
#line 120 "gram.y"
    { (yyval.node) = lolMakeNode(R, ((yyvsp[(1) - (3)].node))->nodeVal, lolMakeList((yyvsp[(3) - (3)].node))); ;}
    break;

  case 15:
#line 124 "gram.y"
    {
                    tmpnval.numbrVal = (yyvsp[(3) - (3)].numbrVal);
                    (yyval.node) = lolMakeNode(MAEK, tmpnval, lolMakeList((yyvsp[(2) - (3)].node)));
                ;}
    break;

  case 16:
#line 129 "gram.y"
    {
                    tmpnval.numbrVal = (yyvsp[(4) - (4)].numbrVal);
                    (yyval.node) = lolMakeNode(MAEK, tmpnval, lolMakeList((yyvsp[(2) - (4)].node)));
                ;}
    break;

  case 17:
#line 134 "gram.y"
    {
                    tmpnval.numbrVal = (yyvsp[(3) - (3)].numbrVal);
                    (yyval.node) = lolMakeNode(ISNOWA, tmpnval, lolMakeList((yyvsp[(1) - (3)].node)));
                ;}
    break;

  case 18:
#line 138 "gram.y"
    { (yyval.node) = lolMakeNode(YRVARZ, tmpnval, NULL); ;}
    break;

  case 19:
#line 140 "gram.y"
    {
                    (yyval.node) = lolMakeNode(OUTTADATABUKKIT, ((yyvsp[(2) - (4)].node))->nodeVal, lolMakeList((yyvsp[(4) - (4)].node)));
                ;}
    break;

  case 20:
#line 144 "gram.y"
    {
                    tmpnval.yarnVal = pstrdup("IT");
                    (yyval.node) = lolMakeNode(OUTTADATABUKKIT, tmpnval, lolMakeList((yyvsp[(3) - (3)].node)));
                ;}
    break;

  case 21:
#line 148 "gram.y"
    { (yyval.node) = lolMakeNode(GTFO, tmpnval, NULL); ;}
    break;

  case 22:
#line 149 "gram.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 23:
#line 151 "gram.y"
    {
                    (yyval.node) = lolMakeNode((yyvsp[(1) - (4)].numbrVal), tmpnval, lolMakeTwoNodeList((yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node)));
                ;}
    break;

  case 24:
#line 155 "gram.y"
    {
                    (yyval.node) = lolMakeNode((yyvsp[(1) - (3)].numbrVal), tmpnval, lolMakeTwoNodeList((yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node)));
                ;}
    break;

  case 25:
#line 158 "gram.y"
    { (yyval.node) = lolMakeNode((yyvsp[(1) - (2)].numbrVal), tmpnval, lolMakeList((yyvsp[(2) - (2)].node))); ;}
    break;

  case 26:
#line 159 "gram.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 27:
#line 160 "gram.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 28:
#line 161 "gram.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 29:
#line 165 "gram.y"
    { (yyval.nodeList) = lolMakeList(lolMakeNode(YARLY, tmpnval, (yyvsp[(3) - (3)].nodeList))); ;}
    break;

  case 30:
#line 171 "gram.y"
    { (yyval.nodeList) = lolListAppend((yyvsp[(1) - (5)].nodeList), lolMakeNode(MEBBE, tmpnval, lolMakeTwoNodeList((yyvsp[(3) - (5)].node), lolMakeNode(MEBBEBLOCK, tmpnval, (yyvsp[(5) - (5)].nodeList))))); ;}
    break;

  case 31:
#line 173 "gram.y"
    { (yyval.nodeList) = lolListAppend((yyvsp[(1) - (4)].nodeList), lolMakeNode(NOWAI, tmpnval, (yyvsp[(4) - (4)].nodeList))); ;}
    break;

  case 32:
#line 178 "gram.y"
    {
                    ((yyvsp[(2) - (4)].node))->list = (yyvsp[(4) - (4)].nodeList);
                    tmpnval.numbrVal = 0;
                    (yyval.nodeList) = lolMakeList(lolMakeNode(OMG, tmpnval, lolMakeList((yyvsp[(2) - (4)].node))));
                ;}
    break;

  case 33:
#line 191 "gram.y"
    {
                    ((yyvsp[(3) - (5)].node))->list = (yyvsp[(5) - (5)].nodeList);
                    tmpnval.numbrVal = 0;
                    (yyval.nodeList) = lolListAppend((yyvsp[(1) - (5)].nodeList), lolMakeNode(OMG, tmpnval, lolMakeList((yyvsp[(3) - (5)].node))));
                ;}
    break;

  case 34:
#line 205 "gram.y"
    { (yyval.nodeList) = lolListAppend((yyvsp[(1) - (4)].nodeList), lolMakeNode(OMGWTF, tmpnval, (yyvsp[(4) - (4)].nodeList))); ;}
    break;

  case 35:
#line 209 "gram.y"
    { (yyval.numbrVal) = ident_TROOF; ;}
    break;

  case 36:
#line 210 "gram.y"
    { (yyval.numbrVal) = ident_NUMBR; ;}
    break;

  case 37:
#line 211 "gram.y"
    { (yyval.numbrVal) = ident_NUMBAR; ;}
    break;

  case 38:
#line 212 "gram.y"
    { (yyval.numbrVal) = ident_YARN; ;}
    break;

  case 39:
#line 213 "gram.y"
    { (yyval.numbrVal) = ident_NOOB; ;}
    break;

  case 40:
#line 217 "gram.y"
    {
                    tmpnval.yarnVal = pstrdup(pllolcode_yytext);
                    (yyval.node) = lolMakeNode(IDENT, tmpnval, NULL);
                ;}
    break;

  case 41:
#line 231 "gram.y"
    { (yyval.node) = lolMakeNode((yyvsp[(1) - (2)].numbrVal), tmpnval, lolMakeList((yyvsp[(2) - (2)].node))); ;}
    break;

  case 42:
#line 232 "gram.y"
    { lolListAppend(((yyvsp[(1) - (2)].node))->list, (yyvsp[(2) - (2)].node)); (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 43:
#line 233 "gram.y"
    { lolListAppend(((yyvsp[(1) - (3)].node))->list, (yyvsp[(3) - (3)].node)); (yyval.node) = (yyvsp[(1) - (3)].node); ;}
    break;

  case 44:
#line 237 "gram.y"
    { (yyval.numbrVal) = ALLOF; ;}
    break;

  case 45:
#line 238 "gram.y"
    { (yyval.numbrVal) = ANYOF; ;}
    break;

  case 46:
#line 239 "gram.y"
    { (yyval.numbrVal) = SMOOSH; ;}
    break;

  case 47:
#line 243 "gram.y"
    { (yyval.numbrVal) = NOT; ;}
    break;

  case 48:
#line 247 "gram.y"
    { (yyval.numbrVal) = SUMOF; ;}
    break;

  case 49:
#line 248 "gram.y"
    { (yyval.numbrVal) = DIFFOF; ;}
    break;

  case 50:
#line 249 "gram.y"
    { (yyval.numbrVal) = PRODUKTOF; ;}
    break;

  case 51:
#line 250 "gram.y"
    { (yyval.numbrVal) = QUOSHUNTOF; ;}
    break;

  case 52:
#line 251 "gram.y"
    { (yyval.numbrVal) = MODOF; ;}
    break;

  case 53:
#line 252 "gram.y"
    { (yyval.numbrVal) = BIGGROF; ;}
    break;

  case 54:
#line 253 "gram.y"
    { (yyval.numbrVal) = SMALLROF; ;}
    break;

  case 55:
#line 254 "gram.y"
    { (yyval.numbrVal) = BOTHOF; ;}
    break;

  case 56:
#line 255 "gram.y"
    { (yyval.numbrVal) = EITHEROF; ;}
    break;

  case 57:
#line 256 "gram.y"
    { (yyval.numbrVal) = WONOF; ;}
    break;

  case 58:
#line 257 "gram.y"
    { (yyval.numbrVal) = BOTHSAEM; ;}
    break;

  case 59:
#line 258 "gram.y"
    { (yyval.numbrVal) = DIFFRINT; ;}
    break;

  case 60:
#line 262 "gram.y"
    {
                    tmpnval.yarnVal = pstrdup((yyvsp[(1) - (1)].yarnVal));
                    (yyval.node) = lolMakeNode(YARN, tmpnval, NULL);
                ;}
    break;

  case 61:
#line 266 "gram.y"
    { tmpnval.numbarVal = (yyvsp[(1) - (1)].numbarVal); (yyval.node) = lolMakeNode(NUMBAR, tmpnval, NULL); ;}
    break;

  case 62:
#line 267 "gram.y"
    { tmpnval.numbrVal = (yyvsp[(1) - (1)].numbrVal); (yyval.node) = lolMakeNode(NUMBR, tmpnval, NULL); ;}
    break;

  case 63:
#line 268 "gram.y"
    { tmpnval.numbrVal = 1; (yyval.node) = lolMakeNode(TROOF, tmpnval, NULL); ;}
    break;

  case 64:
#line 269 "gram.y"
    { tmpnval.numbrVal = 0; (yyval.node) = lolMakeNode(TROOF, tmpnval, NULL); ;}
    break;

  case 65:
#line 273 "gram.y"
    { (yyval.numbrVal) = DEBUG1; ;}
    break;

  case 66:
#line 274 "gram.y"
    { (yyval.numbrVal) = LOG; ;}
    break;

  case 67:
#line 275 "gram.y"
    { (yyval.numbrVal) = NOTICE; ;}
    break;

  case 68:
#line 276 "gram.y"
    { (yyval.numbrVal) = INFO; ;}
    break;

  case 69:
#line 277 "gram.y"
    { (yyval.numbrVal) = WARNING; ;}
    break;

  case 70:
#line 278 "gram.y"
    { (yyval.numbrVal) = ERROR; ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2047 "gram.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 280 "gram.y"


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

