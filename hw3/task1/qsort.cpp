#include "qsort.h"
#include "sorter.h"

void QSort::sorting(int array[], int start, int end)
{
    int i = start;
    int j = end;
    int x = (start + end) / 2;
    do
    {
        while (array[i] < array[x])
            i++;
        while (array[x] < array[j])
            j--;
        if (i <= j)
            swap(array[i++], array[j--]);
    }
    while (i <= j);
    if (start < j - x - 1)
        sorting(array, start, j);
    if (i < end - x - 1)
        sorting(array, i, end);
}

void QSort::swap(int &a, int &b)
{
    a += b;
    b = a - b;
    a = a - b;
}
