#pragma once
#include "stack.h"

class ArrayStack : public Stack
{
public:
    ArrayStack():size(0){}
    ~ArrayStack(){}
    void push(int n);
    int pop();
    int sizeOfStack();
    int front();
    void printStack();
    int at(int i);
private:
    static const int dim = 1000;
    int value[dim];
    int size;
};

