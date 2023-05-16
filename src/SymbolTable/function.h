#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include "symbol.h"

class Function
{
private:
    std::string name;
    std::string varType;
    std::unordered_map<int, Symbol *> parameters;
    int count = 0;
    bool isDefined = false;

public:
    Function(std::string name, std::string varType);
    void setName(std::string name);
    void setVarType(std::string varType);
    void addParameter(Symbol* symbol);
    void setIsDefined(bool isDefined);
    void print();

    std::string getName();
    std::string getVarType();
    Symbol* getParameter(int index);
    int getCount();
    bool checkDefinition();
};
