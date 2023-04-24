/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 4 "parser.y"

    /*To enable yacc debugging (tracing the grammar rules) set the ENABLE_YACC_DEBUG flag to 1 (default: 0)*/
    #define ENABLE_YACC_DEBUG 0

    /*To enable lex debugging (tracing the token rules) set the ENABLE_LEX_DEBUG flag to 1 (default: 0)*/
    #define ENABLE_LEX_DEBUG 0
#line 12 "parser.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    extern FILE *yyin;
    extern FILE *yyout;
    extern int yyleng;
    extern int yy_flex_debug;
    int yydebug;
    extern int yylex(void);
    int yyerror(const char* s);

#line 91 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INTEGER = 258,                 /* INTEGER  */
    FLOAT = 259,                   /* FLOAT  */
    BOOL = 260,                    /* BOOL  */
    CHAR = 261,                    /* CHAR  */
    TYPE_INT = 262,                /* TYPE_INT  */
    TYPE_FLOAT = 263,              /* TYPE_FLOAT  */
    TYPE_CHAR = 264,               /* TYPE_CHAR  */
    TYPE_BOOL = 265,               /* TYPE_BOOL  */
    TYPE_VOID = 266,               /* TYPE_VOID  */
    CONSTANT = 267,                /* CONSTANT  */
    ENUM = 268,                    /* ENUM  */
    WHILE = 269,                   /* WHILE  */
    FOR = 270,                     /* FOR  */
    BREAK = 271,                   /* BREAK  */
    CONTINUE = 272,                /* CONTINUE  */
    IF = 273,                      /* IF  */
    ELSE = 274,                    /* ELSE  */
    ELSEIF = 275,                  /* ELSEIF  */
    SWITCH = 276,                  /* SWITCH  */
    CASE = 277,                    /* CASE  */
    DEFAULT = 278,                 /* DEFAULT  */
    MINUS = 279,                   /* MINUS  */
    MULT = 280,                    /* MULT  */
    PLUS = 281,                    /* PLUS  */
    DIV = 282,                     /* DIV  */
    MODULE = 283,                  /* MODULE  */
    POWER = 284,                   /* POWER  */
    EQU = 285,                     /* EQU  */
    INC = 286,                     /* INC  */
    DEC = 287,                     /* DEC  */
    MORE = 288,                    /* MORE  */
    LESS = 289,                    /* LESS  */
    EQU_EQU = 290,                 /* EQU_EQU  */
    MORE_OR_EQU = 291,             /* MORE_OR_EQU  */
    LESS_OR_EQU = 292,             /* LESS_OR_EQU  */
    NOT_EQU = 293,                 /* NOT_EQU  */
    AND = 294,                     /* AND  */
    OR = 295,                      /* OR  */
    NOT = 296,                     /* NOT  */
    OPEN_CURL = 297,               /* OPEN_CURL  */
    CLOSE_CURL = 298,              /* CLOSE_CURL  */
    OPEN_BRAC = 299,               /* OPEN_BRAC  */
    CLOSE_BRAC = 300,              /* CLOSE_BRAC  */
    SEMICOLON = 301,               /* SEMICOLON  */
    COMMA = 302,                   /* COMMA  */
    COLON = 303,                   /* COLON  */
    REPEAT = 304,                  /* REPEAT  */
    UNTIL = 305,                   /* UNTIL  */
    IDENTIFIER = 306,              /* IDENTIFIER  */
    COMMENT = 307                  /* COMMENT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "parser.y"

    int ivalue;
    float fvalue;
    char cvalue;

#line 196 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTEGER = 3,                    /* INTEGER  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_BOOL = 5,                       /* BOOL  */
  YYSYMBOL_CHAR = 6,                       /* CHAR  */
  YYSYMBOL_TYPE_INT = 7,                   /* TYPE_INT  */
  YYSYMBOL_TYPE_FLOAT = 8,                 /* TYPE_FLOAT  */
  YYSYMBOL_TYPE_CHAR = 9,                  /* TYPE_CHAR  */
  YYSYMBOL_TYPE_BOOL = 10,                 /* TYPE_BOOL  */
  YYSYMBOL_TYPE_VOID = 11,                 /* TYPE_VOID  */
  YYSYMBOL_CONSTANT = 12,                  /* CONSTANT  */
  YYSYMBOL_ENUM = 13,                      /* ENUM  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_FOR = 15,                       /* FOR  */
  YYSYMBOL_BREAK = 16,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 17,                  /* CONTINUE  */
  YYSYMBOL_IF = 18,                        /* IF  */
  YYSYMBOL_ELSE = 19,                      /* ELSE  */
  YYSYMBOL_ELSEIF = 20,                    /* ELSEIF  */
  YYSYMBOL_SWITCH = 21,                    /* SWITCH  */
  YYSYMBOL_CASE = 22,                      /* CASE  */
  YYSYMBOL_DEFAULT = 23,                   /* DEFAULT  */
  YYSYMBOL_MINUS = 24,                     /* MINUS  */
  YYSYMBOL_MULT = 25,                      /* MULT  */
  YYSYMBOL_PLUS = 26,                      /* PLUS  */
  YYSYMBOL_DIV = 27,                       /* DIV  */
  YYSYMBOL_MODULE = 28,                    /* MODULE  */
  YYSYMBOL_POWER = 29,                     /* POWER  */
  YYSYMBOL_EQU = 30,                       /* EQU  */
  YYSYMBOL_INC = 31,                       /* INC  */
  YYSYMBOL_DEC = 32,                       /* DEC  */
  YYSYMBOL_MORE = 33,                      /* MORE  */
  YYSYMBOL_LESS = 34,                      /* LESS  */
  YYSYMBOL_EQU_EQU = 35,                   /* EQU_EQU  */
  YYSYMBOL_MORE_OR_EQU = 36,               /* MORE_OR_EQU  */
  YYSYMBOL_LESS_OR_EQU = 37,               /* LESS_OR_EQU  */
  YYSYMBOL_NOT_EQU = 38,                   /* NOT_EQU  */
  YYSYMBOL_AND = 39,                       /* AND  */
  YYSYMBOL_OR = 40,                        /* OR  */
  YYSYMBOL_NOT = 41,                       /* NOT  */
  YYSYMBOL_OPEN_CURL = 42,                 /* OPEN_CURL  */
  YYSYMBOL_CLOSE_CURL = 43,                /* CLOSE_CURL  */
  YYSYMBOL_OPEN_BRAC = 44,                 /* OPEN_BRAC  */
  YYSYMBOL_CLOSE_BRAC = 45,                /* CLOSE_BRAC  */
  YYSYMBOL_SEMICOLON = 46,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 47,                     /* COMMA  */
  YYSYMBOL_COLON = 48,                     /* COLON  */
  YYSYMBOL_REPEAT = 49,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 50,                     /* UNTIL  */
  YYSYMBOL_IDENTIFIER = 51,                /* IDENTIFIER  */
  YYSYMBOL_COMMENT = 52,                   /* COMMENT  */
  YYSYMBOL_YYACCEPT = 53,                  /* $accept  */
  YYSYMBOL_tokens = 54,                    /* tokens  */
  YYSYMBOL_token = 55,                     /* token  */
  YYSYMBOL_in_scope_statements = 56,       /* in_scope_statements  */
  YYSYMBOL_in_scope_statement = 57,        /* in_scope_statement  */
  YYSYMBOL_in_enum_statement = 58,         /* in_enum_statement  */
  YYSYMBOL_enum_variable_declaration = 59, /* enum_variable_declaration  */
  YYSYMBOL_type = 60,                      /* type  */
  YYSYMBOL_parameter_or_empty = 61,        /* parameter_or_empty  */
  YYSYMBOL_parameters = 62,                /* parameters  */
  YYSYMBOL_argument_or_empty = 63,         /* argument_or_empty  */
  YYSYMBOL_arguments = 64,                 /* arguments  */
  YYSYMBOL_enum_declaration = 65,          /* enum_declaration  */
  YYSYMBOL_function_prototype = 66,        /* function_prototype  */
  YYSYMBOL_function_declaration = 67,      /* function_declaration  */
  YYSYMBOL_variable_declaration = 68,      /* variable_declaration  */
  YYSYMBOL_constant_declaration = 69,      /* constant_declaration  */
  YYSYMBOL_expression = 70,                /* expression  */
  YYSYMBOL_operand = 71,                   /* operand  */
  YYSYMBOL_constant_right_hand_side = 72,  /* constant_right_hand_side  */
  YYSYMBOL_assignment = 73,                /* assignment  */
  YYSYMBOL_function_call = 74,             /* function_call  */
  YYSYMBOL_if_statement = 75,              /* if_statement  */
  YYSYMBOL_elseif_statment = 76,           /* elseif_statment  */
  YYSYMBOL_while_statement = 77,           /* while_statement  */
  YYSYMBOL_for_statement = 78,             /* for_statement  */
  YYSYMBOL_counter_variable = 79,          /* counter_variable  */
  YYSYMBOL_switch_statement = 80,          /* switch_statement  */
  YYSYMBOL_in_switch_statement = 81,       /* in_switch_statement  */
  YYSYMBOL_cases = 82,                     /* cases  */
  YYSYMBOL_case = 83,                      /* case  */
  YYSYMBOL_default = 84,                   /* default  */
  YYSYMBOL_repeat_until_statement = 85     /* repeat_until_statement  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  57
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   957

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  214

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   307


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    69,    69,    70,    74,    75,    76,    77,    80,    81,
      86,    87,    88,    89,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   116,   117,   118,   119,   122,   124,   124,
     124,   124,   124,   125,   126,   126,   128,   129,   129,   131,
     132,   133,   134,   134,   134,   135,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   148,   149,   150,   151,
     152,   153,   154,   155,   158,   158,   158,   159,   159,   159,
     159,   161,   163,   165,   166,   167,   171,   172,   174,   176,
     177,   177,   179,   180,   180,   181,   181,   182,   183,   185
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER", "FLOAT",
  "BOOL", "CHAR", "TYPE_INT", "TYPE_FLOAT", "TYPE_CHAR", "TYPE_BOOL",
  "TYPE_VOID", "CONSTANT", "ENUM", "WHILE", "FOR", "BREAK", "CONTINUE",
  "IF", "ELSE", "ELSEIF", "SWITCH", "CASE", "DEFAULT", "MINUS", "MULT",
  "PLUS", "DIV", "MODULE", "POWER", "EQU", "INC", "DEC", "MORE", "LESS",
  "EQU_EQU", "MORE_OR_EQU", "LESS_OR_EQU", "NOT_EQU", "AND", "OR", "NOT",
  "OPEN_CURL", "CLOSE_CURL", "OPEN_BRAC", "CLOSE_BRAC", "SEMICOLON",
  "COMMA", "COLON", "REPEAT", "UNTIL", "IDENTIFIER", "COMMENT", "$accept",
  "tokens", "token", "in_scope_statements", "in_scope_statement",
  "in_enum_statement", "enum_variable_declaration", "type",
  "parameter_or_empty", "parameters", "argument_or_empty", "arguments",
  "enum_declaration", "function_prototype", "function_declaration",
  "variable_declaration", "constant_declaration", "expression", "operand",
  "constant_right_hand_side", "assignment", "function_call",
  "if_statement", "elseif_statment", "while_statement", "for_statement",
  "counter_variable", "switch_statement", "in_switch_statement", "cases",
  "case", "default", "repeat_until_statement", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-137)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-89)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     555,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
      56,    10,   -15,    24,    28,    30,    42,    46,    31,    31,
      41,   -20,  -137,   210,  -137,  -137,    45,    49,  -137,    27,
    -137,    55,    57,    84,    15,  -137,    68,  -137,  -137,  -137,
    -137,  -137,    70,    54,   -33,    31,    33,  -137,  -137,    31,
      31,    58,  -137,   695,   574,    31,    31,  -137,  -137,  -137,
       1,   574,  -137,  -137,  -137,    31,    31,    31,    31,    31,
      31,    31,    31,    31,    31,    31,    31,    31,  -137,  -137,
    -137,  -137,  -137,    91,    76,   102,   717,   103,    83,  -137,
    -137,    89,   739,   761,    31,    85,   229,  -137,   888,    92,
    -137,   138,    31,    56,   279,   904,   917,   904,   917,    59,
      59,   -28,   -28,   -28,   -28,   -28,   100,    39,    16,   -22,
      98,    93,   101,   112,    31,   104,   106,   871,    94,   105,
    -137,  -137,    31,   888,   108,    99,   107,  -137,  -137,  -137,
     148,    76,   111,  -137,   574,   672,   574,   137,    31,   116,
    -137,   114,  -137,   122,  -137,  -137,   298,    31,   348,    11,
     132,   157,   137,   -28,    31,    56,    76,  -137,   783,    51,
     133,  -137,   134,  -137,  -137,   805,  -137,  -137,   141,   142,
     143,    61,   574,   574,  -137,   574,   574,    31,   144,   145,
     624,   643,   367,   417,   827,   574,    31,   149,   150,  -137,
    -137,   146,   436,   849,   -16,   151,   574,  -137,   155,   486,
     574,  -137,   505,  -137
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    67,    68,    70,    69,    28,    29,    30,    31,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    64,    20,     0,     3,     7,     0,     0,     4,     0,
       6,     0,     0,     0,    46,    65,     0,    66,    14,    15,
      16,    17,     0,     0,     0,     0,     0,    21,    22,     0,
       0,    64,    63,     0,     0,     0,     0,     1,     2,    19,
      42,     0,     5,    10,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    12,    53,
      54,    13,    18,     0,     0,     0,     0,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,     8,    71,     0,
      36,    37,     0,     0,     0,    48,    49,    47,    50,    51,
      52,    58,    57,    59,    56,    62,    60,    61,     0,    24,
       0,     0,     0,    42,     0,     0,     0,     0,     0,     0,
       9,    72,     0,    43,    66,     0,     0,    33,    41,    45,
       0,     0,     0,    27,     0,     0,     0,     0,     0,     0,
      38,    34,    40,    23,    26,    39,     0,     0,     0,     0,
       0,    83,    85,    55,     0,     0,     0,    78,     0,    73,
       0,    82,     0,    84,    86,     0,    35,    25,     0,     0,
       0,     0,     0,     0,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    79,
      74,     0,     0,     0,    21,    21,     0,    75,     0,     0,
       0,    76,     0,    77
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -137,  -137,   175,   -57,     0,  -136,  -137,     3,  -137,    34,
    -137,    69,  -137,  -137,  -137,   154,  -137,   -17,    44,    86,
     159,   109,  -137,  -137,  -137,  -137,  -137,  -137,  -137,    67,
    -137,  -137,  -137
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    23,    24,    96,    97,   120,    26,    88,   136,   137,
      99,   100,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,   181,    39,    40,    91,    41,   160,   161,
     162,   173,    42
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    52,    53,    27,   104,   154,   -87,   -87,   140,    84,
      55,    76,    77,    43,     1,     2,     3,     4,    85,     1,
       2,     3,     4,    25,    56,   141,    27,   -87,    86,    45,
     177,   102,    92,    93,     1,     2,     3,     4,    98,   101,
       5,     6,     7,     8,     9,   103,    79,    80,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    44,    51,     5,     6,     7,     8,     9,    46,    61,
     179,   180,    18,    62,    47,    19,    48,   127,    76,   -89,
     188,   189,    51,    54,    87,   133,    49,   156,    70,   158,
      50,    59,    71,    72,    73,    74,   130,    75,    76,    77,
      60,    63,    56,    64,   130,    83,   135,   145,    65,    66,
      67,    68,    69,    70,    81,   101,    82,    71,    72,    73,
      74,   118,    75,    76,    77,   190,   191,   119,   192,   193,
      78,   163,   121,    55,   123,   124,   128,   131,   202,   -89,
     168,   142,   102,   144,   143,    85,   146,   175,   147,   209,
     151,   153,   152,   212,   -44,   149,   130,   155,   130,   159,
     164,   165,    65,    66,    67,    68,    69,    70,   135,   166,
     194,    71,    72,    73,    74,   171,    75,    76,    77,   203,
     172,   182,   183,   185,   186,   132,   195,   187,   206,   196,
     130,   130,   130,   130,   -88,   204,   205,   210,    58,   176,
      89,   150,   130,   170,   139,    90,     0,     0,     0,   130,
      57,   134,   130,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,   174,
       0,    17,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    95,    12,    13,    14,    15,    16,     0,     0,
      17,    18,     0,     0,    19,     0,     0,     0,     0,    20,
       0,    21,    22,     0,     0,     0,     0,     0,     0,     0,
      18,     0,   129,    19,     0,     0,     0,     0,    20,     0,
      21,    22,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    95,    12,    13,    14,    15,    16,     0,     0,
      17,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    95,    12,    13,    14,    15,    16,     0,     0,    17,
      18,     0,   138,    19,     0,     0,     0,     0,    20,     0,
      21,    22,     0,     0,     0,     0,     0,     0,     0,    18,
       0,   167,    19,     0,     0,     0,     0,    20,     0,    21,
      22,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    95,    12,    13,    14,    15,    16,     0,     0,    17,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      95,    12,    13,    14,    15,    16,     0,     0,    17,    18,
       0,   169,    19,     0,     0,     0,     0,    20,     0,    21,
      22,     0,     0,     0,     0,     0,     0,     0,    18,     0,
     199,    19,     0,     0,     0,     0,    20,     0,    21,    22,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      95,    12,    13,    14,    15,    16,     0,     0,    17,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    95,
      12,    13,    14,    15,    16,     0,     0,    17,    18,     0,
     200,    19,     0,     0,     0,     0,    20,     0,    21,    22,
       0,     0,     0,     0,     0,     0,     0,    18,     0,   207,
      19,     0,     0,     0,     0,    20,     0,    21,    22,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    95,
      12,    13,    14,    15,    16,     0,     0,    17,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    95,    12,
      13,    14,    15,    16,     0,     0,    17,    18,     0,   211,
      19,     0,     0,     0,     0,    20,     0,    21,    22,     0,
       0,     0,     0,     0,     0,     0,    18,     0,   213,    19,
       0,     0,     0,     0,    20,     0,    21,    22,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     0,     0,    17,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    95,    12,    13,
      14,    15,    16,     0,     0,    17,    18,     0,     0,    19,
       0,     0,     0,     0,    20,     0,    21,    22,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     0,    19,     0,
       0,     0,     0,    20,     0,    21,    22,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    95,    12,    13,
     197,    15,    16,     0,     0,    17,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    95,    12,    13,   198,
      15,    16,     0,     0,    17,    18,     0,     0,    19,     0,
       0,     0,     0,    20,     0,    21,    22,     0,     0,     0,
       0,     0,     0,     0,    18,     0,     0,    19,     0,     0,
       0,     0,    20,     0,    21,    22,    65,    66,    67,    68,
      69,    70,     0,     0,     0,    71,    72,    73,    74,     0,
      75,    76,    77,     0,     0,     0,     0,     0,   157,    65,
      66,    67,    68,    69,    70,     0,     0,     0,    71,    72,
      73,    74,     0,    75,    76,    77,     0,     0,     0,     0,
      94,    65,    66,    67,    68,    69,    70,     0,     0,     0,
      71,    72,    73,    74,     0,    75,    76,    77,     0,     0,
       0,     0,   122,    65,    66,    67,    68,    69,    70,     0,
       0,     0,    71,    72,    73,    74,     0,    75,    76,    77,
       0,     0,     0,     0,   125,    65,    66,    67,    68,    69,
      70,     0,     0,     0,    71,    72,    73,    74,     0,    75,
      76,    77,     0,     0,     0,     0,   126,    65,    66,    67,
      68,    69,    70,     0,     0,     0,    71,    72,    73,    74,
       0,    75,    76,    77,     0,     0,     0,     0,   178,    65,
      66,    67,    68,    69,    70,     0,     0,     0,    71,    72,
      73,    74,     0,    75,    76,    77,     0,     0,     0,     0,
     184,    65,    66,    67,    68,    69,    70,     0,     0,     0,
      71,    72,    73,    74,     0,    75,    76,    77,     0,     0,
       0,     0,   201,    65,    66,    67,    68,    69,    70,     0,
       0,     0,    71,    72,    73,    74,     0,    75,    76,    77,
       0,     0,     0,     0,   208,    65,    66,    67,    68,    69,
      70,     0,     0,     0,    71,    72,    73,    74,   148,    75,
      76,    77,    65,    66,    67,    68,    69,    70,     0,     0,
       0,    71,    72,    73,    74,     0,    75,    76,    77,    66,
       0,    68,    69,    70,     0,     0,     0,    71,    72,    73,
      74,     0,    75,    76,    77,    69,    70,     0,     0,     0,
      71,    72,    73,    74,     0,    75,    76,    77
};

static const yytype_int16 yycheck[] =
{
       0,    18,    19,     0,    61,   141,    22,    23,    30,    42,
      30,    39,    40,    10,     3,     4,     5,     6,    51,     3,
       4,     5,     6,    23,    44,    47,    23,    43,    45,    44,
     166,    30,    49,    50,     3,     4,     5,     6,    55,    56,
       7,     8,     9,    10,    11,    44,    31,    32,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    51,    51,     7,     8,     9,    10,    11,    44,    42,
      19,    20,    41,    46,    46,    44,    46,    94,    39,    40,
      19,    20,    51,    42,    51,   102,    44,   144,    29,   146,
      44,    46,    33,    34,    35,    36,    96,    38,    39,    40,
      51,    46,    44,    46,   104,    51,   103,   124,    24,    25,
      26,    27,    28,    29,    46,   132,    46,    33,    34,    35,
      36,    30,    38,    39,    40,   182,   183,    51,   185,   186,
      46,   148,    30,    30,    51,    46,    51,    45,   195,    39,
     157,    43,    30,    42,    51,    51,    42,   164,    42,   206,
      51,     3,    45,   210,    46,    50,   156,    46,   158,    22,
      44,    47,    24,    25,    26,    27,    28,    29,   165,    47,
     187,    33,    34,    35,    36,    43,    38,    39,    40,   196,
      23,    48,    48,    42,    42,    47,    42,    44,    42,    44,
     190,   191,   192,   193,    43,    46,    46,    42,    23,   165,
      46,   132,   202,   159,   118,    46,    -1,    -1,    -1,   209,
       0,   102,   212,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,   162,
      -1,    21,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
      21,    41,    -1,    -1,    44,    -1,    -1,    -1,    -1,    49,
      -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    -1,    43,    44,    -1,    -1,    -1,    -1,    49,    -1,
      51,    52,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
      21,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    -1,    -1,    21,
      41,    -1,    43,    44,    -1,    -1,    -1,    -1,    49,    -1,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      -1,    43,    44,    -1,    -1,    -1,    -1,    49,    -1,    51,
      52,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    -1,    -1,    21,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    -1,    21,    41,
      -1,    43,    44,    -1,    -1,    -1,    -1,    49,    -1,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      43,    44,    -1,    -1,    -1,    -1,    49,    -1,    51,    52,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    -1,    21,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    -1,    21,    41,    -1,
      43,    44,    -1,    -1,    -1,    -1,    49,    -1,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    43,
      44,    -1,    -1,    -1,    -1,    49,    -1,    51,    52,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    -1,    21,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    -1,    21,    41,    -1,    43,
      44,    -1,    -1,    -1,    -1,    49,    -1,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    43,    44,
      -1,    -1,    -1,    -1,    49,    -1,    51,    52,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    -1,    21,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    -1,    21,    41,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    49,    -1,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,    44,    -1,
      -1,    -1,    -1,    49,    -1,    51,    52,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    -1,    21,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    -1,    21,    41,    -1,    -1,    44,    -1,
      -1,    -1,    -1,    49,    -1,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    -1,    -1,    44,    -1,    -1,
      -1,    -1,    49,    -1,    51,    52,    24,    25,    26,    27,
      28,    29,    -1,    -1,    -1,    33,    34,    35,    36,    -1,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    46,    24,
      25,    26,    27,    28,    29,    -1,    -1,    -1,    33,    34,
      35,    36,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,
      45,    24,    25,    26,    27,    28,    29,    -1,    -1,    -1,
      33,    34,    35,    36,    -1,    38,    39,    40,    -1,    -1,
      -1,    -1,    45,    24,    25,    26,    27,    28,    29,    -1,
      -1,    -1,    33,    34,    35,    36,    -1,    38,    39,    40,
      -1,    -1,    -1,    -1,    45,    24,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    33,    34,    35,    36,    -1,    38,
      39,    40,    -1,    -1,    -1,    -1,    45,    24,    25,    26,
      27,    28,    29,    -1,    -1,    -1,    33,    34,    35,    36,
      -1,    38,    39,    40,    -1,    -1,    -1,    -1,    45,    24,
      25,    26,    27,    28,    29,    -1,    -1,    -1,    33,    34,
      35,    36,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,
      45,    24,    25,    26,    27,    28,    29,    -1,    -1,    -1,
      33,    34,    35,    36,    -1,    38,    39,    40,    -1,    -1,
      -1,    -1,    45,    24,    25,    26,    27,    28,    29,    -1,
      -1,    -1,    33,    34,    35,    36,    -1,    38,    39,    40,
      -1,    -1,    -1,    -1,    45,    24,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    24,    25,    26,    27,    28,    29,    -1,    -1,
      -1,    33,    34,    35,    36,    -1,    38,    39,    40,    25,
      -1,    27,    28,    29,    -1,    -1,    -1,    33,    34,    35,
      36,    -1,    38,    39,    40,    28,    29,    -1,    -1,    -1,
      33,    34,    35,    36,    -1,    38,    39,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    21,    41,    44,
      49,    51,    52,    54,    55,    57,    59,    60,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    77,
      78,    80,    85,    60,    51,    44,    44,    46,    46,    44,
      44,    51,    70,    70,    42,    30,    44,     0,    55,    46,
      51,    42,    46,    46,    46,    24,    25,    26,    27,    28,
      29,    33,    34,    35,    36,    38,    39,    40,    46,    31,
      32,    46,    46,    51,    42,    51,    70,    51,    60,    68,
      73,    79,    70,    70,    45,    13,    56,    57,    70,    63,
      64,    70,    30,    44,    56,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    30,    51,
      58,    30,    45,    51,    46,    45,    45,    70,    51,    43,
      57,    45,    47,    70,    74,    60,    61,    62,    43,    72,
      30,    47,    43,    51,    42,    70,    42,    42,    37,    50,
      64,    51,    45,     3,    58,    46,    56,    46,    56,    22,
      81,    82,    83,    70,    44,    47,    47,    43,    70,    43,
      71,    43,    23,    84,    82,    70,    62,    58,    45,    19,
      20,    76,    48,    48,    45,    42,    42,    44,    19,    20,
      56,    56,    56,    56,    70,    42,    44,    16,    16,    43,
      43,    45,    56,    70,    46,    46,    42,    43,    45,    56,
      42,    43,    56,    43
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    54,    55,    55,    55,    55,    56,    56,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    58,    58,    58,    58,    59,    60,    60,
      60,    60,    60,    61,    62,    62,    63,    64,    64,    65,
      66,    67,    68,    68,    68,    69,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    71,    71,    71,    72,    72,    72,
      72,    73,    74,    75,    75,    75,    76,    76,    77,    78,
      79,    79,    80,    81,    81,    82,    82,    83,    84,    85
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     2,     1,     1,     1,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     2,     2,
       1,     2,     2,     3,     1,     5,     3,     5,     1,     1,
       1,     1,     1,     1,     2,     4,     1,     1,     3,     6,
       5,     4,     2,     4,     4,     5,     1,     3,     3,     3,
       3,     3,     3,     2,     2,     6,     3,     3,     3,     3,
       3,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     7,    11,    12,     7,     8,     7,    11,
       1,     1,     7,     1,     2,     1,     2,     6,     5,     8
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {

#line 1547 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 187 "parser.y"

/* ############ Auxiliary Functions ############ */

