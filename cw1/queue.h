#pragma once
#include <iostream>
#include "node.h"

using namespace std;

/**
  * @class Queue
  * it has: constructor, destructor,
  * private pointer to class Node(template),
  * class for exception
  * and two publuc methods enqueue and dequeue
  *
  */
template <typename T>
class Queue
{
public:
    Queue(): mFirst(NULL){}
    ~Queue()
    {
        delete mFirst;
    }
    /**
     * method which add elements in ascending order
     * @param T - is element(template)
     * @param priority - is priority of element
     */
    void enqueue(T t, int priority)
    {
        if (!mFirst)
            mFirst = new Node<T>(t, priority, NULL);
        else
        {
            Node<T> *tm = mFirst;
            while (tm->mNext && tm->mNext->mPriority < priority)
                tm = tm->mNext;
            Node<T> *temp = new Node<T>(t, priority, mFirst);
            mFirst = temp;
        }
    }
    /**
     * method, which deletes element with max priority in queue(0 - is max pr)
     * it returns this element value
     *
     */
    T dequeue()
    {
        if (!mFirst)
            throw EmptyQueue();
        else
        {
            Node<T> *tm = mFirst->mNext;
            T n  = mFirst->mValue;
            mFirst = tm;
            delete mFirst;
            return n;
        }
    }
    /// an exeption for empty queue
    class EmptyQueue
    {
    public:
        EmptyQueue(){}
    };
// public for tests
//private:

    Node<T> *mFirst;
};



