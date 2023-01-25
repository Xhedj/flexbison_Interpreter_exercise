
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
#line 1 "test.y"

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define YYDEBUG 1

extern int yylex();
int yyerror(const char *s);

const char INT_TYPE = 1;
const char FLOAT_TYPE = 2;
const char STRING_TYPE = 3;

struct variable summation(struct variable n1, struct variable n2);
struct variable subtraction(struct variable n1, struct variable n2);
struct variable multiplication(struct variable n1, struct variable n2);
struct variable division(struct variable n1, struct variable n2);
struct variable negativeNumb(struct variable);

bool greaterValue(struct variable, struct variable);
bool smallerValue(struct variable, struct variable);
bool equality(struct variable, struct variable);
bool inequality(struct variable, struct variable);
bool greaterEqual(struct variable, struct variable);
bool smallerEqual(struct variable, struct variable);

struct variable increment(struct variable);
struct variable decrement(struct variable);

void print_value(struct variable var);
void print_boolExpr(_Bool result);
char* varType(struct variable data);

struct symbolTable *head = (struct symbolTable *)0;
struct symbolTable *node = (struct symbolTable *)0;
struct symbolTable *symlook(char *str);
void setHead(struct symbolTable *node);
struct symbolTable *addNode(char *str, struct symbolTable *node);
const int max_symbols = 10;
int counter = 0;



/* Line 189 of yacc.c  */
#line 119 "test.tab.c"

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

/* "%code requires" blocks.  */

/* Line 209 of yacc.c  */
#line 45 "test.y"

	struct variable{
    union{
        int intval;
        float floatval;
        char *strings;

    };
    char fromID;
    char type;
};

    struct symbolTable{
        char *id;
        char declared;
        char initialized;
        struct symbolTable *next;
        struct variable value;
    };



/* Line 209 of yacc.c  */
#line 166 "test.tab.c"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     STRING = 258,
     INTEGERV = 259,
     FLOATV = 260,
     INTEGER = 261,
     FLOAT = 262,
     WORD = 263,
     TYPE = 264,
     BADGE = 265,
     IF = 266,
     FL = 267,
     FOR = 268,
     WHILE = 269,
     OTHER = 270,
     EXIT = 271,
     SEMICOLON = 272,
     EOL = 273,
     COMPARISON = 274,
     NEGATION = 275,
     GREATEREQUAL = 276,
     LESSEQUAL = 277,
     DEC = 278,
     INC = 279,
     MINUS = 280
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 66 "test.y"

		char* name;
        char* varname;
        char* types;
		float floatv;
		int integerv;
        _Bool cond;
		struct variable variabile;



