#pragma once
#include "sorter.h"

class HeapSort : public Sorter
{
public:
    HeapSort(){}
    void sorting(int array[],int start, int end);
private:
    void swap(int &a, int &b);
};