int main(int argc, char **argv) { 
    yydebug = ENABLE_YACC_DEBUG;
    yy_flex_debug = ENABLE_LEX_DEBUG;

    if (argc == 1)
    {
        fprintf(stdout, "No arguments provided!\nInput will default to input.txt\nOutput will default to output.txt\n");
        yyin = fopen("input.txt", "r");
        if (yyin == NULL)
        {
            fprintf(stderr, "Input file not found!\nDefaulting input to factorinal\n[use ctrl+D to exit]\n");
            yyin = stdin;
        }
        yyout = fopen("output.txt", "w");
    }
    if (argc == 2)
    {
        fprintf(stdout, "Input set to \"%s\"\nOutput will default to output.txt\n",argv[1]);

        yyin = fopen(argv[1], "r");
        if (yyin == NULL)
        {
            fprintf(stderr, "Input file not found!\nDefaulting input to factorinal\n[use ctrl+D to exit]\n");
            yyin = stdin;
        }
        yyout = fopen("output.txt", "w");
    }
    if (argc == 3)
    {
        fprintf(stdout, "Input set to \"%s\"\nOutput set to \"%s\"\n", argv[1], argv[2]);

        yyin = fopen(argv[1], "r");
        if (yyin == NULL)
        {
            fprintf(stderr, "Input file not found!\nDefaulting input to factorinal\n[use ctrl+D to exit]\n");
            yyin = stdin;
        }
        yyout = fopen(argv[2], "w");
    }
    if (argc > 3)
    {
        fprintf(stdout, "Input set to \"%s\"\nOutput set to \"%s\"\nExtra arguments skipped!\n", argv[1], argv[2]);
        
        yyin = fopen(argv[1], "r");
        if (yyin == NULL)
        {
            fprintf(stderr, "Input file not found!\nDefaulting input to factorinal\n[use ctrl+D to exit]\n");
            yyin = stdin;
        }
        yyout = fopen(argv[2], "w");
    }

    yyparse();

    if (yyin != stdin)
    {
        fclose(yyin);
    }
    fclose(yyout);

    return 0;
}

int yyerror(char const *s)
{
    fprintf(stderr, "%s\n", "HIII");
    return fprintf(stderr, "%s\n", s);
}