/* Line 214 of yacc.c  */
#line 220 "test.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 232 "test.tab.c"

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
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   84

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  8
/* YYNRULES -- Number of rules.  */
#define YYNRULES  37
/* YYNRULES -- Number of states.  */
#define YYNSTATES  70

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   280

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      28,    29,    32,    30,     2,    31,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      19,    21,    20,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    22,    23,    24,    25,    26,    27,
      34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     8,    12,    16,    20,    24,    29,
      34,    37,    40,    42,    46,    50,    54,    58,    61,    64,
      67,    71,    73,    75,    77,    81,    85,    89,    93,    97,
     101,   106,   111,   116,   121,   125,   129,   131
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      36,     0,    -1,    37,    36,    -1,    37,    -1,    38,    17,
      18,    -1,    39,    17,    18,    -1,    40,    17,    18,    -1,
      41,    17,    18,    -1,    42,    10,    17,    18,    -1,     8,
      10,    17,    18,    -1,     8,     4,    -1,     8,     5,    -1,
      16,    -1,    38,    32,    38,    -1,    38,    30,    38,    -1,
      38,    31,    38,    -1,    38,    33,    38,    -1,    38,    27,
      -1,    38,    26,    -1,    31,    38,    -1,    28,    38,    29,
      -1,     4,    -1,     5,    -1,     3,    -1,    38,    20,    38,
      -1,    38,    19,    38,    -1,    38,    22,    38,    -1,    38,
      23,    38,    -1,    38,    24,    38,    -1,    38,    25,    38,
      -1,    42,    10,    21,    38,    -1,    42,    10,    21,    39,
      -1,     8,    10,    21,    39,    -1,     8,    10,    21,    38,
      -1,    10,    21,    38,    -1,    10,    21,    39,    -1,     7,
      -1,     6,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   119,   119,   119,   121,   122,   123,   124,   125,   145,
     157,   160,   163,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   178,   181,   182,   183,   184,   185,   186,
     190,   233,   243,   258,   267,   307,   327,   328
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING", "INTEGERV", "FLOATV",
  "INTEGER", "FLOAT", "WORD", "TYPE", "BADGE", "IF", "FL", "FOR", "WHILE",
  "OTHER", "EXIT", "SEMICOLON", "EOL", "'<'", "'>'", "'='", "COMPARISON",
  "NEGATION", "GREATEREQUAL", "LESSEQUAL", "DEC", "INC", "'('", "')'",
  "'+'", "'-'", "'*'", "'/'", "MINUS", "$accept", "input", "line",
  "expression", "stringa", "cond_expression", "assign", "variabletype", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,    60,
      62,    61,   274,   275,   276,   277,   278,   279,    40,    41,
      43,    45,    42,    47,   280
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    36,    37,    37,    37,    37,    37,    37,
      37,    37,    37,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    39,    40,    40,    40,    40,    40,    40,
      41,    41,    41,    41,    41,    41,    42,    42
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     3,     3,     3,     3,     4,     4,
       2,     2,     1,     3,     3,     3,     3,     2,     2,     2,
       3,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       4,     4,     4,     4,     3,     3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    23,    21,    22,    37,    36,     0,     0,    12,     0,
       0,     0,     3,     0,     0,     0,     0,     0,    10,    11,
       0,     0,     0,    19,     1,     2,     0,     0,     0,     0,
       0,     0,     0,    18,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    34,    35,    20,     4,    25,
      24,    26,    27,    28,    29,    14,    15,    13,    16,     5,
       6,     7,     0,     0,     9,    33,    32,     8,    30,    31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    11,    12,    13,    14,    15,    16,    17
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -20
static const yytype_int8 yypact[] =
{
      33,   -20,   -20,   -20,   -20,   -20,    -1,   -13,   -20,    27,
      27,    34,    33,    43,     7,    25,    28,    38,   -20,   -20,
      60,     2,   -16,   -20,   -20,   -20,    41,    27,    27,    27,
      27,    27,    27,   -20,   -20,    27,    27,    27,    27,    53,
      54,    62,    61,    65,     2,    20,   -20,   -20,   -20,    20,
      20,    20,    20,    20,    20,    24,    24,   -20,   -20,   -20,
     -20,   -20,    66,     2,   -20,    20,   -20,   -20,    20,   -20
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -20,    67,   -20,    -9,   -19,   -20,   -20,   -20
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      22,    23,    46,    18,    19,     1,     2,     3,    21,    20,
      33,    34,    45,    47,    35,    36,    37,    38,    49,    50,
      51,    52,    53,    54,    39,    66,    55,    56,    57,    58,
       9,     2,     3,    10,    24,    65,     1,     2,     3,     4,
       5,     6,    40,     7,    69,    41,    33,    34,    42,     8,
      35,    36,    37,    38,    68,     9,    37,    38,    10,    48,
      26,     9,    27,    28,    10,    29,    30,    31,    32,    33,
      34,    59,    60,    35,    36,    37,    38,    43,    62,    25,
      61,    44,    63,    64,    67
};

