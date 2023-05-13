#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>

#include "symboltable.h"

using namespace std;

void SymbolTable::addSymbolInTable(Symbol *symbol)
{
    symbolTable[symbol->getName()] = symbol;
}

void SymbolTable::modifySymbolInTable(Symbol *symbol, string value)
{
    if (symbolTable.find(symbol->getName()) != symbolTable.end())
    {
        symbolTable[symbol->getName()]->setValue(value);
        symbolTable[symbol->getName()]->setIsDeclared(true);
        if (value.length() != 0)
            symbolTable[symbol->getName()]->setIsInitialised(true);
    }
}

void SymbolTable::setSymbolByNameInTable(string symbolname, string value)
{
    if (symbolTable.find(symbolname) != symbolTable.end())
    {
        symbolTable[symbolname]->setValue(value);
        symbolTable[symbolname]->setIsDeclared(true);
        if (value.length() != 0)
            symbolTable[symbolname]->setIsInitialised(true);
    }
}

string SymbolTable::getSymbolByNameInTable(string symbolname)
{
    if (symbolTable.find(symbolname) != symbolTable.end())
    {
        return symbolTable[symbolname]->getValue();
    }
    return "";
}

void SymbolTable::removeSymbolFromTable(Symbol *symbol)
{
    symbolTable.erase(symbol->getName());
}

void SymbolTable::printSymbolTable()
{
    cout << endl;
    cout << left << setw(20) << "variable name" << setw(20) << "variable type" << setw(20) << "variable value" << setw(15) << "is declared" << setw(15) << "is constant" << setw(15) << "is initialised" << setw(20) << "memory location" << endl;
    for (auto x : symbolTable)
    {
        cout << left << setw(20) << x.first << setw(20) << x.second->getVarType() << setw(20) << x.second->getValue() << setw(15) << x.second->checkDeclared() << setw(15) << x.second->checkConstant() << setw(15) << x.second->checkInitialisation() << setw(20) << x.second << endl;
    }
    cout << endl
         << endl;
}