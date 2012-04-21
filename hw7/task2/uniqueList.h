#pragma once
#include "pointer.h"

class UniqueList : public Pointer
{
public:
    UniqueList(){}
    void add(int n)
    {
        if (isElement(n))
            throw AlreadyExistItemException();
        else addToBegin(n);
    }

    void remove(int n)
    {
        if (!isElement(n))
            throw EmptyListException();
        else deleteElement(n);
    }

    class EmptyListException
    {
    public:
        EmptyListException(){}
    };

    class AlreadyExistItemException
    {
    public:
        AlreadyExistItemException(){}
    };
};

