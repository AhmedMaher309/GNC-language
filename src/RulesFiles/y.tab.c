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
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "src/RulesFiles/parser.y"

    /*To enable yacc debugging (tracing the grammar rules) set the ENABLE_YACC_DEBUG flag to 1 (default: 0)*/
    #define ENABLE_YACC_DEBUG 0

    /*To enable lex debugging (tracing the token rules) set the ENABLE_LEX_DEBUG flag to 1 (default: 0)*/
    #define ENABLE_LEX_DEBUG 0
#line 11 "src/RulesFiles/parser.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "../SymbolTable/symboltable.h"
    #include "../Validator/validator.h"
    extern void lex_init(void*&);
    extern void lex_deinit(void*&);
    extern int yylex(union YYSTYPE*, struct YYLTYPE*, void*);
    int yyerror(struct YYLTYPE*, void*, const char*);

    void* scanner;
    extern void yyset_debug(int, void*);
    extern int yyget_leng(void*);

    SymbolTable table;
    Validator valid;

#line 97 "src/RulesFiles/y.tab.c"

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

#include "y.tab.h"
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
  YYSYMBOL_STRING = 7,                     /* STRING  */
  YYSYMBOL_TYPE_INT = 8,                   /* TYPE_INT  */
  YYSYMBOL_TYPE_FLOAT = 9,                 /* TYPE_FLOAT  */
  YYSYMBOL_TYPE_CHAR = 10,                 /* TYPE_CHAR  */
  YYSYMBOL_TYPE_BOOL = 11,                 /* TYPE_BOOL  */
  YYSYMBOL_TYPE_STRING = 12,               /* TYPE_STRING  */
  YYSYMBOL_TYPE_VOID = 13,                 /* TYPE_VOID  */
  YYSYMBOL_CONSTANT = 14,                  /* CONSTANT  */
  YYSYMBOL_ENUM = 15,                      /* ENUM  */
  YYSYMBOL_WHILE = 16,                     /* WHILE  */
  YYSYMBOL_FOR = 17,                       /* FOR  */
  YYSYMBOL_BREAK = 18,                     /* BREAK  */
  YYSYMBOL_IF = 19,                        /* IF  */
  YYSYMBOL_ELSE = 20,                      /* ELSE  */
  YYSYMBOL_RETURN = 21,                    /* RETURN  */
  YYSYMBOL_SWITCH = 22,                    /* SWITCH  */
  YYSYMBOL_CASE = 23,                      /* CASE  */
  YYSYMBOL_DEFAULT = 24,                   /* DEFAULT  */
  YYSYMBOL_PRINT = 25,                     /* PRINT  */
  YYSYMBOL_MINUS = 26,                     /* MINUS  */
  YYSYMBOL_MULT = 27,                      /* MULT  */
  YYSYMBOL_PLUS = 28,                      /* PLUS  */
  YYSYMBOL_DIV = 29,                       /* DIV  */
  YYSYMBOL_MODULE = 30,                    /* MODULE  */
  YYSYMBOL_POWER = 31,                     /* POWER  */
  YYSYMBOL_EQU = 32,                       /* EQU  */
  YYSYMBOL_INC = 33,                       /* INC  */
  YYSYMBOL_DEC = 34,                       /* DEC  */
  YYSYMBOL_MORE = 35,                      /* MORE  */
  YYSYMBOL_LESS = 36,                      /* LESS  */
  YYSYMBOL_EQU_EQU = 37,                   /* EQU_EQU  */
  YYSYMBOL_MORE_OR_EQU = 38,               /* MORE_OR_EQU  */
  YYSYMBOL_LESS_OR_EQU = 39,               /* LESS_OR_EQU  */
  YYSYMBOL_NOT_EQU = 40,                   /* NOT_EQU  */
  YYSYMBOL_AND = 41,                       /* AND  */
  YYSYMBOL_OR = 42,                        /* OR  */
  YYSYMBOL_NOT = 43,                       /* NOT  */
  YYSYMBOL_REPEAT = 44,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 45,                     /* UNTIL  */
  YYSYMBOL_IDENTIFIER = 46,                /* IDENTIFIER  */
  YYSYMBOL_COMMENT = 47,                   /* COMMENT  */
  YYSYMBOL_48_ = 48,                       /* ';'  */
  YYSYMBOL_49_ = 49,                       /* '('  */
  YYSYMBOL_50_ = 50,                       /* ')'  */
  YYSYMBOL_51_ = 51,                       /* '{'  */
  YYSYMBOL_52_ = 52,                       /* '}'  */
  YYSYMBOL_53_ = 53,                       /* ','  */
  YYSYMBOL_54_ = 54,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 55,                  /* $accept  */
  YYSYMBOL_program = 56,                   /* program  */
  YYSYMBOL_stmt = 57,                      /* stmt  */
  YYSYMBOL_stmt_list = 58,                 /* stmt_list  */
  YYSYMBOL_func_stmt_list = 59,            /* func_stmt_list  */
  YYSYMBOL_break_stmt_list = 60,           /* break_stmt_list  */
  YYSYMBOL_genn_stmt = 61,                 /* genn_stmt  */
  YYSYMBOL_func_stmt = 62,                 /* func_stmt  */
  YYSYMBOL_print_stmt = 63,                /* print_stmt  */
  YYSYMBOL_for_stmt = 64,                  /* for_stmt  */
  YYSYMBOL_if_stmt = 65,                   /* if_stmt  */
  YYSYMBOL_enum_stmt = 66,                 /* enum_stmt  */
  YYSYMBOL_while_stmt = 67,                /* while_stmt  */
  YYSYMBOL_repeat_stmt = 68,               /* repeat_stmt  */
  YYSYMBOL_switch_stmt = 69,               /* switch_stmt  */
  YYSYMBOL_func_proto = 70,                /* func_proto  */
  YYSYMBOL_func_define = 71,               /* func_define  */
  YYSYMBOL_func_call = 72,                 /* func_call  */
  YYSYMBOL_for_proto = 73,                 /* for_proto  */
  YYSYMBOL_for_define = 74,                /* for_define  */
  YYSYMBOL_if_proto = 75,                  /* if_proto  */
  YYSYMBOL_if_define = 76,                 /* if_define  */
  YYSYMBOL_enum_declare = 77,              /* enum_declare  */
  YYSYMBOL_enum_define = 78,               /* enum_define  */
  YYSYMBOL_while_proto = 79,               /* while_proto  */
  YYSYMBOL_while_define = 80,              /* while_define  */
  YYSYMBOL_type = 81,                      /* type  */
  YYSYMBOL_parameters = 82,                /* parameters  */
  YYSYMBOL_rvalue = 83,                    /* rvalue  */
  YYSYMBOL_enum_list = 84,                 /* enum_list  */
  YYSYMBOL_case_list = 85,                 /* case_list  */
  YYSYMBOL_case_default = 86,              /* case_default  */
  YYSYMBOL_expr_list = 87,                 /* expr_list  */
  YYSYMBOL_expr = 88                       /* expr  */
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

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  61
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1222

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  252

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


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
      49,    50,     2,     2,    53,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    54,    48,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    52,     2,     2,     2,     2,
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
      45,    46,    47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   121,   121,   122,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   140,   141,   144,   145,   148,   149,
     155,   158,   159,   160,   173,   187,   200,   204,   205,   206,
     210,   214,   215,   218,   219,   222,   223,   227,   228,   231,
     232,   235,   236,   241,   242,   246,   247,   251,   255,   256,
     259,   260,   261,   262,   266,   269,   270,   271,   272,   273,
     274,   275,   276,   280,   282,   284,   287,   288,   295,   296,
     297,   298,   299,   302,   303,   304,   307,   308,   309,   310,
     311,   314,   315,   316,   317,   320,   321,   324,   327,   328,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "end of file", "error", "invalid token", "INTEGER", "FLOAT", "BOOL",
  "CHAR", "STRING", "TYPE_INT", "TYPE_FLOAT", "TYPE_CHAR", "TYPE_BOOL",
  "TYPE_STRING", "TYPE_VOID", "CONSTANT", "ENUM", "WHILE", "FOR", "BREAK",
  "IF", "ELSE", "RETURN", "SWITCH", "CASE", "DEFAULT", "PRINT", "MINUS",
  "MULT", "PLUS", "DIV", "MODULE", "POWER", "EQU", "INC", "DEC", "MORE",
  "LESS", "EQU_EQU", "MORE_OR_EQU", "LESS_OR_EQU", "NOT_EQU", "AND", "OR",
  "NOT", "REPEAT", "UNTIL", "IDENTIFIER", "COMMENT", "';'", "'('", "')'",
  "'{'", "'}'", "','", "':'", "$accept", "program", "stmt", "stmt_list",
  "func_stmt_list", "break_stmt_list", "genn_stmt", "func_stmt",
  "print_stmt", "for_stmt", "if_stmt", "enum_stmt", "while_stmt",
  "repeat_stmt", "switch_stmt", "func_proto", "func_define", "func_call",
  "for_proto", "for_define", "if_proto", "if_define", "enum_declare",
  "enum_define", "while_proto", "while_define", "type", "parameters",
  "rvalue", "enum_list", "case_list", "case_default", "expr_list", "expr", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#define YYPACT_NINF (-159)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     843,  -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159,
    -159,   -35,     8,    -1,    20,    45,    46,    55,    64,    21,
      29,   -19,  -159,   684,  -159,  -159,  -159,  -159,  -159,  -159,
    -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159,
    -159,  -159,  -159,  -159,  -159,    73,  -159,   973,    75,    76,
     -37,    21,    71,    21,    80,    21,  -159,  -159,   342,    94,
      21,  -159,  -159,   -17,    21,    21,    21,    21,    21,    21,
    -159,  -159,    21,    21,    21,    21,    21,    21,    21,    21,
    -159,     8,    89,    93,    82,   180,    97,   996,   865,    81,
     883,    85,  -159,   392,    83,    86,  1019,   -43,  1180,    94,
    -159,     8,   706,   266,   706,   266,   158,   158,   -20,   -20,
     -20,   -20,   -20,   -20,    92,    -3,    90,    88,   105,    95,
     -24,    87,    -8,    21,    21,    17,    91,    96,    98,   100,
    -159,  -159,  -159,  -159,    21,   102,  1042,   101,   103,    22,
     106,   109,   140,    82,   110,  -159,   707,  1065,  1088,  -159,
     415,    66,  -159,    21,    99,  1180,  -159,  -159,    31,     8,
    -159,   843,  -159,  -159,   107,  -159,  -159,   111,   246,   112,
      21,    21,   126,   465,   105,   108,    79,   113,   901,    21,
    -159,   752,  -159,   488,    82,  -159,   115,  -159,  -159,  1111,
     919,    36,   146,   117,   707,   105,   120,   119,   121,   937,
      21,   797,   123,  -159,  -159,  -159,    21,    37,  -159,   538,
      67,   707,   820,  -159,   122,   129,  -159,  -159,   130,  1134,
      21,  -159,   955,  -159,   707,  -159,   561,  -159,   611,  -159,
     707,  -159,  -159,  -159,  1157,    72,   269,   127,  -159,  -159,
     634,  -159,  -159,  -159,   707,  -159,  -159,  -159,   319,   128,
    -159,  -159
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    76,    77,    79,    78,    80,    68,    69,    70,    71,
      72,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    13,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    27,    28,    29,    31,    32,    33,
      34,    35,    36,    37,    38,     0,    90,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    91,   108,     0,     0,
       0,     1,     2,     0,     0,     0,     0,     0,     0,     0,
     106,   107,     0,     0,     0,     0,     0,     0,     0,     0,
      26,    75,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,    14,     0,    91,     0,     0,     0,    88,     0,
      20,    75,    93,    94,    92,    95,    97,    96,   102,   103,
      98,   100,   101,    99,   104,   105,     0,     0,     0,     0,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,    22,    24,    47,     0,     0,     0,     0,    73,     0,
       0,     0,     0,     0,     0,    65,     0,     0,     0,    54,
       0,     0,    30,     0,     0,    89,    21,    25,     0,    75,
      44,     0,    23,    64,    82,    84,    63,     0,     0,     0,
       0,     0,    59,     0,     0,     0,     0,     0,     0,     0,
      43,     0,    74,     0,     0,    19,     0,    66,    67,     0,
       0,     0,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,    83,    18,     0,     0,    62,     0,
       0,     0,     0,    87,     0,     0,    42,    40,     0,     0,
       0,    45,     0,    49,     0,    61,     0,    58,     0,    86,
       0,    41,    39,    17,     0,     0,     0,     0,    60,    57,
       0,    85,    16,    48,     0,    52,    53,    56,     0,     0,
      50,    51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -159,  -159,     0,   -54,  -159,  -158,  -159,  -159,  -159,  -159,
    -159,  -159,  -159,  -159,  -159,  -159,  -159,   -47,  -159,  -159,
    -159,  -159,  -159,  -159,  -159,  -159,   -10,   -96,  -112,  -140,
    -159,     5,  -159,   -18
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    23,    92,   212,   202,   169,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,   117,    46,   121,
     176,   177,    97,    47
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,    57,    49,   165,    93,   137,   140,   133,   142,    83,
     134,    48,    95,    59,    84,    99,     6,     7,     8,     9,
      10,    78,    79,    62,     1,     2,     3,     4,     5,   143,
      60,   100,   101,    85,    87,    88,   213,    90,    78,    -1,
     145,    96,    98,   146,   204,    50,   102,   103,   104,   105,
     106,   107,   135,   229,   108,   109,   110,   111,   112,   113,
     114,   115,   193,   182,    19,   149,   237,    56,   150,    51,
     160,   116,   241,   161,     1,     2,     3,     4,     5,   180,
      58,   136,   181,   214,   208,   223,   249,   209,   224,   174,
     175,   116,   168,   130,    52,    53,   173,     1,     2,     3,
       4,     5,   195,   175,    54,   147,   148,   183,     1,     2,
       3,     4,     5,    55,    19,   227,   155,    86,   228,    63,
     243,   118,    82,   244,    81,   119,    89,   201,   120,   123,
     128,   126,    60,    -1,   131,   178,   138,    19,   139,   144,
      94,   141,   151,   164,   152,   154,   191,   153,   179,   116,
     156,   158,   189,   190,   162,   226,   159,   163,   166,   185,
     184,   199,   194,   205,   188,   197,   210,   216,   130,   217,
     236,   211,   215,   130,   240,   221,   230,   231,   232,   246,
     251,   196,   219,   130,     0,     0,     0,     0,   222,    69,
     248,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,   130,   234,     0,     0,     0,    64,    65,    66,    67,
      68,    69,   130,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,     0,     0,     0,   130,     0,     0,     0,
     122,     0,     0,     0,     0,     0,   130,     0,     0,     0,
     130,     0,     0,     0,     0,     0,     0,     0,   130,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,   186,    16,     0,     0,    17,     0,
       0,    18,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,   186,    16,    19,
      20,    17,    21,    22,    18,     0,    68,    69,   187,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,     0,
       0,     0,    19,    20,     0,    21,    22,     0,     0,     0,
       0,   245,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,   186,    16,     0,
       0,    17,     0,     0,    18,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,    16,    19,    20,    17,    21,    22,    18,     0,     0,
       0,   250,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,    20,     0,    21,    22,
       0,     0,     0,     0,    91,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,    16,     0,     0,    17,     0,     0,    18,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,    16,    19,    20,    17,    21,    22,
      18,     0,     0,     0,   129,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,    20,
       0,    21,    22,     0,     0,     0,     0,   172,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,    16,     0,     0,    17,     0,     0,
      18,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     0,    16,    19,    20,
      17,    21,    22,    18,     0,     0,     0,   192,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,    20,     0,    21,    22,     0,     0,     0,     0,
     203,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     0,    16,     0,     0,
      17,     0,     0,    18,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     0,
      16,    19,    20,    17,    21,    22,    18,     0,     0,     0,
     225,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,    20,     0,    21,    22,     0,
       0,     0,     0,   238,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     0,
      16,     0,     0,    17,     0,     0,    18,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,    16,    19,    20,    17,    21,    22,    18,
       0,     0,     0,   239,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,    20,     0,
      21,    22,     0,     0,    61,     0,   247,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     0,    16,     0,     0,    17,     0,     0,    18,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,   167,    16,    19,    20,    17,
      21,    22,    18,    65,     0,    67,    68,    69,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,     0,
      19,    20,     0,    21,    22,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,    16,     0,   200,    17,     0,     0,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,    20,     0,    21,    22,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,    16,     0,   220,    17,
       0,     0,    18,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,   186,    16,
      19,    20,    17,    21,    22,    18,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,    16,    19,    20,    17,    21,    22,    18,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    19,    20,     0,    21,
      22,    64,    65,    66,    67,    68,    69,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,     0,    64,
      65,    66,    67,    68,    69,   125,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,     0,    64,    65,    66,
      67,    68,    69,   127,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,     0,    64,    65,    66,    67,    68,
      69,   198,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,     0,    64,    65,    66,    67,    68,    69,   207,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
       0,    64,    65,    66,    67,    68,    69,   218,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,     0,    64,
      65,    66,    67,    68,    69,   235,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,     0,     0,     0,     0,
       0,    80,    64,    65,    66,    67,    68,    69,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,     0,
       0,     0,     0,     0,   124,    64,    65,    66,    67,    68,
      69,     0,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,     0,     0,     0,     0,     0,   132,    64,    65,
      66,    67,    68,    69,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     0,     0,     0,     0,     0,
     157,    64,    65,    66,    67,    68,    69,     0,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,     0,     0,
       0,     0,     0,   170,    64,    65,    66,    67,    68,    69,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,     0,     0,     0,     0,     0,   171,    64,    65,    66,
      67,    68,    69,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,     0,     0,     0,     0,     0,   206,
      64,    65,    66,    67,    68,    69,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,     0,     0,     0,
       0,     0,   233,    64,    65,    66,    67,    68,    69,     0,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
       0,     0,     0,     0,     0,   242,    64,    65,    66,    67,
      68,    69,     0,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79
};

