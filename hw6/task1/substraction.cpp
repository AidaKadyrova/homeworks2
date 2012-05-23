#include "substraction.h"

Substraction::Substraction(std::string s) : Operation(s)
{
    this->symbol = '-';
}

Substraction::~Substraction() {}

int Substraction::calculate()
{
    return left->calculate() - right->calculate();
}
