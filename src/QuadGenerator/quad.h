#pragma once
#include <string>

class Quadruple
{
    private:
    std::string operation;
    std::string operand1;
    std::string operand2;
    std::string destination;

    public:
    Quadruple(std::string operation, std::string operand1, std::string operand2, std::string destination);

    // Setters
    void setOperation(std::string op);
    void setOperand1(std::string op1);
    void setOperand2(std::string op2);
    void setDestination(std::string dest);

    // Getters
    std::string getOperation();
    std::string getOperand1();
    std::string getOperand2();
    std::string getDestination();
};