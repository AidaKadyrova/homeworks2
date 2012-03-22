#pragma once
#include "stack.h"

class PointerStack : public Stack
{
public:
    PointerStack():next(0){}
    ~PointerStack();
    void push(int n);
    int pop();
    void printSize();
    int front();
    void printStack();
private:
    PointerStack *next;
    int value;
};

