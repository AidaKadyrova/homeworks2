#pragma once
#include "operation.h"

/**
  * @class implements the division
  */
class Division: public Operation
{
public:
    Division(std::string s);
    ~Division();
    int calculate();
};
