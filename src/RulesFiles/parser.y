/* ############ Declarations ############ */
/* ### Auxiliary declarations ### */
%{
    /*To enable yacc debugging (tracing the grammar rules) set the ENABLE_YACC_DEBUG flag to 1 (default: 0)*/
    #define ENABLE_YACC_DEBUG 0

    /*To enable lex debugging (tracing the token rules) set the ENABLE_LEX_DEBUG flag to 1 (default: 0)*/
    #define ENABLE_LEX_DEBUG 0
%}

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "../Scopes/scopestack.h"
    #include "../QuadGenerator/quadgenerator.h"
    #include "../FunctionTable/functiontable.h"
    #include "../Validator/validator.h"
    extern void lex_init(void*&);
    extern void lex_deinit(void*&);
    extern int yylex(union YYSTYPE*, struct YYLTYPE*, void*);
    int yyerror(struct YYLTYPE*, void*, const char*);

    void* scanner;
    extern void yyset_debug(int, void*);
    extern int yyget_leng(void*);

    ScopeStack scope;
    QuadGenerator generator;
    SymbolTable* table = scope.getGlobals();

    FunctionTable functions;
    Function* func = NULL;

    Validator valid;
%}

/* ### Regular Definitions ### */
%define api.pure full
%lex-param {void* scanner}
%parse-param {void* scanner}

%locations
%define parse.error custom

%union {

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
};

%token <ivalue> INTEGER
%token <fvalue> FLOAT
%token <bvalue> BOOL
%token <cvalue> CHAR
%token <svalue> STRING
%token <gvalue> TYPE_INT TYPE_FLOAT TYPE_CHAR TYPE_BOOL TYPE_STRING
%token TYPE_VOID
%token CONSTANT
%token ENUM
%token WHILE FOR BREAK
%token IF ELSE RETURN
%token SWITCH CASE DEFAULT
%token PRINT
%token MINUS MULT PLUS DIV MODULE POWER EQU INC DEC
%token MORE LESS EQU_EQU MORE_OR_EQU LESS_OR_EQU NOT_EQU
%token AND OR NOT
%token REPEAT UNTIL
%token <gvalue> IDENTIFIER
%token COMMENT

%type <gvalue> type
%type <gvalue> expr
%type <gvalue> rvalue
%type <gvalue> func_sgnt
%type <gvalue> ret_func_sgnt
%type <gvalue> func_call
%type <gvalue> enum_define

/*to specify the precedence and associativity of operators*/
%left EQU_EQU NOT_EQU MORE LESS MORE_OR_EQU LESS_OR_EQU
%left PLUS MINUS
%left MULT DIV
%left MODULE
%right POWER
%right INC DEC
%right EQU 
%nonassoc OR 
%nonassoc AND
%nonassoc NOT 

%start program 

%% 
    /* ############ Rules ############ */

 /*///////////// the most general rule (program rule)////////////*/

program: program stmt
         | stmt
         ;


 /*////////////////// second degreee ////////////////////////////*/

stmt: genn_stmt // {printf("genn_stmt\n");}
      | func_stmt
      | print_stmt
      | for_stmt
      | if_stmt
      | enum_stmt
      | while_stmt
      | repeat_stmt
      | switch_stmt
      | COMMENT
      ;

stmt_list: stmt             
         | stmt_list stmt   
         ;

func_stmt_list: stmt_list RETURN expr ';'      
                |  RETURN expr ';'
                ;

break_stmt_list: stmt_list BREAK ';' 
               | BREAK ';' 
               ;


 /*/////////////////// third degree /////////////////////////////*/

