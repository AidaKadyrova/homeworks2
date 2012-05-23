#include "expression.h"
#include "digit.h"
#include "addition.h"
#include "substraction.h"
#include "multiplication.h"
#include "division.h"

Expression* Expression::parse(std::string s)
{
    if (s[0] == '(')
    {
        switch (s[1])
        {
            case '+':
                return new Addition(s);
            case '-':
                return new Substraction(s);
            case '*':
                return new Multiplication(s);
            case '/':
                return new Division(s);
        }
    }
    else
    {
        return new Digit(s);
    }
    return NULL;
}
