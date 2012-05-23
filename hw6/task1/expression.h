#pragma once
#include <string>
/**
  * @class - abstract class, which can parse an expression
  * and has 2 virtual  methods(calculate and print)
  *
  */
class Expression
{
public:
    static Expression* parse(std::string s);
    virtual int calculate() = 0;
    virtual void print() = 0;
};
