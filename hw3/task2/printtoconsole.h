#pragma once
#include "output.h"

/**
  * @class PrintToConsole
  * this class prints an array to console
  * and it does it in two ways
  */
class PrintToConsole : public Output
{
public:
    /// constructor(by default)
    PrintToConsole(){}
    /**
      * this method writes an array to the mas
      * and after prints mas to console
      */
    void printSpirally(int **arr, int n);
    /// just prints an array to console
    void printArray(int **arr, int n);
//private:
    /// method printToConsole writes an array here before printing
    int mas[100];
};