genn_stmt:  type IDENTIFIER ';'                         {
                                                            Symbol* sym = table->getSymbolObjectbyName($2.value);
                                                            if (sym == NULL)
                                                            {
                                                                Symbol* sym = new Symbol($2.value,$1.value);
                                                                table->addSymbolInTable(sym); 

                                                                const char* name = generator.addAssignment(sym);
                                                                generator.addQuad("ALLOC",$2.value,"",name);
                                                            }
                                                            else
                                                            {
                                                                printf("Error [%d]: Variable is defined before\n", @1.first_line);
                                                            }
                                                        }

           | type IDENTIFIER EQU func_call ';'         {  
                                                            Symbol* sym = table->getSymbolObjectbyName($2.value);
                                                            if (sym == NULL)
                                                            {
                                                                Symbol* sym = new Symbol($2.value,$1.value);
                                                                const char* name = generator.addAssignment(sym);
                                                                generator.addQuad("ALLOC",$2.value,"",name);
                                                                generator.addQuad("ASSIGN",$4.value,"",name);
                                                            }
                                                        }

           | IDENTIFIER EQU func_call ';'

           | CONSTANT type IDENTIFIER EQU rvalue ';'    {
                                                            

                                                            Symbol* sym = table->getSymbolObjectbyName($3.value);
                                                            if (sym == NULL)
                                                            {
                                                                Symbol* sym = new Symbol($3.value, $2.value);
                                                                sym->setIsInitialised(1); 
                                                                sym->setConstant(1);
                                                                if(valid.checkType(sym->getVarType(), $5.type, @1.first_line)){
                                                                    table->addSymbolInTable(sym);
                                                                    table->modifySymbolInTable(sym,valid.TypeConversion(sym->getVarType(), $5.type, $5.value));

                                                                        const char* name = generator.addAssignment(sym);
                                                                        generator.addQuad("CONST_ALLOC",$3.value,"",name);
                                                                        generator.addQuad("ASSIGN",$5.value,"",name);
                                                                }
                                                            }
                                                            else
                                                            {
                                                                printf("Error [%d]: Variable is defined before\n", @1.first_line);
                                                            }
                                                        }

           | IDENTIFIER EQU expr ';'                    {
                                                            SymbolTable* table = scope.getSymbolTableFromStack($1.value);
                                                            if (table != NULL)
                                                            {
                                                                Symbol* sym = table->getSymbolObjectbyName($1.value);

                                                                const char* exprValue = generator.getTemp($3.value);
                                                                const char* exprType = $3.type;

                                                                if (strcmp(exprType,"ID") == 0)
                                                                {
                                                                    SymbolTable* exprtable = scope.getSymbolTableFromStack(exprValue);
                                                                    if (exprtable != NULL)
                                                                    {
                                                                        Symbol* exprsym = exprtable->getSymbolObjectbyName(exprValue);
                                                                        exprValue = generator.getAssignment(exprsym);
                                                                        exprType = exprsym->getVarTypeAsCStr();
                                                                    }
                                                                    else
                                                                    {
                                                                        printf("Error [%d]: Unidentified Variable\n", @1.first_line);
                                                                    }
                                                                }

                                                                if(strcmp(exprType,"ID") != 0)
                                                                {
                                                                    if(sym->checkConstant()){
                                                                        printf("Error [%d]: Constant cannot be reassigned\n", @1.first_line);
                                                                    }
                                                                    else if(valid.checkType(sym->getVarType(), exprType, @1.first_line)){
                                                                        table->modifySymbolInTable(sym,valid.TypeConversion(sym->getVarType(), exprType, exprValue));
                                                                        generator.addQuad("ASSIGN",$3.value,"",generator.getAssignment(sym));
                                                                    }
                                                                }
                                                            }
                                                            else
                                                            {
                                                                printf("Error [%d]: Unidentified Variable\n", @1.first_line);
                                                            }
                                                            generator.clearTemps();
                                                        }

           | type IDENTIFIER EQU expr ';'               { 
                                                            Symbol* sym = table->getSymbolObjectbyName($2.value);
                                                            if (sym == NULL)
                                                            {
                                                                Symbol* sym = new Symbol($2.value,$1.value);

                                                                const char* exprValue = generator.getTemp($4.value);
                                                                const char* exprType = $4.type;

                                                                if (strcmp(exprType,"ID") == 0)
                                                                {
                                                                    SymbolTable* exprtable = scope.getSymbolTableFromStack(exprValue);
                                                                    if (exprtable != NULL)
                                                                    {
                                                                        Symbol* exprsym = exprtable->getSymbolObjectbyName(exprValue);
                                                                        exprValue = generator.getAssignment(exprsym);
                                                                        exprType = exprsym->getVarTypeAsCStr();
                                                                    }
                                                                    else
                                                                    {
                                                                        printf("Error [%d]: Unidentified Variable\n", @1.first_line);
                                                                    }
                                                                }

                                                                if (strcmp(exprType,"ID") != 0)
                                                                {
                                                                    if (valid.checkType(sym->getVarType(), exprType, @1.first_line)) {
                                                                        sym->setIsInitialised(1); 
                                                                        table->addSymbolInTable(sym); 
                                                                        table->modifySymbolInTable(sym,valid.TypeConversion(sym->getVarType(), exprType, exprValue));

                                                                        const char* name = generator.addAssignment(sym);
                                                                        generator.addQuad("ALLOC",$2.value,"",name);
                                                                        generator.addQuad("ASSIGN",$4.value,"",name);
                                                                        }                                                 
                                                                }
                                                            }
                                                            else
                                                            {
                                                                   printf("Error [%d]: Variable is defined before\n", @1.first_line);
                                                            }
                                                            generator.clearTemps();
                                                            //printf("clear\n");
                                                        }
           | expr ';'
           ;


