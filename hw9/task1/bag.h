#pragma once
#include <set>
#include "bagiterator.h"
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

    class Iterator
    {
    public:
        /// Копирование из Bag<T>::Iterator
        Iterator(const typename Bag::Iterator &i) : it(i.it){}
        /// Копирование из multiset<T>::iterator
        Iterator(const typename multiset<int>::iterator &i) : it(i){}
        Iterator(){}
        /// Перезагрузка оператора присваивания
        Iterator &operator= (const typename Bag::Iterator &i)
        {
            it = i.it;
            return *this;
        }
        Iterator &operator= (typename multiset<int>::iterator &i)
        {
           it =i;
           return *this;
        }
        /// Перезагрузка оператора ++
        Iterator &operator++ ()
        {
            it++;
            return *this;
        }
        /// Перезагрузка оператора сравнения
        bool operator== (const typename Bag::Iterator &i)
        {
            return it == i.it;
        }

        /// Оператор разименования
        T operator* ()
        {
            return *it;
        }

    private:
        typename multiset<T>::iterator it;
    };


    Iterator begin()
    {
        return Iterator(bag.begin());
    }
    Iterator end()
    {
        return Iterator(bag.end());
    }
private:
    multiset<T> bag;
};
