#pragma once
#include "list.h"

class Array : public List
{
public:
    Array();
    void addToBegin(int n);
    void addToEnd(int n);
    void addToThePosition(int n, int position);
    void isElement(int n);
    void deleteList();
    void deleteElement(int n);
    void printSize();
    void printList();
private:
    static const int dim = 1000;
    int mas[dim];
    int size;
};
