#include <iostream>
#include <string>
#include <unordered_map>

class Function
{
private:
    std::string name;
    std::string varType;
    bool isDefined = false;

public:
    Function(std::string name, std::string varType);
    void setName(std::string name);
    void setVarType(std::string varType);
    void setIsDefined(bool isDefined);
    void print();

    std::string getName();
    std::string getVarType();
    std::string getValue();
    bool checkDefinition();
};
