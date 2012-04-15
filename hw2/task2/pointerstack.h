#pragma once
#include "stack.h"

class PointerStack : public Stack
{
public:
    PointerStack():next(0){}
    ~PointerStack();
    void push(int n);
    int pop();
    int sizeOfStack();
    int front();
    void printStack();
    int at(int i){}

private:
    PointerStack *next;
    int value;
};

