#pragma once
#include "operation.h"
/**
  * @class implements the addition
  */
class Addition: public Operation
{
public:
    Addition(std::string s);
    ~Addition();
    int calculate();
};
