#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "../SymbolTable/symboltable.h"

struct ScopeNode
{
    std::string name;
    std::string type;
    SymbolTable* symbolTable;
    ScopeNode* parent;
    std::vector<ScopeNode*> children;
};

class ScopeStack
{
private:
    ScopeNode* globals;
    ScopeNode* scopeStack;

public:
    ScopeStack();
    SymbolTable* addScope();
    SymbolTable* removeScope(std::string type);
    SymbolTable* getGlobals();
    SymbolTable* getSymbolTableFromStack(std::string symbolname);
    void printSymbolTables(ScopeNode* node = NULL, int level = 0);
};