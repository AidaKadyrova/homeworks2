#pragma once
#include "list.h"

class Array : public List
{
public:
    Array():size(0){}
    ~Array(){}
    void addToBegin(int n);
    void addToEnd(int n);
    void addToThePosition(int n, int position);
    bool isElement(int n);
    void deleteElement(int n);
    int sizeOfList();
    void printList();
    int at(int i);

private:
    static const int dim = 1000;
    int mas[dim];
    int size;
};
