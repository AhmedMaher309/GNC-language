#include <iostream>
#include <string>
#include <iomanip>

#include "quadgenerator.h"

using namespace std;

int QuadGenerator::count = 0;

QuadGenerator::QuadGenerator()
{
    quads = new vector<Quadruple*>();
    scopes.push(quads);
}

void QuadGenerator::startScope()
{
    scopes.push(new vector<Quadruple*>());
}

void QuadGenerator::endScope(std::string type)
{
    vector<Quadruple*>* closedList = scopes.top();
    scopes.pop();

    vector<Quadruple*>* parentList = scopes.top(); 

    /*ADD SCOPE TYPE SPECIFIC QUADS*/
    addQuad(type,"__________","__________","__________");

    /*ADD CLOSED SCOPE QUADS TO PARENT LIST*/
    parentList->insert(parentList->end(),closedList->begin(),closedList->end());

    /*INCREASE COUNT OF LABELS*/
    count++;
}

const char *QuadGenerator::addAssignment(Symbol* sym)
{
    assignments[sym] = "R"+to_string(assignments.size());

    std::string str_value = assignments[sym];
    char *cstr_value = new char[str_value.length() + 1];
    str_value.copy(cstr_value, str_value.length());
    cstr_value[str_value.length()] = '\0';
    return cstr_value;
}

const char *QuadGenerator::getAssignment(Symbol* sym)
{
    std::string str_value = assignments[sym];
    char *cstr_value = new char[str_value.length() + 1];
    str_value.copy(cstr_value, str_value.length());
    cstr_value[str_value.length()] = '\0';
    return cstr_value;
}

const char *QuadGenerator::addTemp(std::string expr1, std::string op, std::string expr2)
{
    temps[expr1 + op + expr2] = "T"+to_string(temps.size());
    
    std::string str_value = temps[expr1 + op + expr2];
    char *cstr_value = new char[str_value.length() + 1];
    str_value.copy(cstr_value, str_value.length());
    cstr_value[str_value.length()] = '\0';
    return cstr_value;
}

void QuadGenerator::clearTemps()
{
    temps.clear();
}

void QuadGenerator::addQuad(std::string operation, std::string operand1, std::string operand2, std::string destination)
{
    scopes.top()->push_back(new Quadruple(operation,operand1,operand2,destination));
}

void QuadGenerator::printQuads()
{
    cout << left << setw(20) << "operation" << setw(20) << "operand1" << setw(20) << "operand2" << setw(20) << "destination" << endl;
    for (int i = 0; i < quads->size(); i++)
    {
        cout << left << setw(20) << (*quads)[i]->getOperation() << setw(20) << (*quads)[i] -> getOperand1() << setw(20) << (*quads)[i] -> getOperand2() << setw(20) << (*quads)[i] -> getDestination() << endl;
    }
}