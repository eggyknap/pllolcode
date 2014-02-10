/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1489 of yacc.c.  */
#line 191 "gram.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE pllolcode_yylval;