static const yytype_uint8 yycheck[] =
{
       9,    10,    21,     4,     5,     3,     4,     5,    21,    10,
      26,    27,    21,    29,    30,    31,    32,    33,    27,    28,
      29,    30,    31,    32,    17,    44,    35,    36,    37,    38,
      28,     4,     5,    31,     0,    44,     3,     4,     5,     6,
       7,     8,    17,    10,    63,    17,    26,    27,    10,    16,
      30,    31,    32,    33,    63,    28,    32,    33,    31,    18,
      17,    28,    19,    20,    31,    22,    23,    24,    25,    26,
      27,    18,    18,    30,    31,    32,    33,    17,    17,    12,
      18,    21,    21,    18,    18
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    10,    16,    28,
      31,    36,    37,    38,    39,    40,    41,    42,     4,     5,
      10,    21,    38,    38,     0,    36,    17,    19,    20,    22,
      23,    24,    25,    26,    27,    30,    31,    32,    33,    17,
      17,    17,    10,    17,    21,    38,    39,    29,    18,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    18,
      18,    18,    17,    21,    18,    38,    39,    18,    38,    39
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
        case 4:

/* Line 1455 of yacc.c  */
#line 121 "test.y"
    { print_value((yyvsp[(1) - (3)].variabile)); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 122 "test.y"
    { print_value((yyvsp[(1) - (3)].variabile)); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 123 "test.y"
    { print_boolExpr((yyvsp[(1) - (3)].cond)); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 124 "test.y"
    { ; ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 125 "test.y"
    {
            struct symbolTable *pointer = symlook((yyvsp[(2) - (4)].varname));
            if(!pointer->initialized){
                pointer->initialized = 1;

                if((yyvsp[(1) - (4)].types) == "integer"){
                    pointer->value.type = INT_TYPE;
                    printf(" A variable of type integer has been declared with Identifier: '%s'\n",(yyvsp[(2) - (4)].varname));
                }
                    

                else if((yyvsp[(1) - (4)].types) == "float"){
                    pointer->value.type = FLOAT_TYPE;
                    printf(" A variable of type float has been declared with Identifier: '%s'\n",(yyvsp[(2) - (4)].varname));
                }
            } 
            else {
                printf("--ERROR--\nVariable '%s' already defined\n",(yyvsp[(2) - (4)].varname));
            }
        ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 145 "test.y"
    {
            struct symbolTable *pointer = symlook((yyvsp[(2) - (4)].varname)); 
            if(!pointer->initialized)
            {
                pointer->initialized = 1; 
                pointer->value.type = STRING_TYPE; 
                pointer->value.strings = "null";
                printf(" A variable string has been declared with Identifier: '%s'\n",(yyvsp[(2) - (4)].varname));
            } else {
                printf("--ERROR--\nVariable '%s' already defined\n",(yyvsp[(2) - (4)].varname));
            }
        ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 157 "test.y"
    {
            printf("--ERROR!!--\n Illegal variable declaration! A legal variable declaration must start with a letter and not an Integer \n");
            ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 160 "test.y"
    {
            printf("--ERROR!!--\n Illegal variable declaration! A legal variable declaration must start with a letter and not a Float \n");
        ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 163 "test.y"
    {exit(0); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 166 "test.y"
    {(yyval.variabile) = multiplication((yyvsp[(1) - (3)].variabile),(yyvsp[(3) - (3)].variabile)); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 167 "test.y"
    {(yyval.variabile) = summation((yyvsp[(1) - (3)].variabile),(yyvsp[(3) - (3)].variabile)); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 168 "test.y"
    {(yyval.variabile) = subtraction((yyvsp[(1) - (3)].variabile),(yyvsp[(3) - (3)].variabile)); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 169 "test.y"
    {(yyval.variabile) = division((yyvsp[(1) - (3)].variabile),(yyvsp[(3) - (3)].variabile)); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 170 "test.y"
    {(yyval.variabile) = increment((yyvsp[(1) - (2)].variabile));;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 171 "test.y"
    {(yyval.variabile) = decrement((yyvsp[(1) - (2)].variabile));;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 172 "test.y"
    {(yyval.variabile) = negativeNumb((yyvsp[(2) - (2)].variabile));;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 173 "test.y"
    {(yyval.variabile) = (yyvsp[(2) - (3)].variabile);;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 174 "test.y"
    {{struct variable data; data.type = INT_TYPE; data.fromID=0; data.intval = (yyvsp[(1) - (1)].integerv); (yyval.variabile) = data; };}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 175 "test.y"
    {{struct variable data; data.type = FLOAT_TYPE; data.fromID=0; data.floatval = (yyvsp[(1) - (1)].floatv); (yyval.variabile) = data; };}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 178 "test.y"
    {struct variable data; data.type = STRING_TYPE; data.strings = ++(yyvsp[(1) - (1)].name); data.strings[strlen(data.strings)-1] = '\0'; (yyval.variabile) = data; ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 181 "test.y"
    {(yyval.cond) = greaterValue((yyvsp[(1) - (3)].variabile),(yyvsp[(3) - (3)].variabile)); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 182 "test.y"
    {(yyval.cond) = smallerValue((yyvsp[(1) - (3)].variabile),(yyvsp[(3) - (3)].variabile)); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 183 "test.y"
    {(yyval.cond) = equality((yyvsp[(1) - (3)].variabile),(yyvsp[(3) - (3)].variabile));;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 184 "test.y"
    {(yyval.cond) = inequality((yyvsp[(1) - (3)].variabile),(yyvsp[(3) - (3)].variabile));;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 185 "test.y"
    {(yyval.cond) = greaterEqual((yyvsp[(1) - (3)].variabile),(yyvsp[(3) - (3)].variabile));;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 186 "test.y"
    {(yyval.cond) = smallerEqual((yyvsp[(1) - (3)].variabile),(yyvsp[(3) - (3)].variabile));;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 190 "test.y"
    {
                    struct symbolTable *pointer = symlook((yyvsp[(2) - (4)].varname));
                    if(pointer->initialized){
				        printf("--ERROR!!--\n Variable %s already defined \n",(yyvsp[(2) - (4)].varname));
				    }
			        else {
                            if((yyvsp[(1) - (4)].types) == "float"){
                                if((yyvsp[(4) - (4)].variabile).type == INT_TYPE||(yyvsp[(4) - (4)].variabile).type == FLOAT_TYPE){
                                pointer->value.type = FLOAT_TYPE;
                                pointer->initialized=1;	
                                pointer->declared=1;
                                
                                if((yyvsp[(4) - (4)].variabile).type == INT_TYPE){
                                    pointer->value.floatval = (yyvsp[(4) - (4)].variabile).intval;
                                } else {
                                    pointer->value.floatval = (yyvsp[(4) - (4)].variabile).floatval;
                                }
                                printf(" Variable defined as: '%s' and",(yyvsp[(2) - (4)].varname));
                                printf(" has value %f\n",pointer->value.floatval);

                        } else 
                            fprintf(stderr, "--ERROR!!--\n Cannot assign %s to FLOAT type \n",varType((yyvsp[(4) - (4)].variabile))); 

                        } else if((yyvsp[(1) - (4)].types) == "integer") {
							
						if(!((yyvsp[(4) - (4)].variabile).type == INT_TYPE))
							fprintf(stderr, "--ERROR!!--\n Cannot assign %s to INTEGER type \n",varType((yyvsp[(4) - (4)].variabile)));
								
						else {
                                pointer->value.type = INT_TYPE;
                                pointer->initialized = 1;
                                pointer->declared=1;
                                pointer->value.intval=(yyvsp[(4) - (4)].variabile).intval;
                                printf(" Variable defined as '%s' and",(yyvsp[(2) - (4)].varname));
                                printf(" has value %i\n",pointer->value.intval);
						    }
                        }  
                        else {
                        fprintf(stderr, "--ERROR!!--\n The type inserted: %s, is not recognized \n",(yyvsp[(1) - (4)].types));
                        }
                    }
                ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 233 "test.y"
    {
                    struct symbolTable* pointer = symlook((yyvsp[(2) - (4)].varname));
                    if(pointer->initialized){
                        printf("Variable already defined\n");
                        }
                    else{
                        fprintf(stderr, "--ERROR!!--\n Impossible to assign string to the type: %s \n",(yyvsp[(1) - (4)].types));
                        }
                ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 243 "test.y"
    {
                    struct symbolTable* pointer = symlook((yyvsp[(2) - (4)].varname));
                    if(pointer->initialized){
                        printf("--ERROR!!--\n The variable: '%s', has been already defined \n",(yyvsp[(2) - (4)].varname));
                    }			
                    else {
                        pointer->value.type = STRING_TYPE;
                        pointer->initialized=1;
                        pointer->declared=1;
                        pointer->value.strings=strdup((yyvsp[(4) - (4)].variabile).strings);
                        printf(" Variable defined as '%s' and",(yyvsp[(2) - (4)].varname));
                        printf(" has value: %s \n", pointer->value.strings);
                        }
                ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 258 "test.y"
    {
                    struct symbolTable* pointer = symlook((yyvsp[(2) - (4)].varname)); 
                    if(pointer->initialized){
                        printf("--ERROR!!--\n The variable: '%s', has been already defined \n",(yyvsp[(2) - (4)].varname));
                    }else{
                        printf("--ERROR!!--\n Cannot assign an expression to a string!! \n");
                    }
                ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 267 "test.y"
    {
                    struct symbolTable* pointer1 = symlook((yyvsp[(1) - (3)].varname));
                    if(pointer1->initialized){
                        char type1 = pointer1->value.type;
                        char type2 = (yyvsp[(3) - (3)].variabile).type; 
                        if (type2 == 0){
                                print_value((yyvsp[(3) - (3)].variabile));
                        }else{
                            if(type1 == 2){
                                if(type2 == 1){
                                    pointer1->value.floatval=(yyvsp[(3) - (3)].variabile).intval;
                                    pointer1->declared=1;
                                    printf(" Assigned integer value to float variable: '%d'\n",(yyvsp[(3) - (3)].variabile).intval);

                                } else if(type2 == 2){
                                    pointer1->value.floatval=(yyvsp[(3) - (3)].variabile).floatval;
                                    pointer1->declared=1;
                                    printf(" Assigned float value to float variable: '%f'\n",(yyvsp[(3) - (3)].variabile).floatval);
                                } else {
                                    fprintf(stderr, "--ERROR!!--\n Cannot assign: %s to %s type \n",varType((yyvsp[(3) - (3)].variabile)),varType(pointer1->value));
                                    }
                            } else {
                                if(type1 == type2) {
                                    if(type1 == 1){
                                        pointer1->value.intval=(yyvsp[(3) - (3)].variabile).intval;
                                        printf(" Assigned integer value to integer variable: '%d'\n",(yyvsp[(3) - (3)].variabile).intval);
                                    } else {
                                    pointer1->value.strings=(yyvsp[(3) - (3)].variabile).strings;
                                    printf(" Assigned a string to a string variable: '%s'\n",(yyvsp[(3) - (3)].variabile).strings);
                                    }
                                    pointer1->declared=1;
                                } else {
                                    fprintf(stderr, "--ERROR!!--\n Cannot assign: %s to %s type\n",varType((yyvsp[(3) - (3)].variabile)),varType(pointer1->value));}
                            }
                        }
                    } else {
                        printf("--ERROR!!--\n The variable '%s' is not defined\n",(yyvsp[(1) - (3)].varname));
                    }
                ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 307 "test.y"
    {
                    struct symbolTable* pointer = symlook((yyvsp[(1) - (3)].varname)); 

					if(pointer->initialized){

                        if(pointer->value.type != STRING_TYPE){
                            fprintf(stderr, "--ERROR!!--\n A string cannot be assigned to type: %s \n",varType(pointer->value));
                        } else {
                            pointer->value.strings=strdup((yyvsp[(3) - (3)].variabile).strings);
                            printf(" Currently defined variable has ID: %s and", (yyvsp[(1) - (3)].varname));
                            printf(" has value: %s \n", pointer->value.strings);
                            pointer->declared=1;
                        
                        }

					} else {printf("--ERROR!!--\n Variable '%s' is not defined \n",(yyvsp[(1) - (3)].varname));}
                ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 327 "test.y"
    {(yyval.types) = "float";;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 328 "test.y"
    {(yyval.types) = "integer";;}
    break;



/* Line 1455 of yacc.c  */
#line 1873 "test.tab.c"
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
#line 334 "test.y"

// Sum of two variables
struct variable summation(struct variable n1, struct variable n2){
    struct variable result;

    if (n1.type == STRING_TYPE && n2.type == STRING_TYPE){
        result.strings = n1.strings;
        strcat(result.strings, n2.strings);
        result.type = STRING_TYPE;
    }
    else if (n1.type == INT_TYPE && n2.type == INT_TYPE){
        result.intval = n1.intval + n2.intval;
        result.type = INT_TYPE;
    }
    else if (n1.type == INT_TYPE && n2.type == FLOAT_TYPE){
        result.floatval = n1.intval + n2.floatval;
        result.type = FLOAT_TYPE;
    }
    else if (n1.type == FLOAT_TYPE && n2.type == INT_TYPE){
        result.floatval = n1.floatval + n2.intval;
        result.type = FLOAT_TYPE;
    }
    else if (n1.type == FLOAT_TYPE && n2.type == FLOAT_TYPE){
        result.floatval = n1.floatval + n2.floatval;
        result.type = FLOAT_TYPE;
    }
    else{
        result.type = 9; // ERROR TYPE
    }

    return result;
}

// Subtraction between variables
struct variable subtraction(struct variable n1, struct variable n2){
    struct variable result;

    if (n1.type == INT_TYPE && n2.type == INT_TYPE){
        result.intval = n1.intval - n2.intval;
        result.type = INT_TYPE;
    }
    else if (n1.type == INT_TYPE && n2.type == FLOAT_TYPE){
        result.floatval = n1.intval - n2.floatval;
        result.type = FLOAT_TYPE;
    }
    else if (n1.type == FLOAT_TYPE && n2.type == INT_TYPE){
        result.floatval = n1.floatval - n2.intval;
        result.type = FLOAT_TYPE;
    }
    else{
        result.floatval = n1.floatval - n2.floatval;
        result.type = FLOAT_TYPE;
    }

    return result;
}

// Multiplication of two variables
struct variable multiplication(struct variable n1, struct variable n2){

    struct variable result;

    if (n1.type == INT_TYPE && n2.type == INT_TYPE){
        result.intval = n1.intval * n2.intval;
        result.type = INT_TYPE;
    }
    else if (n1.type == INT_TYPE && n2.type == FLOAT_TYPE){
        result.floatval = n1.intval * n2.floatval;
        result.type = FLOAT_TYPE;
    }
    else if (n1.type == FLOAT_TYPE && n2.type == INT_TYPE){
        result.floatval = n1.floatval * n2.intval;
        result.type = FLOAT_TYPE;
    }
    else{
        result.floatval = n1.floatval * n2.floatval;
        result.type = FLOAT_TYPE;
    }

    return result;
}

// Division of two variables
struct variable division(struct variable n1, struct variable n2){

    struct variable result;
    if(n2.floatval == 0.0 || n2.intval == 0){
        printf("cannot divide by 0");
        exit(0);
    }
    else if (n1.type == INT_TYPE && n2.type == INT_TYPE){
        result.intval = n1.intval / n2.intval;
        result.type = INT_TYPE;
    }
    else if (n1.type == INT_TYPE && n2.type == FLOAT_TYPE){
        result.floatval = n1.intval / n2.floatval;
        result.type = FLOAT_TYPE;
    }
    else if (n1.type == FLOAT_TYPE && n2.type == INT_TYPE){
        result.floatval = n1.floatval / n2.intval;
        result.type = FLOAT_TYPE;
    }
    else{
        result.floatval = n1.floatval / n2.floatval;
        result.type = FLOAT_TYPE;
    }

    return result;
}

struct variable negativeNumb(struct variable n1){
    struct variable result;
    if (n1.type == INT_TYPE){
        result.type = INT_TYPE;
        result.intval = -n1.intval;
    }
    else{
        result.type = FLOAT_TYPE;
        result.floatval = -n1.floatval;
    }
    return result;
}


/* Function for printing the data value */
void print_value(struct variable var){
    if (var.type == INT_TYPE){
        printf("Integer Result: %i \n", var.intval);
    }
    else if (var.type == FLOAT_TYPE){
        printf("Float Result: %f \n", var.floatval);
    }
    else if (var.type == STRING_TYPE){
        printf("String: %s \n", var.strings);
    }
    else{
        printf("variable is not defined\n");
    }
}

char* varType(struct variable data){ // returns type of data

	char* type;

	switch(data.type) {
	
		case 1:
			type="int";
			break;
		case 2:
			type="float";
			break;
		case 3:
			type="string";
			break; 
		case 0:
			type="none";
			break;
	}
	
	return type;
}

_Bool equality(struct variable n1, struct variable n2){
    _Bool prov;
    if (n1.type == INT_TYPE && n2.type == INT_TYPE){
        if (n1.intval == n2.intval){
            prov = true;
        }
    }
    else if (n1.type == FLOAT_TYPE && n2.type == FLOAT_TYPE){
        if (n1.floatval == n2.floatval){
            prov = true;
        }
    }
    else if (n1.type == FLOAT_TYPE && n2.type == INT_TYPE){
        if (n1.floatval == n2.intval){
            prov = true;
        }
    }
    else if (n1.type == INT_TYPE && n2.type == FLOAT_TYPE){
        if (n1.intval == n2.floatval){
            prov = true;
        }
    }
    else{
        prov = false;
    }
    return prov;
}

_Bool greaterValue(struct variable n1, struct variable n2){
    _Bool prov;
    if (n1.type == INT_TYPE && n2.type == INT_TYPE){
        if (n1.intval > n2.intval){
            prov = true;
        }
    }
    else if (n1.type == FLOAT_TYPE && n2.type == FLOAT_TYPE){
        if (n1.floatval > n2.floatval){
            prov = true;
        }
    }
    else if (n1.type == FLOAT_TYPE && n2.type == INT_TYPE){
        if (n1.floatval > n2.intval){
            prov = true;
        }
    }
    else if (n1.type == INT_TYPE && n2.type == FLOAT_TYPE){
        if (n1.intval > n2.floatval){
            prov = true;
        }
    }
    else{
        prov = false;
    }
    return prov;
}

_Bool inequality(struct variable n1, struct variable n2){
    return !equality(n1, n2);
}

_Bool smallerValue(struct variable n1, struct variable n2){
    return (!greaterValue(n1, n2) && !equality(n1, n2));
}

_Bool greaterEqual(struct variable n1, struct variable n2){
    return greaterValue(n1, n2) || equality(n1, n2);
}

_Bool smallerEqual(struct variable n1, struct variable n2){
    return smallerValue(n1, n2) || equality(n1, n2);
}

struct variable increment(struct variable n1){
    struct variable result;
    if (n1.type == INT_TYPE){
        result.type = INT_TYPE;
        result.intval = n1.intval + 1;
    }
    else{
        result.type = FLOAT_TYPE;
        result.floatval = n1.floatval + 1;
    }
    return result;
}

struct variable decrement(struct variable n1){
    struct variable result;
    if (n1.type == INT_TYPE){
        result.type = INT_TYPE;
        result.intval = n1.intval - 1;
    }
    else{
        result.type = FLOAT_TYPE;
        result.floatval = n1.floatval - 1;
    }
    return result;
}

void print_boolExpr(_Bool result){
    printf("Conditional result: %s\n", result ? "true" : "false");
}

struct symbolTable *addNode(char *str, struct symbolTable *iter){

    struct symbolTable *node = (struct symbolTable *)malloc(sizeof(struct symbolTable));
    node->id = strdup(str);
    node->next = NULL;

    iter->next = node;

    counter++;

    return node;
}

struct symbolTable *symlook(char *str){

    if (head == NULL) {
        head = (struct symbolTable *)malloc(sizeof(struct symbolTable));
        head->id = strdup(str);
        head->next = NULL;
        counter++;
        return head;
    }

    else {

        struct symbolTable *iter = (struct symbolTable *)malloc(sizeof(struct symbolTable));
        iter = head;

        while (iter->next != NULL){ // iterate over list
            /* strcmp checks if WHOLE string is equal starting from pointer to it*/

            if (iter->id && !strcmp(iter->id, str)){ /* return pointer */
                return iter;
            }
            iter = iter->next;
        }

        if (iter->id && !strcmp(iter->id, str)){ /* return pointer */
            return iter;
        }

        if (counter < max_symbols){ // if the variable was not found and there is still space in the ST
            struct symbolTable *added = addNode(str, iter);
            return added;
        }

	exit(1);

    }
}




int yyerror(const char *s)
{
	return fprintf (stderr, "%s\n", s);
	fputs (s, stderr);
	fputc ('\n', stderr);
	return 0;
}

int main()
{

    yyparse();
    return 0;
}