func_stmt: func_proto
	       | func_define
           | func_call
           ;


print_stmt: PRINT '(' expr ')' ';'
            ;


for_stmt: for_proto
	      | for_define
          ;

if_stmt: if_proto
         | if_define
         ;

enum_stmt: enum_declare
	  | enum_define
           ;


while_stmt: while_proto
           | while_define
           ;
           
repeat_stmt: REPEAT scope_begin stmt_list scope_end UNTIL '(' expr ')' ';'              { 
                                                                                            table = scope.removeScope("repeat");
                                                                                            generator.endScope("repeat"); 
                                                                                        }

                  | REPEAT scope_begin scope_end UNTIL '(' expr ')' ';'                 { 
                                                                                            table = scope.removeScope("repeat");
                                                                                            generator.endScope("repeat"); 
                                                                                        }
                  ;
                  
switch_stmt:   SWITCH '(' IDENTIFIER ')' scope_begin case_list case_default scope_end   { 
                                                                                            table = scope.removeScope("switch");
                                                                                            generator.endScope("switch"); 
                                                                                        }

                | SWITCH '(' IDENTIFIER ')' scope_begin case_default scope_end          { 
                                                                                            table = scope.removeScope("switch");
                                                                                            generator.endScope("switch"); 
                                                                                        }
                ;


 /*///////////////////// forth degree /////////////////////////*/
func_proto: func_sgnt parameters ';'                                                    { 
                                                                                            functions.addFunctionInTable(func); func = NULL; 
                                                                                        }

          | ret_func_sgnt parameters ';'                                                { 
                                                                                            functions.addFunctionInTable(func); func = NULL; 
                                                                                        }
          ;

func_define: func_sgnt parameters scope_begin stmt_list scope_end                       { 
                                                                                            table = scope.removeScope($1.value);
                                                                                            generator.endScope($1.value); 
                                                                                            func->setIsDefined(1); 
                                                                                            functions.addFunctionInTable(func); 
                                                                                            func = NULL; 
                                                                                        }

           | ret_func_sgnt parameters scope_begin func_stmt_list scope_end              { 
                                                                                            table = scope.removeScope($1.value);
                                                                                            generator.endScope($1.value); 
                                                                                            func->setIsDefined(1); 
                                                                                            functions.addFunctionInTable(func); 
                                                                                            func = NULL; 
                                                                                        }
           ;
        
func_call: IDENTIFIER '(' expr_list ')'  ';'                                              { /*Check function table to make sure function exists and correct parameters*/ }
          ;                                               



for_proto: FOR '(' IDENTIFIER EQU expr ';' expr ';' IDENTIFIER EQU expr ')' ';'
           ;

for_define: FOR '(' IDENTIFIER EQU expr ';' expr ';' IDENTIFIER EQU expr ')' scope_begin stmt_list scope_end                   {
                                                                                                                                    table = scope.removeScope("for");
                                                                                                                                    generator.endScope("for");
                                                                                                                                }

	        | FOR '(' IDENTIFIER EQU expr ';' expr ';' IDENTIFIER EQU expr ')' scope_begin break_stmt_list scope_end           {
                                                                                                                                    table = scope.removeScope("for");
                                                                                                                                    generator.endScope("for");
                                                                                                                                }

            ;


if_proto: IF '(' expr ')' ';'
        ;

if_define: if_scope 
         | if_scope else_scope
         ;

if_scope: IF '(' expr ')' scope_begin stmt_list scope_end                   {
                                                                                table = scope.removeScope("if");
                                                                                generator.endScope("if");
                                                                                printf("if\n");
                                                                            }

        | IF '(' expr ')' scope_begin scope_end                             {
                                                                                table = scope.removeScope("if");
                                                                                generator.endScope("if");
                                                                                printf("if\n");
                                                                            }
        ;

else_scope: ELSE scope_begin stmt_list scope_end                            {
                                                                                table = scope.removeScope("else");
                                                                                generator.endScope("else");
                                                                            }

          | ELSE scope_begin scope_end                                      {
                                                                                table = scope.removeScope("else");
                                                                                generator.endScope("else");
                                                                            }
          | ELSE ';'
          ;

