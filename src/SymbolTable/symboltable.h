#include <iostream>
#include <unordered_map>
#include <string>
#include "symbol.h"

class SymbolTable
{
private:
    std::unordered_map<std::string, Symbol *> symbolTable;

public:
    void addSymbolInTable(Symbol *symbol);
    void modifySymbolInTable(Symbol *symbol, std::string value);
    void setSymbolByNameInTable(std::string symbolname, std::string value);
    const char *getSymbolByNameInTable(std::string symbolname);
    Symbol *getSymbolObjectbyName(std::string symbolname);
    void removeSymbolFromTable(Symbol *symbol);
    void printSymbolTable();
};