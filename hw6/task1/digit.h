#pragma once
#include "expression.h"
/**
  * @class Digit can calculate and print itself
  *
  */
class Digit : public Expression
{
public:
    Digit(std::string s);
    ~Digit();
    int calculate();
    void print();
protected:
    int value;
};

