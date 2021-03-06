
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "yacc_spec.y"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sim.h"
#include "code.h"
  
  
  extern int yylineno;
  int sim_i;


  void yyerror(const char *str)
  {
    //printf ("llamo a yyerror con str(%s)\n",str);
    if (str!=NULL)
      fprintf(stderr,"line %d: %s\n",yylineno,str);
  }

 
  
  void built_in(){
    load_il("sys.il");
    link_il("sys.il");
  }
  
  
  

/* Line 189 of yacc.c  */
#line 103 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
     EQ = 277,
     NQ = 278,
     LT = 279,
     GT = 280,
     AND = 281,
     OR = 282
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
#define NQ 278
#define LT 279
#define GT 280
#define AND 281
#define OR 282




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 31 "yacc_spec.y"

  int ival;
  int sval;       //simbol index
  char *literal;
  char buf_code[64];       // buffer para subir código a través del árbol de no-terminales



/* Line 214 of yacc.c  */
#line 202 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 214 "y.tab.c"

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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   122

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNRULES -- Number of states.  */
#define YYNSTATES  110

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

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
      25,    26,    27
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,    10,    13,    14,    17,    22,    25,
      30,    32,    35,    40,    45,    51,    53,    57,    61,    64,
      66,    69,    70,    72,    74,    76,    80,    84,    87,    90,
      93,    95,    97,    99,   101,   105,   110,   113,   116,   119,
     122,   125,   128,   133,   136,   139,   142,   147,   149,   151,
     153,   155,   157,   162,   166,   168,   172,   174,   178,   180,
     184,   189
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      29,     0,    -1,    30,    32,    -1,    30,    34,    32,    -1,
      30,    31,    -1,    -1,    12,     3,    -1,    33,    16,    39,
      17,    -1,    33,    40,    -1,    13,    15,    18,    19,    -1,
      35,    -1,    34,    35,    -1,    36,    16,    39,    38,    -1,
      13,     3,    18,    19,    -1,    13,     3,    18,    37,    19,
      -1,     3,    -1,     3,    20,    37,    -1,    14,    42,    17,
      -1,    14,    17,    -1,    17,    -1,    39,    40,    -1,    -1,
      41,    -1,    47,    -1,    49,    -1,     3,     4,    42,    -1,
       3,     4,    44,    -1,    43,     3,    -1,    43,     5,    -1,
      43,    11,    -1,     3,    -1,     5,    -1,    11,    -1,    47,
      -1,    18,    42,    19,    -1,    43,    18,    42,    19,    -1,
      42,     7,    -1,    42,     8,    -1,    42,     6,    -1,    45,
       3,    -1,    45,     5,    -1,    45,    11,    -1,    45,    18,
      44,    19,    -1,     3,    46,    -1,     5,    46,    -1,    11,
      46,    -1,    18,    44,    19,    46,    -1,    22,    -1,    26,
      -1,    27,    -1,    25,    -1,    24,    -1,     3,    18,    48,
      19,    -1,     3,    18,    19,    -1,     3,    -1,     3,    20,
      48,    -1,     5,    -1,     5,    20,    48,    -1,    11,    -1,
      11,    20,    48,    -1,    50,    16,    39,    17,    -1,    21,
      18,    44,    19,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    81,    81,    81,    84,    84,    87,    91,    92,    97,
     104,   104,   118,   124,   132,   145,   152,   161,   167,   171,
     186,   187,   190,   191,   192,   205,   211,   219,   228,   238,
     247,   255,   263,   269,   275,   281,   292,   301,   310,   323,
     329,   335,   341,   345,   350,   355,   360,   366,   371,   376,
     381,   386,   404,   411,   418,   424,   430,   436,   442,   448,
     461,   467
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "ASIG_OP", "INT", "ADD", "SUB",
  "MUL", "DIV", "END_SENT", "STRING", "IMPORT", "FUNCTION", "RETURN",
  "MAIN_ID", "BLOCK_START", "BLOCK_END", "PAR_A", "PAR_C", "COMA", "IF",
  "EQ", "NQ", "LT", "GT", "AND", "OR", "$accept", "PROGRAM", "IMPORTS",
  "IMPORT_DEF", "FUNC_MAIN_CODE", "FUNC_MAIN_HDR", "FUNCS", "FUNC_CODE",
  "FUNC_HDR", "PARAM_DEF", "RETURN_SENT", "BLOCK_SENT", "SENT", "ASIG",
  "EXP", "EXP2", "LEXP", "LEXP2", "LOP", "FUNC_CALL", "PARAM_CALL",
  "IF_SENT", "IF_HDR", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    28,    29,    29,    30,    30,    31,    32,    32,    33,
      34,    34,    35,    36,    36,    37,    37,    38,    38,    38,
      39,    39,    40,    40,    40,    41,    41,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    43,    43,    43,    44,
      44,    44,    44,    45,    45,    45,    45,    46,    46,    46,
      46,    46,    47,    47,    48,    48,    48,    48,    48,    48,
      49,    50
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     2,     0,     2,     4,     2,     4,
       1,     2,     4,     4,     5,     1,     3,     3,     2,     1,
       2,     0,     1,     1,     1,     3,     3,     2,     2,     2,
       1,     1,     1,     1,     3,     4,     2,     2,     2,     2,
       2,     2,     4,     2,     2,     2,     4,     1,     1,     1,
       1,     1,     4,     3,     1,     3,     1,     3,     1,     3,
       4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     1,     0,     0,     4,     2,     0,     0,
      10,     0,     6,     0,     0,     0,    21,     0,     8,    22,
      23,    24,     0,     3,    11,    21,     0,     0,     0,     0,
       0,     0,    21,     0,    15,    13,     0,     9,    30,    31,
      32,     0,    25,     0,    26,     0,    33,    54,    56,    58,
      53,     0,     7,    20,     0,     0,     0,     0,     0,     0,
       0,    19,    12,     0,    14,    47,    51,    50,    48,    49,
      43,    44,    45,     0,     0,    38,    36,    37,    27,    28,
      29,     0,    39,    40,    41,     0,     0,     0,     0,    52,
      61,    60,    30,    31,    32,    18,     0,     0,    16,    34,
       0,     0,     0,    55,    57,    59,    17,    46,    35,    42
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     6,     7,     8,     9,    10,    11,    36,
      62,    30,    53,    19,    73,    43,    74,    45,    70,    46,
      51,    21,    22
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -40
static const yytype_int8 yypact[] =
{
     -40,    37,    64,   -40,    38,     7,   -40,   -40,     3,    36,
     -40,    14,   -40,    49,    51,    30,   -40,    52,   -40,   -40,
     -40,   -40,    58,   -40,   -40,   -40,    17,    54,    39,    28,
       6,    40,   -40,     4,    34,   -40,    70,   -40,    76,    83,
      83,    39,     5,    57,   -40,    60,   -40,    71,    72,    75,
     -40,    92,   -40,   -40,    83,    83,    83,    40,    97,    11,
      35,   -40,   -40,    87,   -40,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,   -40,    74,    98,   -40,   -40,   -40,   -40,   -40,
     -40,    61,   -40,   -40,   -40,    40,   101,   101,   101,   -40,
     -40,   -40,    81,   -40,   -40,   -40,    61,    80,   -40,   -40,
      83,    77,    99,   -40,   -40,   -40,   -40,   -40,   -40,   -40
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -40,   -40,   -40,   -40,   110,   -40,   -40,   111,   -40,    59,
     -40,   -17,   113,   -40,   -25,   -40,   -26,   -40,   -39,    -4,
      27,   -40,   -40
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      71,    72,    44,    42,    20,    58,    15,    15,    33,    15,
      13,    75,    76,    77,    15,    59,    71,    72,    60,    16,
      34,    61,    14,    52,    17,    17,    20,    17,    91,    20,
      25,    47,    17,    48,    28,    97,    35,     3,    92,    49,
      93,    12,    38,    54,    39,    55,    94,    50,    29,     5,
      40,    56,    95,    96,    63,    20,   101,    41,    57,   102,
      78,   107,    79,    82,    92,    83,    93,    26,    80,    27,
      31,    84,    94,    37,    32,    81,     4,     5,    85,    96,
      75,    76,    77,    75,    76,    77,    75,    76,    77,    64,
      34,    86,    87,    99,    29,    88,   108,   106,    65,    29,
      66,    67,    68,    69,    47,    65,    48,    66,    67,    68,
      69,    89,    49,   103,   104,   105,    90,   100,   109,    23,
      24,    18,    98
};

