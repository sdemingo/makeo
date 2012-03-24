
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
     ID = 258,
     ASIG_OP = 259,
     INT = 260,
     ADD = 261,
     SUB = 262,
     MUL = 263,
     DIV = 264,
     END_SENT = 265,
     STRING = 266,
     IMPORT = 267,
     FUNCTION = 268,
     RETURN = 269,
     MAIN_ID = 270,
     BLOCK_START = 271,
     BLOCK_END = 272,
     PAR_A = 273,
     PAR_C = 274,
     COMA = 275,
     IF = 276,
     EQ = 277
   };
#endif
/* Tokens.  */
#define ID 258
#define ASIG_OP 259
#define INT 260
#define ADD 261
#define SUB 262
#define MUL 263
#define DIV 264
#define END_SENT 265
#define STRING 266
#define IMPORT 267
#define FUNCTION 268
#define RETURN 269
#define MAIN_ID 270
#define BLOCK_START 271
#define BLOCK_END 272
#define PAR_A 273
#define PAR_C 274
#define COMA 275
#define IF 276
#define EQ 277




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 31 "yacc_spec.y"

  int ival;
  int sval;       //simbol index
  char *literal;
  char buf_code[64];       // buffer para subir código a través del árbol de no-terminales



/* Line 1676 of yacc.c  */
#line 105 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