static const yytype_int16 yycheck[] =
{
       0,    19,    12,   143,    58,   101,   118,    50,    32,    46,
      53,    46,    59,    32,    51,    32,     8,     9,    10,    11,
      12,    41,    42,    23,     3,     4,     5,     6,     7,    53,
      49,    48,    49,    51,    52,    53,   194,    55,    41,    42,
      48,    59,    60,    51,   184,    46,    64,    65,    66,    67,
      68,    69,    99,   211,    72,    73,    74,    75,    76,    77,
      78,    79,   174,   159,    43,    48,   224,    46,    51,    49,
      48,    81,   230,    51,     3,     4,     5,     6,     7,    48,
      51,    99,    51,   195,    48,    48,   244,    51,    51,    23,
      24,   101,   146,    93,    49,    49,   150,     3,     4,     5,
       6,     7,    23,    24,    49,   123,   124,   161,     3,     4,
       5,     6,     7,    49,    43,    48,   134,    46,    51,    46,
      48,    32,    46,    51,    49,    32,    46,   181,    46,    32,
      45,    50,    49,    41,    48,   153,    46,    43,    50,    52,
      46,    46,    51,     3,    48,    45,    20,    49,    49,   159,
      48,    50,   170,   171,    48,   209,    53,    48,    48,    48,
      53,   179,    54,    48,    52,    52,    20,    48,   168,    48,
     224,    54,    52,   173,   228,    52,    54,    48,    48,    52,
      52,   176,   200,   183,    -1,    -1,    -1,    -1,   206,    31,
     244,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   201,   220,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,   212,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      50,    -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,    -1,
     240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    -1,    22,    -1,
      -1,    25,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    43,
      44,    22,    46,    47,    25,    -1,    30,    31,    52,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    43,    44,    -1,    46,    47,    -1,    -1,    -1,
      -1,    52,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      -1,    22,    -1,    -1,    25,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    19,    43,    44,    22,    46,    47,    25,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    46,    47,
      -1,    -1,    -1,    -1,    52,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    19,    -1,    -1,    22,    -1,    -1,    25,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    19,    43,    44,    22,    46,    47,
      25,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      -1,    46,    47,    -1,    -1,    -1,    -1,    52,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    19,    -1,    -1,    22,    -1,    -1,
      25,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,    19,    43,    44,
      22,    46,    47,    25,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    -1,    46,    47,    -1,    -1,    -1,    -1,
      52,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,    19,    -1,    -1,
      22,    -1,    -1,    25,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      19,    43,    44,    22,    46,    47,    25,    -1,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    -1,    46,    47,    -1,
      -1,    -1,    -1,    52,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      19,    -1,    -1,    22,    -1,    -1,    25,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    19,    43,    44,    22,    46,    47,    25,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,
      46,    47,    -1,    -1,     0,    -1,    52,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    19,    -1,    -1,    22,    -1,    -1,    25,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    43,    44,    22,
      46,    47,    25,    27,    -1,    29,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    -1,
      43,    44,    -1,    46,    47,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    19,    -1,    21,    22,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    46,    47,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    19,    -1,    21,    22,
      -1,    -1,    25,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      43,    44,    22,    46,    47,    25,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    19,    43,    44,    22,    46,    47,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    46,
      47,    26,    27,    28,    29,    30,    31,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    26,
      27,    28,    29,    30,    31,    50,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    26,    27,    28,
      29,    30,    31,    50,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    26,    27,    28,    29,    30,
      31,    50,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    26,    27,    28,    29,    30,    31,    50,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    26,    27,    28,    29,    30,    31,    50,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    26,
      27,    28,    29,    30,    31,    50,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    48,    26,    27,    28,    29,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    48,    26,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    48,    26,    27,
      28,    29,    30,    31,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      48,    26,    27,    28,    29,    30,    31,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    48,    26,    27,    28,    29,    30,    31,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    48,    26,    27,    28,
      29,    30,    31,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    48,
      26,    27,    28,    29,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    48,    26,    27,    28,    29,    30,    31,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    48,    26,    27,    28,    29,
      30,    31,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    19,    22,    25,    43,
      44,    46,    47,    56,    57,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    83,    88,    46,    81,
      46,    49,    49,    49,    49,    49,    46,    88,    51,    32,
      49,     0,    57,    46,    26,    27,    28,    29,    30,    31,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      48,    49,    46,    46,    51,    88,    46,    88,    88,    46,
      88,    52,    57,    58,    46,    72,    88,    87,    88,    32,
      48,    49,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    81,    82,    32,    32,
      46,    84,    50,    32,    48,    50,    50,    50,    45,    52,
      57,    48,    48,    50,    53,    72,    88,    82,    46,    50,
      83,    46,    32,    53,    52,    48,    51,    88,    88,    48,
      51,    51,    48,    49,    45,    88,    48,    48,    50,    53,
      48,    51,    48,    48,     3,    84,    48,    18,    58,    60,
      48,    48,    52,    58,    23,    24,    85,    86,    88,    49,
      48,    51,    82,    58,    53,    48,    18,    52,    52,    88,
      88,    20,    52,    83,    54,    23,    86,    52,    50,    88,
      21,    58,    59,    52,    84,    48,    48,    50,    48,    51,
      20,    54,    58,    60,    83,    52,    48,    48,    50,    88,
      21,    52,    88,    48,    51,    52,    58,    48,    51,    60,
      54,    48,    48,    48,    88,    50,    58,    60,    52,    52,
      58,    60,    48,    48,    51,    52,    52,    52,    58,    60,
      52,    52
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    56,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    58,    58,    59,    59,    60,    60,
      61,    61,    61,    61,    61,    61,    61,    62,    62,    62,
      63,    64,    64,    65,    65,    66,    66,    67,    67,    68,
      68,    69,    69,    70,    70,    71,    71,    72,    73,    73,
      74,    74,    74,    74,    75,    76,    76,    76,    76,    76,
      76,    76,    76,    77,    78,    79,    80,    80,    81,    81,
      81,    81,    81,    82,    82,    82,    83,    83,    83,    83,
      83,    84,    84,    84,    84,    85,    85,    86,    87,    87,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     3,     3,     2,
       3,     5,     4,     6,     4,     5,     2,     1,     1,     1,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     9,
       8,     9,     8,     6,     6,     8,     8,     4,    11,     9,
      13,    13,    11,    11,     5,     7,    11,    10,     9,     6,
      10,     9,     8,     6,     6,     5,     7,     7,     1,     1,
       1,     1,     1,     2,     4,     0,     1,     1,     1,     1,
       1,     1,     3,     5,     3,     5,     4,     3,     1,     3,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2
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
        yyerror (&yylloc, scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void* scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (scanner);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void* scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, scanner);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, void* scanner)
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, scanner); \
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




