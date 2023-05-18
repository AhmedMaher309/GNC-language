/*===============================*/
/*UNUSED FILE, ONLY FOR ARCHIVING*/
/*===============================*/

#include <iostream>
#include <vector>
#include <string>

#include "scopestack_old.h"

using namespace std;

ScopeStack::ScopeStack()
{
    this->globals = new SymbolTable();
}

SymbolTable* ScopeStack::addScope()
{
    scopeStack.push_back(new SymbolTable());
    return scopeStack.back();
}

SymbolTable* ScopeStack::removeScope()
{
    scopeStack.pop_back();
    if (!scopeStack.empty())
    {
        return scopeStack.back();
    }
    else
    {
        return globals;
    }
}

SymbolTable* ScopeStack::getGlobals()
{
    return globals;
}

SymbolTable* ScopeStack::getSymbolTableFromStack(std::string symbolname)
{
    Symbol* result;
    for (auto scope = scopeStack.rbegin(); scope != scopeStack.rend(); ++scope)
    {
        result = (*scope)->getSymbolObjectbyName(symbolname);
        if (result != C_NULL)
        {
            return (*scope);
        }
    }

    result = globals->getSymbolObjectbyName(symbolname);
    if (result != C_NULL)
    {
        return globals;
    }

    return C_NULL;
}

void ScopeStack::printSymbolTables()
{
    cout << endl << "Symbol Tables:" << endl;
    cout << "==============" << endl;
    globals->printSymbolTable();

    for (auto scope = scopeStack.begin(); scope != scopeStack.end(); ++scope)
    {
        cout << "====================================================================================================" << endl;
        (*scope)->printSymbolTable();
    }
}