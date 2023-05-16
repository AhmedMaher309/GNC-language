#include <iostream>
#include <vector>
#include <string>
#include "symboltable.h"

class ScopeStack
{
private:
    SymbolTable* globals;
    std::vector<SymbolTable*> scopeStack;

public:
    ScopeStack();
    SymbolTable* addScope();
    SymbolTable* removeScope();
    SymbolTable* getGlobals();
    SymbolTable* getSymbolTableFromStack(std::string symbolname);
};