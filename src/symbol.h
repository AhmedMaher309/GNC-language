#include <iostream>
#include <string>
#include <unordered_map>

class Symbol {
private:
    std::string name;
    std::string varType;
    std::string value = "0xgarbage";
    bool isDeclared = false;

public:
    Symbol(std::string name, std::string varType);
    void setName(std::string name);
    void setVarType(std::string varType);
    void setValue(std::string value);
    void setIsDeclared(bool isDeclared);
    void print();

    std::string getName();
    std::string getVarType();
    std::string getValue();
    bool checkDeclared();
};
