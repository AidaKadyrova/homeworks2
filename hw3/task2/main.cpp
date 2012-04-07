#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "output.h"
#include "printtoconsole.h"
#include "printtofile.h"

using namespace std;

int main()
{


    int n = 0;
    cout << "enter odd number\n";
    cin >> n;

    int const dim= 10;
    int **pArr = new int*[dim];
    for (int i = 0; i < dim; i++)
        pArr[i] = new int[dim];

    srand(time(0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            pArr[i][j] = rand() % 10;

    Output* c = new PrintToConsole;
    c->printArray(pArr, n);
    c->printSpirally(pArr, n);

    Output* f = new PrintToFile;
    f->printArray(pArr, n);
    f->printSpirally(pArr, n);

    for (int i = 0; i < dim; i++)
        delete[]pArr[i];
    delete[]pArr;

    return 0;
}

