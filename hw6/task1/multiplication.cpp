#include "multiplication.h"

Multiplication::Multiplication(std::string s) : Operation(s)
{
    this->symbol = '*';
}

Multiplication::~Multiplication() {}

int Multiplication::calculate()
{
    return left->calculate() * right->calculate();
}
