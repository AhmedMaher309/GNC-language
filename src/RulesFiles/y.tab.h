/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_RULESFILES_Y_TAB_H_INCLUDED
# define YY_YY_SRC_RULESFILES_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
    STRING = 262,                  /* STRING  */
    TYPE_INT = 263,                /* TYPE_INT  */
    TYPE_FLOAT = 264,              /* TYPE_FLOAT  */
    TYPE_CHAR = 265,               /* TYPE_CHAR  */
    TYPE_BOOL = 266,               /* TYPE_BOOL  */
    TYPE_STRING = 267,             /* TYPE_STRING  */
    TYPE_VOID = 268,               /* TYPE_VOID  */
    CONSTANT = 269,                /* CONSTANT  */
    ENUM = 270,                    /* ENUM  */
    WHILE = 271,                   /* WHILE  */
    FOR = 272,                     /* FOR  */
    BREAK = 273,                   /* BREAK  */
    IF = 274,                      /* IF  */
    ELSE = 275,                    /* ELSE  */
    RETURN = 276,                  /* RETURN  */
    SWITCH = 277,                  /* SWITCH  */
    CASE = 278,                    /* CASE  */
    DEFAULT = 279,                 /* DEFAULT  */
    PRINT = 280,                   /* PRINT  */
    MINUS = 281,                   /* MINUS  */
    MULT = 282,                    /* MULT  */
    PLUS = 283,                    /* PLUS  */
    DIV = 284,                     /* DIV  */
    MODULE = 285,                  /* MODULE  */
    POWER = 286,                   /* POWER  */
    EQU = 287,                     /* EQU  */
    INC = 288,                     /* INC  */
    DEC = 289,                     /* DEC  */
    MORE = 290,                    /* MORE  */
    LESS = 291,                    /* LESS  */
    EQU_EQU = 292,                 /* EQU_EQU  */
    MORE_OR_EQU = 293,             /* MORE_OR_EQU  */
    LESS_OR_EQU = 294,             /* LESS_OR_EQU  */
    NOT_EQU = 295,                 /* NOT_EQU  */
    AND = 296,                     /* AND  */
    OR = 297,                      /* OR  */
    NOT = 298,                     /* NOT  */
    REPEAT = 299,                  /* REPEAT  */
    UNTIL = 300,                   /* UNTIL  */
    IDENTIFIER = 301,              /* IDENTIFIER  */
    COMMENT = 302                  /* COMMENT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 38 "src/RulesFiles/parser.y"


    struct 
    {
        const char* type;
        const char* value;
    } ivalue;

    struct 
    {
        const char* type;
        const char* value;
    } fvalue;

    struct 
    {
        const char* type;
        const char* value;
    } cvalue;

    struct 
    {
        const char* type;
        const char* value;
    } bvalue;

    struct 
    {
        const char* type;
        const char* value;
    } svalue;

    struct 
    {
        const char* type;
        const char* value;
    } gvalue;

   //TODO node type will be put here to be the type of any scopes tokens

#line 152 "src/RulesFiles/y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif




int yyparse (void* scanner);


#endif /* !YY_YY_SRC_RULESFILES_Y_TAB_H_INCLUDED  */
