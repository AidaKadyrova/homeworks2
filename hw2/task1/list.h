#pragma once

class List
{
public:
    virtual~List(){}
    virtual void addToBegin(int n) = 0;
    virtual void addToEnd(int n) = 0;
    virtual bool isElement(int n) = 0;
    virtual void deleteElement(int n) = 0;
    virtual void addToThePosition(int n, int position) = 0;
    virtual int sizeOfList() = 0;
    virtual int at(int i) = 0;
protected:
    int size;
};