/* The kind of the lookahead of this context.  */
static yysymbol_kind_t
yypcontext_token (const yypcontext_t *yyctx) YY_ATTRIBUTE_UNUSED;

static yysymbol_kind_t
yypcontext_token (const yypcontext_t *yyctx)
{
  return yyctx->yytoken;
}

/* The location of the lookahead of this context.  */
static YYLTYPE *
yypcontext_location (const yypcontext_t *yyctx) YY_ATTRIBUTE_UNUSED;

static YYLTYPE *
yypcontext_location (const yypcontext_t *yyctx)
{
  return yyctx->yylloc;
}

/* User defined function to report a syntax error.  */
static int
yyreport_syntax_error (const yypcontext_t *yyctx, void* scanner);

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, void* scanner)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (void* scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = yylex (&yylval, &yylloc, scanner);
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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 20: /* genn_stmt: type IDENTIFIER ';'  */
#line 155 "src/RulesFiles/parser.y"
                                                        {   table.addSymbolInTable(new Symbol((yyvsp[-1].gvalue).value,(yyvsp[-2].gvalue).value));
                                                            printf("ID @ %d:%d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                                        }
#line 1726 "src/RulesFiles/y.tab.c"
    break;

  case 23: /* genn_stmt: CONSTANT type IDENTIFIER EQU rvalue ';'  */
#line 160 "src/RulesFiles/parser.y"
                                                        {
                                                            Symbol* sym= new Symbol((yyvsp[-3].gvalue).value, (yyvsp[-4].gvalue).value);
                                                            sym->setIsInitialised(1); sym->setIsConstant(1);
                                                            bool checker = valid.checkSyntax(sym->getVarType(),(yyvsp[-1].gvalue).value); 
                                                            if (checker) {
                                                                table.addSymbolInTable(sym);
                                                                table.modifySymbolInTable(sym,(yyvsp[-1].gvalue).value);
                                                                }
                                                            else {
                                                                printf("error mismatching \n");
                                                                }
                                                            printf("ID @ %d:%d\n", (yylsp[-3]).first_line, (yylsp[-3]).first_column);
                                                        }
#line 1744 "src/RulesFiles/y.tab.c"
    break;

  case 24: /* genn_stmt: IDENTIFIER EQU expr ';'  */
#line 173 "src/RulesFiles/parser.y"
                                                        {
                                                            Symbol* sym = table.getSymbolObjectbyName((yyvsp[-3].gvalue).value); 
                                                            if (sym != NULL)
                                                            {
                                                                bool checker = valid.checkSyntax(sym->getVarType(),(yyvsp[-1].gvalue).value);
                                                                if(checker) {
                                                                    table.setSymbolByNameInTable((yyvsp[-3].gvalue).value, (yyvsp[-1].gvalue).value);
                                                                    }
                                                                else {
                                                                    printf("error mismatching\n");
                                                                    }
                                                            }
                                                            printf("ID @ %d:%d\n", (yylsp[-3]).first_line, (yylsp[-3]).first_column);
                                                        }
#line 1763 "src/RulesFiles/y.tab.c"
    break;

  case 25: /* genn_stmt: type IDENTIFIER EQU expr ';'  */
#line 187 "src/RulesFiles/parser.y"
                                                        { 
                                                            Symbol* sym = new Symbol((yyvsp[-3].gvalue).value,(yyvsp[-4].gvalue).value);
                                                            sym->setIsInitialised(1); 
                                                            bool checker = valid.checkSyntax(sym->getVarType(),(yyvsp[-1].gvalue).value); 
                                                        if (checker) {
                                                                table.addSymbolInTable(sym); 
                                                                table.setSymbolByNameInTable((yyvsp[-3].gvalue).value, (yyvsp[-1].gvalue).value);
                                                                } 
                                                            else {
                                                                printf("error mismatching \n");
                                                                }
                                                            printf("ID @ %d:%d\n", (yylsp[-3]).first_line, (yylsp[-3]).first_column);
                                                        }
#line 1781 "src/RulesFiles/y.tab.c"
    break;

  case 68: /* type: TYPE_INT  */
#line 295 "src/RulesFiles/parser.y"
               { (yyval.gvalue).type = "TYPE"; (yyval.gvalue).value = "int"; }
#line 1787 "src/RulesFiles/y.tab.c"
    break;

  case 69: /* type: TYPE_FLOAT  */
#line 296 "src/RulesFiles/parser.y"
                   { (yyval.gvalue).type = "TYPE"; (yyval.gvalue).value = "float"; }
#line 1793 "src/RulesFiles/y.tab.c"
    break;

  case 70: /* type: TYPE_CHAR  */
#line 297 "src/RulesFiles/parser.y"
                  { (yyval.gvalue).type = "TYPE"; (yyval.gvalue).value = "char"; }
#line 1799 "src/RulesFiles/y.tab.c"
    break;

  case 71: /* type: TYPE_BOOL  */
#line 298 "src/RulesFiles/parser.y"
                  { (yyval.gvalue).type = "TYPE"; (yyval.gvalue).value = "bool"; }
#line 1805 "src/RulesFiles/y.tab.c"
    break;

  case 72: /* type: TYPE_STRING  */
#line 299 "src/RulesFiles/parser.y"
                    { (yyval.gvalue).type = "TYPE"; (yyval.gvalue).value = "string"; }
#line 1811 "src/RulesFiles/y.tab.c"
    break;

  case 76: /* rvalue: INTEGER  */
#line 307 "src/RulesFiles/parser.y"
                { (yyval.gvalue).type = "int"; (yyval.gvalue).value = (yyvsp[0].ivalue).value; }
#line 1817 "src/RulesFiles/y.tab.c"
    break;

  case 77: /* rvalue: FLOAT  */
#line 308 "src/RulesFiles/parser.y"
                { (yyval.gvalue).type = "float"; (yyval.gvalue).value = (yyvsp[0].fvalue).value; }
#line 1823 "src/RulesFiles/y.tab.c"
    break;

  case 78: /* rvalue: CHAR  */
#line 309 "src/RulesFiles/parser.y"
               { (yyval.gvalue).type = "char"; (yyval.gvalue).value = (yyvsp[0].cvalue).value; }
#line 1829 "src/RulesFiles/y.tab.c"
    break;

  case 79: /* rvalue: BOOL  */
#line 310 "src/RulesFiles/parser.y"
               { (yyval.gvalue).type = "bool"; (yyval.gvalue).value = (yyvsp[0].bvalue).value; }
#line 1835 "src/RulesFiles/y.tab.c"
    break;

  case 80: /* rvalue: STRING  */
#line 311 "src/RulesFiles/parser.y"
                 { (yyval.gvalue).type = "string"; (yyval.gvalue).value = (yyvsp[0].svalue).value; }
#line 1841 "src/RulesFiles/y.tab.c"
    break;

  case 90: /* expr: rvalue  */
#line 331 "src/RulesFiles/parser.y"
             { (yyval.gvalue) = (yyvsp[0].gvalue); }
#line 1847 "src/RulesFiles/y.tab.c"
    break;

  case 91: /* expr: IDENTIFIER  */
#line 332 "src/RulesFiles/parser.y"
                  { (yyval.gvalue).type = (yyvsp[0].gvalue).type/*ELMAFROUD HENA NEGIB TYPE EL SYMBOL*/; (yyval.gvalue).value = table.getSymbolByNameInTable((yyvsp[0].gvalue).value); if((yyval.gvalue).value == NULL) {(yyval.gvalue).value = "TEMP";}; }
#line 1853 "src/RulesFiles/y.tab.c"
    break;

  case 92: /* expr: expr PLUS expr  */
#line 333 "src/RulesFiles/parser.y"
                      { (yyval.gvalue).type = "TEMP"; (yyval.gvalue).value = "TEMP"; }
#line 1859 "src/RulesFiles/y.tab.c"
    break;

  case 93: /* expr: expr MINUS expr  */
#line 334 "src/RulesFiles/parser.y"
                       { (yyval.gvalue).type = "TEMP"; (yyval.gvalue).value = "TEMP"; }
#line 1865 "src/RulesFiles/y.tab.c"
    break;

  case 94: /* expr: expr MULT expr  */
#line 335 "src/RulesFiles/parser.y"
                      { (yyval.gvalue).type = "TEMP"; (yyval.gvalue).value = "TEMP"; }
#line 1871 "src/RulesFiles/y.tab.c"
    break;

  case 95: /* expr: expr DIV expr  */
#line 336 "src/RulesFiles/parser.y"
                     { (yyval.gvalue).type = "TEMP"; (yyval.gvalue).value = "TEMP"; }
#line 1877 "src/RulesFiles/y.tab.c"
    break;

  case 96: /* expr: expr POWER expr  */
#line 337 "src/RulesFiles/parser.y"
                       { (yyval.gvalue).type = "TEMP"; (yyval.gvalue).value = "TEMP"; }
#line 1883 "src/RulesFiles/y.tab.c"
    break;

  case 97: /* expr: expr MODULE expr  */
#line 338 "src/RulesFiles/parser.y"
                        { (yyval.gvalue).type = "TEMP"; (yyval.gvalue).value = "TEMP"; }
#line 1889 "src/RulesFiles/y.tab.c"
    break;

  case 98: /* expr: expr EQU_EQU expr  */
#line 339 "src/RulesFiles/parser.y"
                         { (yyval.gvalue).type = "TEMP"; (yyval.gvalue).value = "TEMP"; }
#line 1895 "src/RulesFiles/y.tab.c"
    break;

  case 99: /* expr: expr NOT_EQU expr  */
#line 340 "src/RulesFiles/parser.y"
                         { (yyval.gvalue).type = "TEMP"; (yyval.gvalue).value = "TEMP"; }
#line 1901 "src/RulesFiles/y.tab.c"
    break;

  case 100: /* expr: expr MORE_OR_EQU expr  */
#line 341 "src/RulesFiles/parser.y"
                             { (yyval.gvalue).type = "TEMP"; (yyval.gvalue).value = "TEMP"; }
#line 1907 "src/RulesFiles/y.tab.c"
    break;

  case 101: /* expr: expr LESS_OR_EQU expr  */
#line 342 "src/RulesFiles/parser.y"
                             { (yyval.gvalue).type = "TEMP"; (yyval.gvalue).value = "TEMP"; }
#line 1913 "src/RulesFiles/y.tab.c"
    break;

  case 102: /* expr: expr MORE expr  */
#line 343 "src/RulesFiles/parser.y"
                      { (yyval.gvalue).type = "TEMP"; (yyval.gvalue).value = "TEMP"; }
#line 1919 "src/RulesFiles/y.tab.c"
    break;

  case 103: /* expr: expr LESS expr  */
#line 344 "src/RulesFiles/parser.y"
                      { (yyval.gvalue).type = "TEMP"; (yyval.gvalue).value = "TEMP"; }
#line 1925 "src/RulesFiles/y.tab.c"
    break;

  case 104: /* expr: expr AND expr  */
#line 345 "src/RulesFiles/parser.y"
                     { (yyval.gvalue).type = "TEMP"; (yyval.gvalue).value = "TEMP"; }
#line 1931 "src/RulesFiles/y.tab.c"
    break;

  case 105: /* expr: expr OR expr  */
#line 346 "src/RulesFiles/parser.y"
                    { (yyval.gvalue).type = "TEMP"; (yyval.gvalue).value = "TEMP"; }
#line 1937 "src/RulesFiles/y.tab.c"
    break;

  case 106: /* expr: expr INC  */
#line 347 "src/RulesFiles/parser.y"
                 { (yyval.gvalue).type = "TEMP"; (yyval.gvalue).value = "TEMP"; }
#line 1943 "src/RulesFiles/y.tab.c"
    break;

  case 107: /* expr: expr DEC  */
#line 348 "src/RulesFiles/parser.y"
                { (yyval.gvalue).type = "TEMP"; (yyval.gvalue).value = "TEMP"; }
#line 1949 "src/RulesFiles/y.tab.c"
    break;

  case 108: /* expr: NOT expr  */
#line 349 "src/RulesFiles/parser.y"
                { (yyval.gvalue).type = "TEMP"; (yyval.gvalue).value = "TEMP"; }
#line 1955 "src/RulesFiles/y.tab.c"
    break;


#line 1959 "src/RulesFiles/y.tab.c"

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
  *++yylsp = yyloc;

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        if (yyreport_syntax_error (&yyctx, scanner) == 2)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc, scanner);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
  yyerror (&yylloc, scanner, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 352 "src/RulesFiles/parser.y"

     
/* ############ Auxiliary Functions ############ */

int main(int argc, char **argv) { 
    lex_init(scanner);

    yydebug = ENABLE_YACC_DEBUG;
    yyset_debug(ENABLE_LEX_DEBUG, scanner);

    yyparse(scanner);

    lex_deinit(scanner);
    
    table.printSymbolTable(); 

    return 0;
}

int yyerror(struct YYLTYPE* yylloc, void* scanner, const char *s)
{
    return fprintf(stderr, "%s\n", s);
}

/*CODE COPIED FROM BISON DOCUMENTATION, JUST FOR TESTING, CAN CHANGE LATER*/
static int yyreport_syntax_error(const yypcontext_t *ctx, void* scanner)
{
    int res = 0;
    YYLOCATION_PRINT(stderr, yypcontext_location(ctx));
    fprintf(stderr, ": syntax error");

    // Report the tokens expected at this point.
    {
        yysymbol_kind_t expected[5];
        int n = yypcontext_expected_tokens(ctx, expected, 5);
        if (n < 0)
        {
          // Forward errors to yyparse.
          res = n;
        }
        else
        {
          for (int i = 0; i < n; ++i)
          {
              fprintf(stderr, "%s %s", i == 0 ? ": expected" : " or", yysymbol_name(expected[i]));
          }  
        }     
    }

    // Report the unexpected token.
    {
        yysymbol_kind_t lookahead = yypcontext_token(ctx);
        if (lookahead != YYSYMBOL_YYEMPTY)
        {
            fprintf(stderr, " before %s, len = %d", yysymbol_name(lookahead), yyget_leng(scanner));
        }
    }

    fprintf(stderr, "\n");
    return res;
}
