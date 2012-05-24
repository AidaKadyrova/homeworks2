#pragma once
#include <set>
using namespace std;
template <typename T>

/**
  * @class шаблонный класс Bag, хранящий мультимножество
  * (множество, в котором элементы могут повторяться).
  * Класс ассимптотически эффективный по времени и по памяти.
  */
class Bag
{
public:
    ~Bag(){}
    bool isEmpty()
    {
        return bag.empty();
    }
    void insert(T el)
    {
        bag.insert(el);
    }

    void erase(T el)
    {
        typename multiset<T>::iterator i;
        i = bag.find(el);
        bag.erase(i);
    }


    bool find(const T& el)
    {
        return (bag.end() != bag.find(el));
    }

    int amountEl(const T& u)
    {
        return bag.count(u);
    }

    void clear()
    {
        bag.clear();
    }

    int size()
    {
        return bag.size();
    }

private:
    multiset<T> bag;
};
