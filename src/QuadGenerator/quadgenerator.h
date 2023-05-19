#include <iostream>
#include <vector>
#include <stack>
#include <string>

#include "quad.h"

struct Scope
{
    std::string name;
    int sLine;
    int eLine;

    Scope(int _sLine)
    {
        sLine = _sLine;
    }
};

class QuadGenerator
{
private:
    std::stack<Scope*> scopes;
    std::vector<Quadruple*> quadList;

public:
    static int count;
    void startScope(int sLine);
    void endScope(int eLine, std::string name);
    void addQuad(std::string operation, std::string operand1, std::string operand2, std::string destination);
    void printQuads();
};

