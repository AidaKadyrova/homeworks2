#pragma once
/**
 * @class Node
 * it has constructor with initialization
 *
 */
template <typename T>

class Node
{
public:
    Node(T value, int priority, Node* next) : mValue(value)
      , mPriority(priority)
      , mNext(next)
    {}
// public for tests
//private:
    int mPriority;
    T mValue;
    Node<T> *mNext;
};


