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

void SymbolTable::addSymbolsInTable(std::unordered_map<std::string, Symbol *> *symbolTable)
{
    this->symbolTable = *symbolTable;
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

// void SymbolTable::setSymbolByNameInTable(std::string symbolname, std::string value)
// {
//     if (symbolTable.find(symbolname) != symbolTable.end())
//     {
//         symbolTable[symbolname]->setValue(value);
//         if (value.length() != 0)
//             symbolTable[symbolname]->setIsInitialised(true);
//     }
// }

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
    cout << left << setw(15) << "variable name" << setw(15) << "variable type" << setw(15) << "variable value" << setw(15) << "is constant" << setw(15) << "is initialised" << setw(15) << "is Used" << setw(15) << "memory location" << endl;
    for (auto x : symbolTable)
    {
        cout << left << setw(15) << x.first << setw(15) << x.second->getVarType() << setw(15) << x.second->getValue() << setw(15) << x.second->checkConstant() << setw(15) << x.second->checkInitialisation() << setw(15) << x.second->checkUsed() << setw(15) << x.second << endl;
    }
    cout << endl
         << endl;
}

const char *SymbolTable::getSymbolTypeByNameInTable(std::string symbolname)
{
    if (symbolTable.find(symbolname) != symbolTable.end())
    {
        std::string str_value = symbolTable[symbolname]->getVarType();
        char *cstr_value = new char[str_value.length() + 1];
        str_value.copy(cstr_value, str_value.length());
        cstr_value[str_value.length()] = '\0';
        return cstr_value;
    }
    return C_NULL;
}

// loop on symbol table and check if the symbol is used or not
void SymbolTable::checkSymbolTable()
{
    for (auto x : symbolTable)
    {
        if (x.second->checkUsed() == false)
        {
            cout << "Warning: variable " << x.first << " is declared but not used" << endl;
        }
    }
}
