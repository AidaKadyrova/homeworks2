#include "digit.h"
#include <iostream>
#include <cstdlib>

Digit::Digit(std::string s)
{
    this->value = atoi(s.c_str());
}

Digit::~Digit() {}

int Digit::calculate()
{
    return this->value;
}

void Digit::print()
{
    std::cout << this->value;
}
