#include <iostream>
#include <unordered_map>
#include <string>
#include "function.h"

#define C_NULL 0

class FunctionTable
{
private:
    std::unordered_map<std::string, Function *> functionTable;

public:
    void addFunctionInTable(Function *function);
    void setFunctionByNameInTable(std::string functionname, bool defined);
    Function *getFunctionObjectbyName(std::string functionname);
    void removeFunctionFromTable(Function *function);
    void printFunctionTable();
};