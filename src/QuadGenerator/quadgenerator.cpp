#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "quadgenerator.h"

using namespace std;

int QuadGenerator::labelCount = 0;

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

    /*TYPES: if, else, FUNCTION NAME, for, while, repeat, switch, case, enum */
    if (type == "if")
    {
        addQuad("JN","T"+to_string(temps.size()),"","L"+to_string(labelCount));
        parentList->insert(parentList->end(),closedList->begin(),closedList->end());
        addQuad("L"+to_string(labelCount)+":","","","");

        labelCount++;
    }
    else if (type == "else")
    {
        parentList->insert(parentList->end(),closedList->begin(),closedList->end());
    }
    else if (type == "for")
    {
        /*ADD SCOPE TYPE SPECIFIC QUADS*/
        addQuad(type,"__________","__________","__________");

        /*ADD CLOSED SCOPE QUADS TO PARENT LIST*/
        parentList->insert(parentList->end(),closedList->begin(),closedList->end());

        /*ADD SCOPE TYPE SPECIFIC QUADS*/
        addQuad(type,"__________","__________","__________");

        /*INCREASE COUNT OF LABELS*/
        labelCount++;
    }
    else if (type == "while")
    {
        /*ADD SCOPE TYPE SPECIFIC QUADS*/
        addQuad(type,"__________","__________","__________");

        /*ADD CLOSED SCOPE QUADS TO PARENT LIST*/
        parentList->insert(parentList->end(),closedList->begin(),closedList->end());

        /*ADD SCOPE TYPE SPECIFIC QUADS*/
        addQuad(type,"__________","__________","__________");

        /*INCREASE COUNT OF LABELS*/
        labelCount++;
    }
    else if (type == "repeat")
    {
        /*ADD SCOPE TYPE SPECIFIC QUADS*/
        addQuad(type,"__________","__________","__________");

        /*ADD CLOSED SCOPE QUADS TO PARENT LIST*/
        parentList->insert(parentList->end(),closedList->begin(),closedList->end());

        /*ADD SCOPE TYPE SPECIFIC QUADS*/
        addQuad(type,"__________","__________","__________");

        /*INCREASE COUNT OF LABELS*/
        labelCount++;
    }
    else if (type == "switch")
    {
        /*ADD SCOPE TYPE SPECIFIC QUADS*/
        addQuad(type,"__________","__________","__________");

        /*ADD CLOSED SCOPE QUADS TO PARENT LIST*/
        parentList->insert(parentList->end(),closedList->begin(),closedList->end());

        /*ADD SCOPE TYPE SPECIFIC QUADS*/
        addQuad(type,"__________","__________","__________");

        /*INCREASE COUNT OF LABELS*/
        labelCount++;
    }
    else if (type == "case")
    {
        /*ADD SCOPE TYPE SPECIFIC QUADS*/
        addQuad(type,"__________","__________","__________");

        /*ADD CLOSED SCOPE QUADS TO PARENT LIST*/
        parentList->insert(parentList->end(),closedList->begin(),closedList->end());

        /*ADD SCOPE TYPE SPECIFIC QUADS*/
        addQuad(type,"__________","__________","__________");

        /*INCREASE COUNT OF LABELS*/
        labelCount++;
    }
    else if (type == "enum")
    {
        parentList->insert(parentList->end(),closedList->begin(),closedList->end());

    }
    else
    {
        addQuad(type+":","","","");
        parentList->insert(parentList->end(),closedList->begin(),closedList->end());
        addQuad("RET","T"+to_string(temps.size()),"","");

        labelCount++;
    }

    clearTemps();
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
    temps["T"+to_string(temps.size())] = expr1 + op + expr2;
    
    std::string str_value = "T"+to_string(temps.size()-1);
    char *cstr_value = new char[str_value.length() + 1];
    str_value.copy(cstr_value, str_value.length());
    cstr_value[str_value.length()] = '\0';
    return cstr_value;
}

const char *QuadGenerator::getTemp(std::string temp)
{
    std::string str_value = temps[temp];
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

void QuadGenerator::printQuadsToFile()
{
    // Open the file for writing
    ofstream outputFile("quadruples.txt");

    // Check if the file was opened successfully
    if (!outputFile)
    {
        cerr << "Error opening file." << endl;
        return;
    }

    outputFile << "START main" << endl << endl;

    // Write the quadruples to the file
    for (int i = 0; i < quads->size(); i++)
    {
        outputFile << left << setw(20) << (*quads)[i]->getOperation() << setw(6) << (*quads)[i] -> getOperand1() << setw(6) << (*quads)[i] -> getOperand2() << setw(6) << (*quads)[i] -> getDestination() << endl;
    }

    // Close the file
    outputFile.close();
}