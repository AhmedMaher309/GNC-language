#include <string>

#include "quad.h"

Quadruple::Quadruple(std::string operation, std::string operand1, std::string operand2, std::string destination)
{
    this->operation = operation;
    this->operand1 = operand1;
    this->operand2 = operand2;
    this->destination = destination;
}

// Setter implementations
void Quadruple::setOperation(std::string op)
{
    operation = op;
}

void Quadruple::setOperand1(std::string op1)
{
    operand1 = op1;
}

void Quadruple::setOperand2(std::string op2)
{
    operand2 = op2;
}

void Quadruple::setDestination(std::string dest)
{
    destination = dest;
}

// Getter implementations
std::string Quadruple::getOperation()
{
    return operation;
}

std::string Quadruple::getOperand1()
{
    return operand1;
}

std::string Quadruple::getOperand2()
{
    return operand2;
}

std::string Quadruple::getDestination()
{
    return destination;
}