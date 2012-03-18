#include "pointer.h"
#include "list.h"
#include <iostream>

using namespace std;

Pointer::Pointer()
{
    next = NULL;
    size = 0;
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

void Pointer::isElement(int n)
{
    if (!next)
    {
        cout << "no, because the list list is empty" << endl;
        return;
    }
    Pointer *tmp = this;
    while (tmp->next)
    {
        if (tmp->value == n)
        {
            cout << "yes" << endl;
            return;
        }
        tmp = tmp->next;
    }
    cout << "no" << endl;
    \
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
}

void Pointer::deleteList()
{
    delete next;
    next = NULL;
}

void Pointer::printSize()
{
    cout << "there are " << size << " elements in list" << endl;
}
