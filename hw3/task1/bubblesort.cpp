#include "bubblesort.h"
#include "sorter.h"

void BubbleSort::sorting(int array[],int start, int end)
{
    for (int i = start; i < end; i++)
        for (int j = start; j < end - i; j++)
            if (array[j] > array[j + 1])
                swap(array[j], array[j+1]);
}

void BubbleSort::swap(int &a, int &b)
{
    a += b;
    b = a - b;
    a = a - b;
}
