#include "pointerstack.h"
#include "stack.h"
#include <iostream>

using namespace std;

PointerStack::PointerStack()
{
    next = NULL;
}

void PointerStack::push(int n)
{
    PointerStack *tmp = new PointerStack;
    tmp->value = n;
    tmp->next = next;
    next = tmp;
}

void PointerStack::printStack()
{
    if (!next)
        cout << "stack is empty";
    else
    {
        PointerStack *tmp = this;
        while (tmp->next)
        {
            tmp = tmp->next;
            cout << tmp->value << " ";
        }
    }
    cout << endl;
}

int PointerStack::pop()
{
    if (!next)
        return 0;
    PointerStack *temp = next->next;
    int n = next->value;
    delete next;
    next = temp;
    return n;
}

int PointerStack::front()
{
    return next->value;
}

void PointerStack::printSize()
{
    int count = 0;
    PointerStack *tmp = this;
    while (tmp->next)
    {
        tmp = tmp->next;
        count++;
    }
    cout << count << endl;
}
