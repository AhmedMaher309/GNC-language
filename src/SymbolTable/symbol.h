#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

#define C_NULL 0

class Symbol
{
private:
    std::string name;
    std::string varType;
    std::string value = "0xgarbage";
    bool isConstant = false;
    bool isInitialised = false;
    bool isUsed = false;

public:
    Symbol(std::string name, std::string varType);
    void setName(std::string name);
    void setVarType(std::string varType);
    void setValue(std::string value);
    void setIsConstant(bool isConstant);
    void setIsInitialised(bool isInitialised);
    void setIsUsed(bool isUsed);
    void print();

    std::string getName();
    std::string getVarType();
    std::string getValue();
    bool checkConstant();
    bool checkInitialisation();
    bool checkUsed();

};
