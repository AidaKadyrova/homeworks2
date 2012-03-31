#pragma once
#include "output.h"
/**
  * @class PrintToFile
  * it prints an array to "output.txt" file
  */
class PrintToFile : public Output
{
public:
    /// constructor(by default)
    PrintToFile(){}
    void printSpirally(int **arr, int n);
    void printArray(int **arr, int n);
};

