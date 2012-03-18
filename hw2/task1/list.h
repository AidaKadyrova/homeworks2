#pragma once

class List
{
public:
    virtual~List(){};
    virtual void addToBegin(int n) = 0;
    virtual void deleteList() = 0;
    virtual void addToEnd(int n) = 0;
    virtual void isElement(int n) = 0;
    virtual void deleteElement(int n) = 0;
    virtual void addToThePosition(int n, int position) = 0;
    virtual void printList() = 0;
    virtual void printSize() = 0;
};

