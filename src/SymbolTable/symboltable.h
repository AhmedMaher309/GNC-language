#pragma once
#include <fstream>
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
    void addSymbolsInTable(std::unordered_map<std::string, Symbol *> *symbolTable);
    void modifySymbolInTable(Symbol *symbol, std::string value);
    //void setSymbolByNameInTable(std::string symbolname, std::string value);
    const char *getSymbolByNameInTable(std::string symbolname);
    const char * getSymbolTypeByNameInTable(std::string symbolname);
    Symbol *getSymbolObjectbyName(std::string symbolname);
    void checkSymbolTable(int linenum);
    void removeSymbolFromTable(Symbol *symbol);
    void printSymbolTable();
    void printSymbolTableToFile(std::ofstream* outputFile);
};