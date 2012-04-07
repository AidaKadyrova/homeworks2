#include "output.h"
#include "printtoconsole.h"
#include <iostream>

using namespace std;

void PrintToConsole::printSpirally(int **arr, int n)
{
    //cout << "\n\spirally:\n\n";
    int r = 0;
    int count = 0;
    int center = n / 2;
    while (center > r)
    {
        r++;
        for (int j = center - r + 1; j < center + r; j++)//move right
        {
            mas[count] = arr[center - r + 1][j];
            count++;
        }
        for (int j = center - r + 1; j < center + r; j++) //move down
        {
            mas[count] = arr[j][center + r];
            count++;
        }
        for (int j = center + r; j > center - r; j--)//move left
        {
            mas[count] = arr[center + r][j];
            count++;
        }
        for (int j = center + r; j >center - r; j--)// move up
        {
            mas[count] = arr[j][center - r];
            count++;
        }
    }
    r++;
    for (int j = center - r + 1; j < center + r; j++)
    {
        mas[count] = arr[center - r + 1][j];
        count++; //move right once again
    }
    //cout << endl;
    //for (int i = 0; i < n*n; i++)
      //  cout << mas[i] << " ";
}

void PrintToConsole::printArray(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << "  ";
        cout << endl << endl;
    }
}
