#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "../SymbolTable/symboltable.h"

struct ScopeNode
{
    std::string name;
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
    SymbolTable* removeScope();
    SymbolTable* getGlobals();
    SymbolTable* getSymbolTableFromStack(std::string symbolname);
    void printSymbolTables(ScopeNode* node = NULL, int level = 0);
};