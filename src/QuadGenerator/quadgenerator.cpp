#include <iostream>
#include <string>
#include <iomanip>

#include "quadgenerator.h"

using namespace std;

int QuadGenerator::count = 0;

void QuadGenerator::startScope(int sLine)
{
    scopes.push(new Scope(sLine));
}

void QuadGenerator::endScope(int eLine, std::string name)
{
    Scope* closedScope = scopes.top();

    closedScope->eLine = eLine;
    closedScope->name = name + std::to_string(count);
    count++;

    /*ADD SCOPE TYPE SPECIFIC LINES*/
    quadList.push_back(new Quadruple(closedScope->name,to_string(closedScope->sLine),to_string(closedScope->eLine),"TEMP"));
    /*OUTPUT QUADS TO FILE*/

    
    scopes.pop();
}

void QuadGenerator::addQuad(std::string operation, std::string operand1, std::string operand2, std::string destination)
{
    quadList.push_back(new Quadruple(operation,operand1,operand2,destination));
}

void QuadGenerator::printQuads()
{
    cout << left << setw(20) << "operation" << setw(20) << "operand1" << setw(20) << "operand2" << setw(20) << "destination" << endl;
    for (int i = 0; i < quadList.size(); i++)
    {
        cout << left << setw(20) << quadList[i]->operation << setw(20) << quadList[i]->operand1 << setw(20) << quadList[i]->operand2 << setw(20) << quadList[i]->destination << endl;
    }
}