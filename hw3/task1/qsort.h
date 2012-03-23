#pragma once
#include "sorter.h"

class QSort : public Sorter
{
public:
    QSort(){}
    void sorting(int array[],int start, int end);
private:
    void swap(int &a, int &b);
};
