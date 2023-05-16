#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>

#include "functiontable.h"

using namespace std;

void FunctionTable::addFunctionInTable(Function *function)
{
    functionTable[function->getName()] = function;
}

void FunctionTable::setFunctionByNameInTable(std::string functionname, bool defined)
{
    if (functionTable.find(functionname) != functionTable.end())
    {
        functionTable[functionname]->setIsDefined(defined);
    }
}

Function *FunctionTable::getFunctionObjectbyName(std::string functionname)
{
    if (functionTable.find(functionname) != functionTable.end())
    {
        return functionTable[functionname];
    }
    return C_NULL;
}

void FunctionTable::removeFunctionFromTable(Function *function)
{
    functionTable.erase(function->getName());
}

void FunctionTable::printFunctionTable()
{
    cout << endl;
    cout << left << setw(20) << "function name" << setw(20) << "function type" << setw(15) << "is defined" << endl;
    for (auto x : functionTable)
    {
        cout << left << setw(20) << x.second->getName() << setw(20) << x.second->getVarType() << setw(15) << x.second->checkDefinition() << endl;
    }
    cout << endl
         << endl;
}