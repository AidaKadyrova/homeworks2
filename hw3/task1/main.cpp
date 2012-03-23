#include <iostream>
#include "sorter.h"
#include "bubblesort.h"
#include "heapsort.h"
#include "qsort.h"

using namespace std;

int const dim = 10;

void printArray(int array[])
{
    for (int i = 0; i < dim; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main()
{
    int array[dim] = {1,2,8,9,7,5,4,6,9,5};
    printArray(array);

    Sorter* b = new BubbleSort;
    b->sorting(array, 0, dim - 1);
    cout << "bubble sort:\t";
    printArray(array);

    Sorter* h = new HeapSort;
    h->sorting(array, 0, dim);
    cout << "heap sort:\t";
    printArray(array);

    Sorter* q = new QSort;
    q->sorting(array, 0, dim - 1);
    cout << "quick sort:\t";
    printArray(array);

    return 0;
}
