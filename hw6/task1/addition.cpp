#include "addition.h"

Addition::Addition(std::string s) : Operation(s)
{
    this->symbol = '+';
}

Addition::~Addition() {}

int Addition::calculate()
{
    return left->calculate() + right->calculate();
}
