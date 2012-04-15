#include "arraystack.h"
#include "stack.h"
#include <iostream>

using namespace std;

void ArrayStack::push(int n)
{
    value[++size] = n;
}

int ArrayStack::sizeOfStack()
{
    return size;
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


int ArrayStack::at(int i)
{
    return value[i];
}
