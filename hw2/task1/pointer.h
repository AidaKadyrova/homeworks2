#pragma once
#include "list.h"

class Pointer : public List
{
public:
    Pointer();
    void addToBegin(int n);
    void addToEnd(int n);
    void addToThePosition(int n, int position);
    void isElement(int n);
    void deleteElement(int n);
    void deleteList();
    void printSize();
    void printList();
private:
    int value;
    Pointer* next;
    int size;
};
