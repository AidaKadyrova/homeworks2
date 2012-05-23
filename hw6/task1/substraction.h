#pragma once
#include "operation.h"
/**
  * @class implements the substraction
  */
class Substraction: public Operation
{
public:
    Substraction(std::string s);
    ~Substraction();
    int calculate();
};
