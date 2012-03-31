#include "printtofile.h"
#include "output.h"
#include <fstream>

using namespace std;

void PrintToFile::printArray(int **arr, int n)
{
    ofstream f("output.txt");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            f << arr[i][j] << "   ";
        f << endl << endl;
    }
    f.close();
}

void PrintToFile::printSpirally(int **arr, int n)
{
    ofstream f("output.txt", ios::app);
    f << "\n\spirally:\n\n";
    int r = 0;
    int center = n / 2;
    while (center > r)
    {
        r++;
        for (int j = center - r + 1; j < center + r; j++)//move right
            f << arr[center - r + 1][j] << " ";
        for (int j = center - r + 1; j < center + r; j++) //move down
            f << arr[j][center + r] << " ";
        for (int j = center + r; j > center - r; j--)//move left
            f << arr[center + r][j] << " ";
        for (int j = center + r; j >center - r; j--)// move up
            f << arr[j][center - r] << " ";
    }
    r++;
    for (int j = center - r + 1; j < center + r; j++)
        f <<  arr[center - r + 1][j] << " "; //move right once again
    f << endl;
    f.close();
}

