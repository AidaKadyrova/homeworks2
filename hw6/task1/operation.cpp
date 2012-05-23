#include "operation.h"
#include <iostream>

Operation::Operation(std::string s)
{
    int level = 0, middle = -1;
    for (size_t i = 3; i < s.size(); ++i)
    {
        if (s[i] == '(')
            level++;
        if (s[i] == ')')
            level--;
        if (s[i] == ' ' && level == 0)
            middle = i;
    }
    left = Expression::parse(s.substr(3, middle - 3));
    right = Expression::parse(s.substr(middle + 1, s.size() - middle - 2));
}

Operation::~Operation()
{
    delete left;
    delete right;
}

void Operation::print()
{
    std::cout << "(" << this->symbol << " ";
    left->print();
    std::cout << " ";
    right->print();
    std::cout << ")";
}
