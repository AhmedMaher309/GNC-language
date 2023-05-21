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

void Symbol::setConstant(bool isConstant)
{
    this->isConstant = isConstant;
}
void Symbol::setIsInitialised(bool isInitialised)
{
    this->isInitialised = isInitialised;
}

void Symbol::setIsUsed(bool isUsed)
{
    this->isUsed = isUsed;
}

std::string Symbol::getName()
{
    return this->name;
}

const char *Symbol::getNameAsCStr()
{
    std::string str_value = this->name;
    char *cstr_value = new char[str_value.length() + 1];
    str_value.copy(cstr_value, str_value.length());
    cstr_value[str_value.length()] = '\0';
    return cstr_value;
}

std::string Symbol::getVarType()
{
    return this->varType;
}

const char *Symbol::getVarTypeAsCStr()
{
    std::string str_value = this->varType;
    char *cstr_value = new char[str_value.length() + 1];
    str_value.copy(cstr_value, str_value.length());
    cstr_value[str_value.length()] = '\0';
    return cstr_value;
}

std::string Symbol::getValue()
{
    return this->value;
}

const char *Symbol::getValueAsCStr()
{
    std::string str_value = this->value;
    char *cstr_value = new char[str_value.length() + 1];
    str_value.copy(cstr_value, str_value.length());
    cstr_value[str_value.length()] = '\0';
    return cstr_value;
}

bool Symbol::checkConstant()
{
    return this->isConstant;
}
bool Symbol::checkInitialisation()
{
    return this->isInitialised;
}

bool Symbol::checkUsed()
{
    return this->isUsed;
}

void Symbol::print()
{
    cout << this->name << endl;
}

