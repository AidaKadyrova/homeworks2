#include "division.h"

Division::Division(std::string s) : Operation(s)
{
    this->symbol = '/';
}

Division::~Division() {}

int Division::calculate()
{
    return left->calculate() / right->calculate();
}
