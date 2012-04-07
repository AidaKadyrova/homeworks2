#pragma once
#include "stack.h"

class ArrayStack : public Stack
{
public:
    ArrayStack():size(0){}
    ~ArrayStack(){}
    void push(int n);
    int pop();
    void printSize();
    int front();
    void printStack();
//private:
    static const int dim = 1000;
    int value[dim];
    int size;
};

