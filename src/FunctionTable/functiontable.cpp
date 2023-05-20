#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>

#include "functiontable.h"

using namespace std;

void FunctionTable::addFunctionInTable(Function *function)
{
    if(checkExistFunction(function->getName()))
    {
        functionTable[function->getName()] = function;
    }
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
    cout << left << setw(20) << "function name" << setw(20) << "function type" << setw(15) << "is defined" << "parameters" << endl;
    for (auto x : functionTable)
    {
        cout << left << setw(20) << x.second->getName() << setw(20) << x.second->getVarType() << setw(15) << x.second->checkDefinition();
        
        int count = x.second->getCount();
        for(int i = 0; i < count; i++)
        {
            Symbol* param = x.second->getParameter(i);
            cout << i << ": " << param->getVarType() << " " << param->getName();
            if (i != count - 1)
            {
                cout << ", ";
            }
        }

        cout << endl;
    }
    cout << endl
         << endl;
}

bool FunctionTable::checkExistFunction(std::string functionName){
    for (auto x : functionTable){
        if (x.first == functionName){
            cout<<"error, function with the same name already exists"<<endl;
            return false;
        }
    }
    return true;
}

void FunctionTable::printFunctionTableToFile()
{
    // Open the file for writing
    ofstream outputFile("FunctionTable.txt");

    // Check if the file was opened successfully
    if (!outputFile)
    {
        cerr << "Error opening file." << endl;
        return;
    }

    outputFile << endl;
    outputFile << left << setw(20) << "function name" << setw(20) << "function type" << setw(15) << "is defined" << "parameters" << endl;
    for (auto x : functionTable)
    {
        outputFile << left << setw(20) << x.second->getName() << setw(20) << x.second->getVarType() << setw(15) << x.second->checkDefinition();
        
        int count = x.second->getCount();
        for(int i = 0; i < count; i++)
        {
            Symbol* param = x.second->getParameter(i);
            outputFile << i << ": " << param->getVarType() << " " << param->getName();
            if (i != count - 1)
            {
                outputFile << ", ";
            }
        }

        outputFile << endl;
    }
    outputFile << endl
         << endl;
}