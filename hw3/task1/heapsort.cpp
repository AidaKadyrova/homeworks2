#include "heapsort.h"
#include "sorter.h"

void HeapSort::sorting(int array[], int start, int end)
{
    for (int i = end / 2 - 1; i >= start; i--)
        {
            if ((array[i] < array[2 * i + 1]) && ((2 * i + 1) < end))
                swap(array[i], array[2 * i + 1]);
            if ((array[i] < array[2 * (i + 1)]) && ((2 * (i + 1) < end)))
                    swap(array[i], array[2 * (i + 1)]);
        }
        end--;
        swap(array[start], array[end]);
        if (end > 1)
            sorting(array, start, end);
}

void HeapSort::swap(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}
