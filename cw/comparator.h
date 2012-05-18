#pragma once
#include "sorter.h"

#include <QtCore/QCoreApplication>
/**
  * @class has one method which compares two int elements( for test)
  */
template <typename T>
class Comparator
{
public:

    int compare(T a, T b)
    {
        return (a - b);
    }
};


