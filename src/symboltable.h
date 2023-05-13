#include <iostream>
#include <unordered_map>
#include <string>
#include "symbol.h"
using namespace std;

class SymbolTable
{
private:
    unordered_map<string, Symbol *> symbolTable;

public:
    void addSymbolInTable(Symbol *symbol);
    void modifySymbolInTable(Symbol *symbol, string value);
    void setSymbolByNameInTable(string symbolname, string value);
    const char *getSymbolByNameInTable(string symbolname);
    void removeSymbolFromTable(Symbol *symbol);
    void printSymbolTable();
};