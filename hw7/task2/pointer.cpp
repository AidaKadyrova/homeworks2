//hw2 task1
#include "pointer.h"
#include <iostream>

using namespace std;

Pointer::~Pointer()
{
    delete next;
}

void Pointer::addToBegin(int n)
{
    Pointer *tmp = new Pointer;
    tmp->value = n;
    tmp->next = next;
    next = tmp;
    size++;
}

void Pointer::addToEnd(int n)
{
    Pointer *tmp = this;
    Pointer *temp = new Pointer;
    temp->value = n;

    while (tmp->next)
        tmp = tmp->next;
    tmp->next = temp;
    size++;
}

void Pointer::printList()
{
    if (!next)
        cout << "list is empty";
    else
    {
        Pointer *tmp = this;
        while (tmp->next)
        {
            tmp = tmp->next;
            cout << tmp->value << " ";
        }
    }
    cout << endl;
}

void Pointer::addToThePosition(int n, int position)
{
    if (position - 1 > size)
    {
        cout << "wrong position" << endl;
        return;
    }
    else
        {
            Pointer *tmp = this;
            for(int i = 0; i < position - 1; i++)
                tmp = tmp->next;
            Pointer *temp = new Pointer;
            temp->value = n;

            temp->next = tmp->next;
            tmp->next = temp;
            size++;
        }
}

bool Pointer::isElement(int n)
{
    if (!next)
    {
        return false;
    }
    Pointer *tmp = this;
    while (tmp->next)
    {
        if (tmp->value == n)
            return true;
        tmp = tmp->next;
    }
    if (tmp->value == n)
        return true;
    return false;
}


void Pointer::deleteElement(int n)
{
    Pointer *tmp = this;
    while (tmp->next && n != tmp->next->value)
        tmp = tmp->next;
    if (!tmp->next)
        return;
    Pointer *temp = tmp->next->next;
    delete tmp->next;
    tmp->next = temp;
    size--;
}

int Pointer::sizeOfList()
{
    return size;
}

int Pointer::at(int i)
{
    Pointer *tmp = this;
    if (i < size)
        for (int j = 0; j <= i; j++)
            tmp = tmp->next;
    return tmp->value;
}
