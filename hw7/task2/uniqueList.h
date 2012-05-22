#pragma once
#include "pointer.h"

/**
 * @class усовершенствованный класс-список,
 * в который нельзя добавлять уже существующий элемент.
 * при попытке удаления несуществующего бросается исключние
 */
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
    /// класс-исключение для удаление несуществующего элемента
    class RemoveMissingItemExpression
    {
    public:
        RemoveMissingItemExpression(){}
    };
    /// класс-исключение для добавления элемента, содеражащегося в списке
    class AlreadyExistItemException
    {
    public:
        AlreadyExistItemException(){}
    };
};

