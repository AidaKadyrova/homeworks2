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
            throw RemoveMissingItemExpression();
        else deleteElement(n);
    }

    class RemoveMissingItemExpression
    {
    public:
        RemoveMissingItemExpression(){}
    };

    class AlreadyExistItemException
    {
    public:
        AlreadyExistItemException(){}
    };
};

