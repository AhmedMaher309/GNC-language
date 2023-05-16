#include <iostream>
#include <string>

#include "function.h"

using namespace std;

Function::Function(std::string name, std::string varType)
{
    this->name = name;
    this->varType = varType;
}

void Function::setName(std::string name)
{
    this->name = name;
}

void Function::setVarType(std::string varType)
{
    this->varType = varType;
}

void Function::setIsDefined(bool isDefined)
{
    this->isDefined = isDefined;
}

std::string Function::getName()
{
    return this->name;
}

std::string Function::getVarType()
{
    return this->varType;
}

bool Function::checkDefinition()
{
    return this->isDefined;
}

void Function::print()
{
    cout << this->name << endl;
}