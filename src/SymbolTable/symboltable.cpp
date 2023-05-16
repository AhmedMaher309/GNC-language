#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>

#include "symboltable.h"

#define C_NULL 0

using namespace std;

void SymbolTable::addSymbolInTable(Symbol *symbol)
{
    symbolTable[symbol->getName()] = symbol;
}

void SymbolTable::modifySymbolInTable(Symbol *symbol, std::string value)
{
    if (symbolTable.find(symbol->getName()) != symbolTable.end())
    {
        symbolTable[symbol->getName()]->setValue(value);
        if (value.length() != 0)
            symbolTable[symbol->getName()]->setIsInitialised(true);
    }
}

void SymbolTable::setSymbolByNameInTable(std::string symbolname, std::string value)
{
    if (symbolTable.find(symbolname) != symbolTable.end())
    {
        symbolTable[symbolname]->setValue(value);
        if (value.length() != 0)
            symbolTable[symbolname]->setIsInitialised(true);
    }
}

const char *SymbolTable::getSymbolByNameInTable(std::string symbolname)
{
    if (symbolTable.find(symbolname) != symbolTable.end())
    {
        std::string str_value = symbolTable[symbolname]->getValue();
        char *cstr_value = new char[str_value.length() + 1];
        str_value.copy(cstr_value, str_value.length());
        cstr_value[str_value.length()] = '\0';
        return cstr_value;
    }
    return C_NULL;
}

Symbol *SymbolTable::getSymbolObjectbyName(std::string symbolname)
{
    if (symbolTable.find(symbolname) != symbolTable.end())
    {
        return symbolTable[symbolname];
    }
    return C_NULL;
}
void SymbolTable::removeSymbolFromTable(Symbol *symbol)
{
    symbolTable.erase(symbol->getName());
}

void SymbolTable::printSymbolTable()
{
    cout << endl;
    cout << left << setw(20) << "variable name" << setw(20) << "variable type" << setw(20) << "variable value" << setw(15) << "is constant" << setw(20) << "is initialised" << setw(20) << "memory location" << endl;
    for (auto x : symbolTable)
    {
        cout << left << setw(20) << x.first << setw(20) << x.second->getVarType() << setw(20) << x.second->getValue() << setw(15) << x.second->checkConstant() << setw(20) << x.second->checkInitialisation() << setw(20) << x.second << endl;
    }
    cout << endl
         << endl;
}