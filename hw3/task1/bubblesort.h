#pragma once
#include "sorter.h"

class BubbleSort : public Sorter
{
public:
    BubbleSort(){}
    void sorting(int array[],int start, int end);
private:
    void swap(int &a, int &b);
};
