#pragma once

class Stack
{
public:
    virtual~Stack(){}
    virtual int pop() = 0;
    virtual void push(int n) = 0;
    virtual int sizeOfStack() = 0;
    virtual int front() = 0;
    virtual void printStack() = 0;
    virtual int at(int i) = 0;
};
