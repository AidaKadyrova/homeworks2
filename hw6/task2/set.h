#pragma once

/**
 * @class Set
 * template class with operations to add,
 * delete an item, check for membership to the set,
 * intersection and association of sets.
 */

template <typename T>
class Set
{
public:
    Set():size(0){}
    ~Set(){}

    void addElement(const T &el)
    {
        if (!contain(el))
        set[size++] = el;
    }

    void deleteElement(T el)
    {
        for (int i = 0; i < size; i++)
            if (set[i] == el)
            {
                for (int j = i; j < size; j++)
                    set[j] = set[j+1];
                size--;
            }
    }

    bool contain(T el)
    {
        for(int i = 0; i < size; i++)
            if (set[i] == el)
                return true;
        return false;
    }

    Set intersection(Set &set1)
    {
        Set resultSet;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < set1.sizeOfSet(); j++)
                if (set[i] == set1.at(j))
                    resultSet.addElement(set[i]);
        return resultSet;
    }

    Set association(Set &set1)
    {
        Set resultSet;
        for (int i = 0; i < size; i++)
            resultSet.addElement(set[i]);
        for (int i = 0; i < set1.sizeOfSet(); i++)
            resultSet.addElement(set1.at(i));
        return resultSet;
    }

    T at(int i)
    {
        return set[i];
    }

int sizeOfSet()
{
    return size;
}

private:
    int static const dim = 100;
    T set[dim];
    int size;
};

