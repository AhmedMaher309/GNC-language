#include <string>

#include "quad.h"

Quadruple::Quadruple(std::string operation, std::string operand1, std::string operand2, std::string destination)
{
    this->operation = operation;
    this->operand1 = operand1;
    this->operand2 = operand2;
    this->destination = destination;
}