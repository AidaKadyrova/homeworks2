#pragma once
#include "expression.h"

/**
  * @class abstract class - operation with four heirs:
  * addition, division, sustruction and multiplication
  */
class Operation : public Expression
{
public:
    Operation(std::string s);
    virtual ~Operation() = 0;
    virtual int calculate() = 0;
    void print();
protected:
    char symbol;
    Expression *left;
    Expression *right;
};
