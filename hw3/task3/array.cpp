#include "array.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

Array::Array()
{
    int **arr = new int*[dim];
    for (int i = 0; i < dim; i++)
        arr[i] = new int[dim];
}

Array::~Array()
{
    for (int i = 0; i < dim; i++)
        delete[]arr[i];
    delete[]arr;
}

void Array::columnSorting()
{
    random();
    printArray();
    for (int i = 1; i < dim; i++)
        for (int j = 0; j < dim - i; j++)
            if (arr[j][0] > arr[j + 1][0])
                swap(j);
    printArray();
}

void Array::swap(int a)
{
    int *temp;
    temp = arr[a];
    arr[a] = arr[a + 1];
    arr[a + 1] = temp;
}

void Array::random()
{
    srand(time(0));
    for (int i = 0; i < dim; i++)
        for (int j = 0; j < dim; j++)
            arr[i][j] = rand() % 10;
}
void Array::printArray()
{
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
            cout << arr[j][i] << "  ";
        cout << endl << endl;
    }
    cout << endl << endl;
}
