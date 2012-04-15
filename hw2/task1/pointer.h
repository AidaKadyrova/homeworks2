#pragma once
#include "list.h"

class Pointer : public List
{
public:
    Pointer():next(0),size(0){}
    ~Pointer();
    void addToBegin(int n);
    void addToEnd(int n);
    void addToThePosition(int n, int position);
    bool isElement(int n);
    void deleteElement(int n);
    int sizeOfList();
    void printList();
    int at(int i);
private:
    int value;
    Pointer* next;
    int size;
};
