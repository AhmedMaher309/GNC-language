#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

#include "scopestack.h"

using namespace std;

ScopeStack::ScopeStack()
{
    this->globals = new ScopeNode();
    globals->symbolTable = new SymbolTable();
    globals->parent = NULL;
    globals->name = "L0";
    globals->type = "Globals";
    scopeStack = globals;
}

SymbolTable* ScopeStack::addScope()
{
    ScopeNode* newNode = new ScopeNode();
    newNode->symbolTable = new SymbolTable();
    newNode->parent = scopeStack;
    newNode->name = newNode->parent->name + "-" + std::to_string(newNode->parent->children.size());

    scopeStack->children.push_back(newNode);
    scopeStack = newNode;
    return scopeStack->symbolTable;
}

SymbolTable* ScopeStack::removeScope(std::string type)
{
    scopeStack->type = type;
    scopeStack = scopeStack->parent;
    return scopeStack->symbolTable;
}

SymbolTable* ScopeStack::getGlobals()
{
    return globals->symbolTable;
}

SymbolTable* ScopeStack::getSymbolTableFromStack(std::string symbolname)
{
    ScopeNode* current = scopeStack;
    while (current != NULL)
    {
        Symbol* result = current->symbolTable->getSymbolObjectbyName(symbolname);
        if (result != C_NULL)
        {
            return current->symbolTable;
        }
        current = current->parent;
    }
    return C_NULL;
}

void ScopeStack::printSymbolTables(ScopeNode* node, int level)
{
    if (node == NULL)
    {
        node = globals;
    }

    cout << endl;
    cout << right << setfill('=') << setw(2*(level+1)) << "=>" << left << setfill(' ') << node->name << "(" << node->type << ")" << endl;
    cout << left << setw(2*(level+1)) << "" << setfill('=') << setw(node->name.size()) << "" << setfill(' ') << endl;

    node->symbolTable->printSymbolTable();
    cout << "====================================================================================================" << endl;

    for(int i = 0; i < node->children.size(); ++i)
    {
        printSymbolTables(node->children[i], level+1);
    }
}

void ScopeStack::printSymbolTablesToFile(ScopeNode* node, int level, ofstream* outputFile)
{
    ofstream* output = outputFile;

    if (node == NULL)
    {
        node = globals;
        output = new ofstream("compiling_results/SymbolTables.txt");

        // Check if the file was opened successfully
        if (!output)
        {
            cerr << "Error opening file." << endl;
            return;
        }
    }

    (*output) << endl;
    (*output) << right << setfill('=') << setw(2*(level+1)) << "=>" << left << setfill(' ') << node->name << "(" << node->type << ")" << endl;
    (*output) << left << setw(2*(level+1)) << "" << setfill('=') << setw(node->name.size()) << "" << setfill(' ') << endl;

    node->symbolTable->printSymbolTableToFile(output);
    (*output) << "====================================================================================================" << endl;

    for(int i = 0; i < node->children.size(); ++i)
    {
        printSymbolTablesToFile(node->children[i], level+1, output);
    }
}
