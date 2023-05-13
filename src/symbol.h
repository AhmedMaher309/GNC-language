#include <iostream>
#include <string>
#include <unordered_map>

class Symbol
{
private:
    std::string name;
    std::string varType;
    std::string value = "0xgarbage";
    bool isDeclared = false;
    bool isConstant = false;
    bool isInitialised = false;

public:
    Symbol(std::string name, std::string varType);
    void setName(std::string name);
    void setVarType(std::string varType);
    void setValue(std::string value);
    void setIsDeclared(bool isDeclared);
    void setIsConstant(bool isConstant);
    void setIsInitialised(bool isInitialised);
    void print();

    std::string getName();
    std::string getVarType();
    std::string getValue();
    bool checkDeclared();
    bool checkConstant();
    bool checkInitialisation();
};
