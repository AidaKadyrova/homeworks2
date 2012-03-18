#include "arraystack.h"
#include "stack.h"
#include <iostream>

using namespace std;

ArrayStack::ArrayStack()
{
    size  = 0;
}

void ArrayStack::push(int n)
{
    value[++size] = n;
}

void ArrayStack::printSize()
{
    cout << size << endl;
}

int ArrayStack::front()
{
    return value[size];
}

int ArrayStack::pop()
{
    return value[size--];
}

void ArrayStack::printStack()
{
    for(int i = size; i > 0; i--)
    {
        cout << value[i] << " ";
    }
    cout << endl;
}
