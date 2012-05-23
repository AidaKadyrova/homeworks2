#pragma once
#include "operation.h"

/**
  * @class implements the multiplication
  */
class Multiplication: public Operation
{
public:
    Multiplication(std::string s);
    ~Multiplication();
    int calculate();
};