static const yytype_uint8 yycheck[] =
{
      39,    40,    28,    28,     8,    31,     3,     3,    25,     3,
       3,     6,     7,     8,     3,    32,    55,    56,    14,    16,
       3,    17,    15,    17,    21,    21,    30,    21,    17,    33,
      16,     3,    21,     5,     4,    60,    19,     0,     3,    11,
       5,     3,     3,     3,     5,     5,    11,    19,    18,    13,
      11,    11,    17,    18,    20,    59,    81,    18,    18,    85,
       3,   100,     5,     3,     3,     5,     5,    18,    11,    18,
      18,    11,    11,    19,    16,    18,    12,    13,    18,    18,
       6,     7,     8,     6,     7,     8,     6,     7,     8,    19,
       3,    20,    20,    19,    18,    20,    19,    17,    22,    18,
      24,    25,    26,    27,     3,    22,     5,    24,    25,    26,
      27,    19,    11,    86,    87,    88,    19,    19,    19,     9,
       9,     8,    63
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    29,    30,     0,    12,    13,    31,    32,    33,    34,
      35,    36,     3,     3,    15,     3,    16,    21,    40,    41,
      47,    49,    50,    32,    35,    16,    18,    18,     4,    18,
      39,    18,    16,    39,     3,    19,    37,    19,     3,     5,
      11,    18,    42,    43,    44,    45,    47,     3,     5,    11,
      19,    48,    17,    40,     3,     5,    11,    18,    44,    39,
      14,    17,    38,    20,    19,    22,    24,    25,    26,    27,
      46,    46,    46,    42,    44,     6,     7,     8,     3,     5,
      11,    18,     3,     5,    11,    18,    20,    20,    20,    19,
      19,    17,     3,     5,    11,    17,    18,    42,    37,    19,
      19,    42,    44,    48,    48,    48,    17,    46,    19,    19
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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
        case 6:

/* Line 1455 of yacc.c  */
#line 87 "yacc_spec.y"
    {encode("import\n");}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 98 "yacc_spec.y"
    {
  built_in();encode("function main\n");
}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 119 "yacc_spec.y"
    {
  getsim((yyvsp[(4) - (4)].ival))->stype=(yyvsp[(4) - (4)].ival);
}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 125 "yacc_spec.y"
    {
  (yyval.ival)=(yyvsp[(2) - (4)].sval);    //index of func name simbol
  //generar #header si es necesario
  encode("function %s\n",getsim((yyvsp[(2) - (4)].sval))->name);
}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 133 "yacc_spec.y"
    {
  (yyval.ival)=(yyvsp[(2) - (5)].sval);    //index of func name simbol
  getsim((yyvsp[(2) - (5)].sval))->ival=(yyvsp[(4) - (5)].ival); //num of params
  encode("function %s\n",getsim((yyvsp[(2) - (5)].sval))->name);
  while ((sim_i=pull_sim())>=0)
    {
      encode ("pop %s\n",getsim(sim_i)->name);
    }
}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 146 "yacc_spec.y"
    {
  (yyval.ival)=1;
  push_sim((yyvsp[(1) - (1)].sval));
  getsim((yyvsp[(1) - (1)].sval))->stype=S_PARAM;
}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 153 "yacc_spec.y"
    {
  (yyval.ival)=1+(yyvsp[(3) - (3)].ival);
  push_sim((yyvsp[(1) - (3)].sval));
  getsim((yyvsp[(1) - (3)].sval))->stype=S_PARAM;
}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 162 "yacc_spec.y"
    {
  encode("return sim %s\n",getsim((yyvsp[(2) - (3)].ival))->name); 
  (yyval.ival)=getsim((yyvsp[(2) - (3)].ival))->stype;
}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 168 "yacc_spec.y"
    { error("Return without a value or simbol");}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 172 "yacc_spec.y"
    { 
  encode("return const 0\n");
  (yyval.ival)=S_NULL;
}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 206 "yacc_spec.y"
    {
  getsim((yyvsp[(1) - (3)].sval))->stype=(yyvsp[(3) - (3)].ival);
  encode("pop %s\n",getsim((yyvsp[(1) - (3)].sval))->name);
}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 212 "yacc_spec.y"
    {
  getsim((yyvsp[(1) - (3)].sval))->stype=S_BOOLEAN;
  encode("pop %s\n",getsim((yyvsp[(1) - (3)].sval))->name);
}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 220 "yacc_spec.y"
    {
  if (!cmptypes((yyvsp[(1) - (2)].ival),getsim((yyvsp[(2) - (2)].sval))->stype))
    error("Type error");
  (yyval.ival)=(yyvsp[(1) - (2)].ival);
  encode("push sim %s\n",getsim((yyvsp[(2) - (2)].sval))->name);
  dumpcode();               //codigo apilado desde EXP2
}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 229 "yacc_spec.y"
    {  
  if (!cmptypes((yyvsp[(1) - (2)].ival),S_INT))
    error("Type error. Integer expected");
  (yyval.ival)=S_INT;
  encode("push const %d\n",(yyvsp[(2) - (2)].ival));
  dumpcode();               //codigo apilado desde EXP2
}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 239 "yacc_spec.y"
    {
  if (!cmptypes((yyvsp[(1) - (2)].ival),S_STRING))
    error("Type error. String expected");
  (yyval.ival)=S_STRING;
  encode("push const %s\n",(yyvsp[(2) - (2)].literal));
  dumpcode();               //codigo apilado desde EXP2
}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 248 "yacc_spec.y"
    {
  //1if (getsim($1)->stype==S_NULL)
  //  error("a id must be incializated before using it");
  (yyval.ival)=getsim((yyvsp[(1) - (1)].sval))->stype;
  encode("push sim %s\n",getsim((yyvsp[(1) - (1)].sval))->name);
}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 256 "yacc_spec.y"
    { 
  (yyval.ival)=S_INT;
  getsim((yyvsp[(1) - (1)].ival))->stype=S_INT;
  encode("push const %d\n",(yyvsp[(1) - (1)].ival));
}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 264 "yacc_spec.y"
    {
  (yyval.ival)=S_STRING;
  encode("push const %s\n",(yyvsp[(1) - (1)].literal)); 
}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 270 "yacc_spec.y"
    {
  (yyval.ival)=S_PARAM;
}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 276 "yacc_spec.y"
    {
  (yyval.ival)=(yyvsp[(2) - (3)].ival);

}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 282 "yacc_spec.y"
    {
  (yyval.ival)=(yyvsp[(3) - (4)].ival);
}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 293 "yacc_spec.y"
    {
  if (cmptypes((yyvsp[(1) - (2)].ival),S_STRING))
    error("Operation not allowed with strings");
  else
    pushcode("sub\n");
  (yyval.ival)=(yyvsp[(1) - (2)].ival);
}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 302 "yacc_spec.y"
    {
  if (cmptypes((yyvsp[(1) - (2)].ival),S_STRING))
    error("Operation not allowed with strings");
  else
    pushcode("mul\n");
  (yyval.ival)=(yyvsp[(1) - (2)].ival);
}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 311 "yacc_spec.y"
    {
  pushcode("add\n");
  (yyval.ival)=(yyvsp[(1) - (2)].ival);
}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 324 "yacc_spec.y"
    {
  encode("push sim %s\n",getsim((yyvsp[(2) - (2)].sval))->name);
  dumpcode();
}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 330 "yacc_spec.y"
    {
  encode("push const %d\n",(yyvsp[(2) - (2)].ival));
  dumpcode();
}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 336 "yacc_spec.y"
    {
  encode("push const %s\n",(yyvsp[(2) - (2)].literal));
  dumpcode();
}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 346 "yacc_spec.y"
    {
  pushcode("push sim %s\n",getsim((yyvsp[(1) - (2)].sval))->name);
}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 351 "yacc_spec.y"
    {
  pushcode("push const %d\n",(yyvsp[(1) - (2)].ival));
}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 356 "yacc_spec.y"
    {
  pushcode("push const %s\n",(yyvsp[(1) - (2)].literal));
}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 361 "yacc_spec.y"
    {
}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 367 "yacc_spec.y"
    {
  pushcode("eq\n");
}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 372 "yacc_spec.y"
    {
  pushcode("and\n");
}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 377 "yacc_spec.y"
    {
  pushcode("or\n");
}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 382 "yacc_spec.y"
    {
  pushcode("gt\n");
}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 387 "yacc_spec.y"
    {
  pushcode("lt\n");
}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 405 "yacc_spec.y"
    {
  if (getsim((yyvsp[(1) - (4)].sval))->ival != (yyvsp[(3) - (4)].ival))
    error("Wrong parametres number in call");
  encode("call %s\n",getsim((yyvsp[(1) - (4)].sval))->name);   
}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 412 "yacc_spec.y"
    {
  encode("call %s\n",getsim((yyvsp[(1) - (3)].sval))->name); 
}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 419 "yacc_spec.y"
    {
  (yyval.ival)=1; 
  encode("push sim %s\n",getsim((yyvsp[(1) - (1)].sval))->name); 
}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 425 "yacc_spec.y"
    {
  (yyval.ival)=1+(yyvsp[(3) - (3)].ival); 
  encode("push sim %s\n",getsim((yyvsp[(1) - (3)].sval))->name); 
}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 431 "yacc_spec.y"
    {
  (yyval.ival)=1; 
  encode("push const %d\n",(yyvsp[(1) - (1)].ival)); 
}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 437 "yacc_spec.y"
    {
  (yyval.ival)=1+(yyvsp[(3) - (3)].ival); 
  encode("push const %d\n",(yyvsp[(1) - (3)].ival)); 
}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 443 "yacc_spec.y"
    {
  (yyval.ival)=1; 
  encode("push const %s\n",(yyvsp[(1) - (1)].literal)); 
}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 449 "yacc_spec.y"
    {
  (yyval.ival)=1+(yyvsp[(3) - (3)].ival); 
  encode("push const %s\n",(yyvsp[(1) - (3)].literal)); 
}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 462 "yacc_spec.y"
    {
  encode ("label %s\n",getsim((yyvsp[(1) - (4)].ival))->name);
}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 468 "yacc_spec.y"
    {
  /* 
     we create the if label to jump it and we add
     the label to the simtable
  */

  char iflabel[15];   
  sprintf(iflabel,"fi-%d",yylineno);
  int li=addsim(iflabel);
  encode ("goto-ifz %s\n",getsim(li)->name);
  (yyval.ival)=li;
}
    break;



/* Line 1455 of yacc.c  */
#line 1976 "y.tab.c"
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
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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



/* Line 1675 of yacc.c  */
#line 484 "yacc_spec.y"
 


