#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <string>

#include "quad.h"
#include "../SymbolTable/symbol.h"

class QuadGenerator
{
private:
    std::vector<Quadruple*>* quads;
    std::stack<std::vector<Quadruple*>*> scopes;
    std::unordered_map<Symbol*, std::string> assignments;
    std::unordered_map<std::string, std::string> temps;

public:
    static int labelCount;
    QuadGenerator();
    void startScope();
    void endScope(std::string type);
    const char *addAssignment(Symbol* sym);
    const char *getAssignment(Symbol* sym);
    const char *addTemp(std::string expr1, std::string op, std::string expr2);
    const char *getTemp(std::string name);
    void clearTemps();
    void addQuad(std::string operation, std::string operand1, std::string operand2, std::string destination);
    void printQuads();
    void printQuadsToFile();
};