enum_declare: ENUM IDENTIFIER scope_begin enum_list scope_end ';'           {
                                                                                table = scope.removeScope("enum");
                                                                                generator.endScope("enum");
                                                                            }
            ;

enum_define: ENUM IDENTIFIER IDENTIFIER EQU IDENTIFIER ';'                  {
                                                                    
                                                                            Symbol* sym = new Symbol($3.value,"int");
                                                                            sym->setIsInitialised(1);
                                                                            table->addSymbolInTable(sym);
                                                                            }                
           ;

while_proto: WHILE '(' expr ')' ';' ;


while_define: WHILE '(' expr ')' scope_begin stmt_list scope_end            {
                                                                                table = scope.removeScope("while");
                                                                                generator.endScope("while");
                                                                            }

             | WHILE '(' expr ')' scope_begin break_stmt_list scope_end     {
                                                                                table = scope.removeScope("while");
                                                                                generator.endScope("while");                                                                            
                                                                            }
             ;



 /*//////////////////////fifth degree /////////////////////////////// */

type: TYPE_INT                                                              { $$.type = "TYPE"; $$.value = "int"; }
      | TYPE_FLOAT                                                          { $$.type = "TYPE"; $$.value = "float"; }
      | TYPE_CHAR                                                           { $$.type = "TYPE"; $$.value = "char"; }
      | TYPE_BOOL                                                           { $$.type = "TYPE"; $$.value = "bool"; }
      | TYPE_STRING                                                         { $$.type = "TYPE"; $$.value = "string"; }
      ;


func_sgnt: TYPE_VOID IDENTIFIER '('                                         { 
                                                                                $$.type = "void"; 
                                                                                $$.value = $2.value; 
                                                                                func = new Function($2.value, "void"); 
                                                                            }
         ;

ret_func_sgnt: type IDENTIFIER '('                                          { 
                                                                                $$.type = $1.type; 
                                                                                $$.value = $2.value; 
                                                                                func = new Function($2.value, $1.value); 
                                                                            }
             ;


parameters: type IDENTIFIER ')'                                             { 
                                                                                func->addParameter(new Symbol($2.value, $1.value)); 
                                                                            }

	  | type IDENTIFIER ',' parameters                                      { 
                                                                                func->addParameter(new Symbol($2.value, $1.value)); 
                                                                            }
      | ')'
      ;

rvalue: INTEGER                                                             { $$.type = "int"; $$.value = $1.value; }
        | FLOAT                                                             { $$.type = "float"; $$.value = $1.value; }
        | CHAR                                                              { $$.type = "char"; $$.value = $1.value; }
        | BOOL                                                              { $$.type = "bool"; $$.value = $1.value; }
        | STRING                                                            { $$.type = "string"; $$.value = $1.value; }
        ;

enum_list: IDENTIFIER 
	       | IDENTIFIER EQU INTEGER
           | IDENTIFIER EQU INTEGER ',' enum_list
           | IDENTIFIER ',' enum_list
           ;

case_list:  case_list CASE rvalue case_scope_begin break_stmt_list          { 
                                                                                table = scope.removeScope("case");
                                                                                generator.endScope("case"); 

                                                                            }

            | CASE rvalue case_scope_begin break_stmt_list                  { 
                                                                                table = scope.removeScope("case");
                                                                                generator.endScope("case"); 
                                                                            }
            ;

case_default: DEFAULT case_scope_begin break_stmt_list                      { 
                                                                                table = scope.removeScope("case");
                                                                                generator.endScope("case"); 
                                                                            }
            ;
            
expr_list: expr
         | expr ',' expr_list
         ;

