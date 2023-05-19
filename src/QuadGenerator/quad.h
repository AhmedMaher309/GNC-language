#include <string>

class Quadruple
{
    public:
    std::string operation;
    std::string operand1;
    std::string operand2;
    std::string destination;

    public:
    Quadruple(std::string operation, std::string operand1, std::string operand2, std::string destination);
};