#include "array.h"
#include "list.h"
#include <iostream>

using namespace std;

void Array::addToBegin(int n)
{
    for(int i = size; i > 0; i--)
    {
        mas[i] = mas[i - 1];
    }
    mas[0] = n;
    size++;
}

void Array::addToEnd(int n)
{
    mas[size] = n;
    size++;
}

void Array::printList()
{
    for(int i = 0; i < size; i++)
        cout << mas[i] << ' ';
    cout << endl;
}

void Array::printSize()
{
    cout << "there are " << size << " elements" << endl;
}

void Array::addToThePosition(int n, int position)
{
    for(int i = size; i > position - 1; i--)
        mas[i] = mas[i - 1];
    mas[position - 1] = n;
    size++;

}

void Array::deleteElement(int n)
{
    for(int i = 0; i < size; i++)
    {
        if (mas[i] == n)
        {
            for(int j = i; j < size; j++)
                mas[j] = mas[j+1];
            size--;
        }
    }
}

bool Array::isElement(int n)
{
    for(int i = 0; i < size; i++)
        if (mas[i] == n)
        {
            return true;
        }
    return false;
}