expr: rvalue                    { 
                                    const char* name = generator.addTemp($1.value , "" , "");
                                    generator.addQuad("ASSIGN", $1.value, "", name);

                                    $$.value = name; 
                                    $$.type = $1.type;
                                }

     | IDENTIFIER               { 
                                    SymbolTable* table = scope.getSymbolTableFromStack($1.value);
                                    if (table != NULL)
                                    {
                                        Symbol* sym = table->getSymbolObjectbyName($1.value);
                                        sym->setIsUsed(1);
                                        
                                        const char* name = generator.addTemp(sym->getName() , "" , "");
                                        generator.addQuad("ASSIGN", generator.getAssignment(sym), "", name);

                                        $$.value = name;
                                        $$.type = $1.type; 
                                        valid.checkIntializedVariable(sym->checkInitialisation(), @1.first_line);
                                    } 
                                    else 
                                    {
                                        printf("Error [%d]: Unidentified variable %s\n", @1.first_line, $1.value);
                                    }

                                }

     | expr PLUS expr           {
                                    const char* name1 = generator.getTemp($1.value);
                                    const char* type1 = $1.type;
                                    if (strcmp(type1, "ID") == 0) 
                                    {
                                        Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                        name1 = generator.getAssignment(sym); 
                                        type1 = sym->getVarTypeAsCStr();
                                    }
                                    const char* name2 = generator.getTemp($3.value);
                                    const char* type2 = $3.type;
                                    if (strcmp(type2, "ID") == 0) 
                                    {
                                        Symbol* sym = scope.getSymbolTableFromStack(name2)->getSymbolObjectbyName(name2); 
                                        name2 = generator.getAssignment(sym); 
                                        type2 = sym->getVarTypeAsCStr();
                                    }
                                    bool isMatchedTypes = valid.checkType(type1, type2, @1.first_line);
                                    const char* name = generator.addTemp(name1 , "+" , name2);
                                    generator.addQuad("ADD", $1.value, $3.value, name);
                                    $$.value = name; 
                                    $$.type = type1;
                                }

     | expr MINUS expr          {
                                    const char* name1 = generator.getTemp($1.value);
                                    const char* type1 = $1.type;
                                    if (strcmp(type1, "ID") == 0) 
                                    {
                                        Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                        name1 = generator.getAssignment(sym); 
                                        type1 = sym->getVarTypeAsCStr();
                                    }
                                    const char* name2 = generator.getTemp($3.value);
                                    const char* type2 = $3.type;
                                    if (strcmp(type2, "ID") == 0) 
                                    {
                                        Symbol* sym = scope.getSymbolTableFromStack(name2)->getSymbolObjectbyName(name2); 
                                        name2 = generator.getAssignment(sym); 
                                        type2 = sym->getVarTypeAsCStr();
                                    }
                                    bool isMatchedTypes = valid.checkType(type1, type2, @1.first_line);
                                    const char* name = generator.addTemp(name1 , "-" , name2);
                                    generator.addQuad("SUB", $1.value, $3.value, name);
                                    $$.value = name; 
                                    $$.type = type1;
                                }

     | expr MULT expr           {
                                    const char* name1 = generator.getTemp($1.value);
                                    const char* type1 = $1.type;
                                    if (strcmp(type1, "ID") == 0) 
                                    {
                                        Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                        name1 = generator.getAssignment(sym); 
                                        type1 = sym->getVarTypeAsCStr();
                                    }
                                    const char* name2 = generator.getTemp($3.value);
                                    const char* type2 = $3.type;
                                    if (strcmp(type2, "ID") == 0) 
                                    {
                                        Symbol* sym = scope.getSymbolTableFromStack(name2)->getSymbolObjectbyName(name2); 
                                        name2 = generator.getAssignment(sym); 
                                        type2 = sym->getVarTypeAsCStr();
                                    }
                                    bool isMatchedTypes = valid.checkType(type1, type2, @1.first_line);
                                    const char* name = generator.addTemp(name1 , "*" , name2);
                                    generator.addQuad("MUL", $1.value, $3.value, name);
                                    $$.value = name; 
                                    $$.type = type1;
                                }

     | expr DIV expr            {
                                    const char* name1 = generator.getTemp($1.value);
                                    const char* type1 = $1.type;
                                    if (strcmp(type1, "ID") == 0) 
                                    {
                                        Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                        name1 = generator.getAssignment(sym); 
                                        type1 = sym->getVarTypeAsCStr();
                                    }
                                    const char* name2 = generator.getTemp($3.value);
                                    const char* type2 = $3.type;
                                    if (strcmp(type2, "ID") == 0) 
                                    {
                                        Symbol* sym = scope.getSymbolTableFromStack(name2)->getSymbolObjectbyName(name2); 
                                        name2 = generator.getAssignment(sym); 
                                        type2 = sym->getVarTypeAsCStr();
                                    }
                                    bool isMatchedTypes = valid.checkType(type1, type2, @1.first_line);
                                    const char* name = generator.addTemp(name1 , "/" , name2);
                                    generator.addQuad("DIV", $1.value, $3.value, name);
                                    $$.value = name; 
                                    $$.type = type1;
                                }

     | expr POWER expr          {
                                    const char* name1 = generator.getTemp($1.value);
                                    const char* type1 = $1.type;
                                    if (strcmp(type1, "ID") == 0) 
                                    {
                                        Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                        name1 = generator.getAssignment(sym); 
                                        type1 = sym->getVarTypeAsCStr();
                                    }
                                    const char* name2 = generator.getTemp($3.value);
                                    const char* type2 = $3.type;
                                    if (strcmp(type2, "ID") == 0) {
                                        Symbol* sym = scope.getSymbolTableFromStack(name2)->getSymbolObjectbyName(name2); 
                                        name2 = generator.getAssignment(sym); 
                                        type2 = sym->getVarTypeAsCStr();
                                    }
                                    bool isMatchedTypes = valid.checkType(type1, type2, @1.first_line);
                                    const char* name = generator.addTemp(name1 , "^" , name2);
                                    generator.addQuad("POW", $1.value, $3.value, name);
                                    $$.value = name; 
                                    $$.type = type1;                                 
                                }

     | expr MODULE expr         {
                                    const char* name1 = generator.getTemp($1.value);
                                    const char* type1 = $1.type;
                                    if (strcmp(type1, "ID") == 0) 
                                    {
                                        Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                        name1 = generator.getAssignment(sym); 
                                        type1 = sym->getVarTypeAsCStr();
                                    }
                                    const char* name2 = generator.getTemp($3.value);
                                    const char* type2 = $3.type;
                                    if (strcmp(type2, "ID") == 0) 
                                    {
                                        Symbol* sym = scope.getSymbolTableFromStack(name2)->getSymbolObjectbyName(name2); 
                                        name2 = generator.getAssignment(sym); 
                                        type2 = sym->getVarTypeAsCStr();
                                    }
                                    bool isMatchedTypes = valid.checkType(type1, type2, @1.first_line);
                                    const char* name = generator.addTemp(name1 , "%" , name2);
                                    generator.addQuad("MOD", $1.value, $3.value, name);
                                    $$.value = name; 
                                    $$.type = type1;
                                }

     | expr EQU_EQU expr        {
                                    const char* name1 = generator.getTemp($1.value);
                                    const char* type1 = $1.type;
                                    if (strcmp(type1, "ID") == 0) {
                                        Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                        name1 = generator.getAssignment(sym); 
                                        type1 = sym->getVarTypeAsCStr();
                                    }
                                    const char* name2 = generator.getTemp($3.value);
                                    const char* type2 = $3.type;
                                    if (strcmp(type2, "ID") == 0) {
                                        Symbol* sym = scope.getSymbolTableFromStack(name2)->getSymbolObjectbyName(name2); 
                                        name2 = generator.getAssignment(sym); 
                                        type2 = sym->getVarTypeAsCStr();
                                    }
                                    bool isMatchedTypes = valid.checkType(type1, type2, @1.first_line);
                                    const char* name = generator.addTemp(name1 , "==" , name2);
                                    generator.addQuad("EQU", $1.value, $3.value, name);
                                    $$.value = name;  
                                    $$.type = "bool";
                                }

     | expr NOT_EQU expr        {
                                    const char* name1 = generator.getTemp($1.value);
                                    const char* type1 = $1.type;
                                    if (strcmp(type1, "ID") == 0) 
                                    {
                                        Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                        name1 = generator.getAssignment(sym); 
                                        type1 = sym->getVarTypeAsCStr();
                                    }
                                    const char* name2 = generator.getTemp($3.value);
                                    const char* type2 = $3.type;
                                    if (strcmp(type2, "ID") == 0) 
                                    {
                                        Symbol* sym = scope.getSymbolTableFromStack(name2)->getSymbolObjectbyName(name2); 
                                        name2 = generator.getAssignment(sym); 
                                        type2 = sym->getVarTypeAsCStr();
                                    }
                                    bool isMatchedTypes = valid.checkType(type1, type2, @1.first_line);
                                    const char* name = generator.addTemp(name1 , "!=" , name2);
                                    generator.addQuad("NOTEQU", $1.value, $3.value, name);
                                    $$.value = name;  
                                    $$.type = "bool";
                                }

     | expr MORE_OR_EQU expr    {
                                    const char* name1 = generator.getTemp($1.value);
                                    const char* type1 = $1.type;
                                    if (strcmp(type1, "ID") == 0) 
                                    {
                                        Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                        name1 = generator.getAssignment(sym); 
                                        type1 = sym->getVarTypeAsCStr();
                                    }
                                    const char* name2 = generator.getTemp($3.value);
                                    const char* type2 = $3.type;
                                    if (strcmp(type2, "ID") == 0) 
                                    {
                                        Symbol* sym = scope.getSymbolTableFromStack(name2)->getSymbolObjectbyName(name2); 
                                        name2 = generator.getAssignment(sym); 
                                        type2 = sym->getVarTypeAsCStr();
                                    }
                                    bool isMatchedTypes = valid.checkType(type1, type2, @1.first_line);
                                    const char* name = generator.addTemp(name1 , ">=" , name2);
                                    generator.addQuad("MOREEQU", $1.value, $3.value, name);
                                    $$.value = name;  
                                    $$.type = "bool";
                                }

     | expr LESS_OR_EQU expr    {
                                    const char* name1 = generator.getTemp($1.value);
                                    const char* type1 = $1.type;
                                    if (strcmp(type1, "ID") == 0) 
                                    {
                                        Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                        name1 = generator.getAssignment(sym); 
                                        type1 = sym->getVarTypeAsCStr();
                                    }
                                    const char* name2 = generator.getTemp($3.value);
                                    const char* type2 = $3.type;
                                    if (strcmp(type2, "ID") == 0) 
                                    {
                                        Symbol* sym = scope.getSymbolTableFromStack(name2)->getSymbolObjectbyName(name2); 
                                        name2 = generator.getAssignment(sym); 
                                        type2 = sym->getVarTypeAsCStr();
                                    }
                                    bool isMatchedTypes = valid.checkType(type1, type2, @1.first_line);
                                    const char* name = generator.addTemp(name1 , "<=" , name2);
                                    generator.addQuad("LESSEQU", $1.value, $3.value, name);
                                    $$.value = name; 
                                    $$.type = "bool";
                                }

     | expr MORE expr           {
                                    const char* name1 = generator.getTemp($1.value);
                                    const char* type1 = $1.type;
                                    if (strcmp(type1, "ID") == 0) 
                                    {
                                        Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                        name1 = generator.getAssignment(sym); 
                                        type1 = sym->getVarTypeAsCStr();
                                    }
                                    const char* name2 = generator.getTemp($3.value);
                                    const char* type2 = $3.type;
                                    if (strcmp(type2, "ID") == 0) 
                                    {
                                        Symbol* sym = scope.getSymbolTableFromStack(name2)->getSymbolObjectbyName(name2); 
                                        name2 = generator.getAssignment(sym); 
                                        type2 = sym->getVarTypeAsCStr();
                                    }
                                    bool isMatchedTypes = valid.checkType(type1, type2, @1.first_line);
                                    const char* name = generator.addTemp(name1 , ">" , name2);
                                    generator.addQuad("MORE", $1.value, $3.value, name);
                                    $$.value = name; 
                                    $$.type = "bool";
                                }

     | expr LESS expr           {
                                    const char* name1 = generator.getTemp($1.value);
                                    const char* type1 = $1.type;
                                    if (strcmp(type1, "ID") == 0) 
                                    {
                                        Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                        name1 = generator.getAssignment(sym); 
                                        type1 = sym->getVarTypeAsCStr();
                                    }
                                    const char* name2 = generator.getTemp($3.value);
                                    const char* type2 = $3.type;
                                    if (strcmp(type2, "ID") == 0) 
                                    {
                                        Symbol* sym = scope.getSymbolTableFromStack(name2)->getSymbolObjectbyName(name2); 
                                        name2 = generator.getAssignment(sym); 
                                        type2 = sym->getVarTypeAsCStr();
                                    }
                                    bool isMatchedTypes = valid.checkType(type1, type2, @1.first_line);
                                    const char* name = generator.addTemp(name1 , "<" , name2);
                                    generator.addQuad("LESS", $1.value, $3.value, name);
                                    $$.value = name; 
                                    $$.type = "bool";
                                }

     | expr AND expr            {
                                    const char* name1 = generator.getTemp($1.value);
                                    const char* type1 = $1.type;
                                    if (strcmp(type1, "ID") == 0) 
                                    {
                                        Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                        name1 = generator.getAssignment(sym); 
                                        type1 = sym->getVarTypeAsCStr();
                                    }
                                    const char* name2 = generator.getTemp($3.value);
                                    const char* type2 = $3.type;
                                    if (strcmp(type2, "ID") == 0) 
                                    {
                                        Symbol* sym = scope.getSymbolTableFromStack(name2)->getSymbolObjectbyName(name2); 
                                        name2 = generator.getAssignment(sym); 
                                        type2 = sym->getVarTypeAsCStr();
                                    }
                                    bool isMatchedTypes = valid.checkType(type1, type2, @1.first_line);    
                                    const char* name = generator.addTemp(name1 , "&&" , name2);
                                    generator.addQuad("AND", $1.value, $3.value, name);
                                    $$.value = name;  
                                    $$.type = type1;
                                }

     | expr OR expr             {
                                    const char* name1 = generator.getTemp($1.value);
                                    const char* type1 = $1.type;
                                    if (strcmp(type1, "ID") == 0) 
                                    {
                                        Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                        name1 = generator.getAssignment(sym); 
                                        type1 = sym->getVarTypeAsCStr();
                                    }
                                    const char* name2 = generator.getTemp($3.value);
                                    const char* type2 = $3.type;
                                    if (strcmp(type2, "ID") == 0) 
                                    {
                                        Symbol* sym = scope.getSymbolTableFromStack(name2)->getSymbolObjectbyName(name2); 
                                        name2 = generator.getAssignment(sym); 
                                        type2 = sym->getVarTypeAsCStr();
                                    }
                                    bool isMatchedTypes = valid.checkType(type1, type2, @1.first_line);
                                    const char* name = generator.addTemp(name1 , "||" , name2);
                                    generator.addQuad("OR", $1.value, $3.value, name);
                                    $$.value = name; 
                                    $$.type = type1;
                                }

     | expr INC                 {
                                    const char* name1 = generator.getTemp($1.value);
                                    const char* type1 = $1.type;
                                    if (strcmp(type1, "ID") == 0) 
                                    {
                                        Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                        name1 = generator.getAssignment(sym); 
                                        type1 = sym->getVarTypeAsCStr();
                                    };
                                    if (strcmp(type1, "int") != 0 && strcmp(type1, "float") != 0){
                                        { printf("Error: Cant increment variable of this type\n");}
                                    }

                                    const char* name = generator.addTemp(name1 , "++", "");
                                    generator.addQuad("INC", $1.value, "", name);
                                    $$.value = name; 
                                    $$.type = type1;
                                }

     | expr DEC                 {
                                    const char* name1 = generator.getTemp($1.value);
                                    const char* type1 = $1.type;
                                    if (strcmp(type1, "ID") == 0) 
                                    {
                                        Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                        name1 = generator.getAssignment(sym); 
                                        type1 = sym->getVarTypeAsCStr();
                                    }
                                    if (strcmp(type1, "int") != 0 && strcmp(type1, "float") != 0){
                                        { printf("Error: Cant decrement variable of this type\n");}
                                    }
                                    const char* name = generator.addTemp(name1 , "--", "");
                                    generator.addQuad("DEC", $1.value, "", name);
                                    $$.value = name; 
                                    $$.type = type1;
                                }

     | NOT expr                 {
                                    const char* name1 = generator.getTemp($2.value);
                                    const char* type1 = $2.type;
                                    if (strcmp(type1, "ID") == 0) 
                                    {
                                        Symbol* sym = scope.getSymbolTableFromStack(name1)->getSymbolObjectbyName(name1); 
                                        name1 = generator.getAssignment(sym); 
                                        type1 = sym->getVarTypeAsCStr();
                                    }
                                    if (strcmp(type1, "int") != 0 && strcmp(type1, "bool") != 0){
                                        { printf("Error: Cant invert variable of this type\n");}
                                    }
                                    const char* name = generator.addTemp("!" , name1, "");
                                    generator.addQuad("NOT", $2.value, "", name);
                                    $$.value = name; 
                                    $$.type = type1;
                                }
     ;

scope_begin: '{'            {                            
                                table = scope.addScope();
                                if(func != NULL) 
                                {
                                    for(int i = 0; i < func->getCount(); i++)
                                    {
                                        table->addSymbolInTable(func->getParameter(i));
                                    }
                                }
                                generator.startScope();
                            }
             ;


scope_end: '}'              {
                                table->checkSymbolTable(@1.first_line); 
                            }
           ;

case_scope_begin: ':'       {   
                                table = scope.addScope();
                                generator.startScope();
                            }
                ;

%%
     
/* ############ Auxiliary Functions ############ */

int main(int argc, char **argv) { 
    lex_init(scanner);

    yydebug = ENABLE_YACC_DEBUG;
    yyset_debug(ENABLE_LEX_DEBUG, scanner);

    yyparse(scanner);

    //scope.printSymbolTables();
    scope.printSymbolTablesToFile();
    //functions.printFunctionTable();
    functions.printFunctionTableToFile();
    //generator.printQuads();
    generator.printQuadsToFile();

    valid.printErrorList();
    valid.printWarningList();

    lex_deinit(scanner);

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