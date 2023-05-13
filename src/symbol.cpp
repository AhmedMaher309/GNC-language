#include <iostream>
#include <string>

#include "symbol.h"

using namespace std;

Symbol::Symbol(std::string name, std::string varType)
{
    this->setName(name);
    this->setVarType(varType);
}

void Symbol::setName(std::string name)
{
    this->name = name;
}

void Symbol::setVarType(std::string varType)
{
    this->varType = varType;
}

void Symbol::setValue(std::string value)
{
    this->value = value;
}

void Symbol::setIsDeclared(bool isDeclared)
{
    this->isDeclared = isDeclared;
}
void Symbol::setIsConstant(bool isConstant)
{
    this->isConstant = isConstant;
}
void Symbol::setIsInitialised(bool isInitialised)
{
    this->isInitialised = isInitialised;
}

std::string Symbol::getName()
{
    return this->name;
}

std::string Symbol::getVarType()
{
    return this->varType;
}

std::string Symbol::getValue()
{
    return this->value;
}

bool Symbol::checkDeclared()
{
    return this->isDeclared;
}
bool Symbol::checkConstant()
{
    return this->isConstant;
}
bool Symbol::checkInitialisation()
{
    return this->isInitialised;
}

void Symbol::print()
{
    cout << this->name << endl;
}
