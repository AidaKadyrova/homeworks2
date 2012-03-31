#pragma once

/**
  @class Output
  class which prints the array
  */
class Output
{
public:
    /**
      * virtual method which prints the array sprirally
      * @param array is dinamic array
      * @param n is size of array
      */
    virtual void printSpirally(int **arr, int n) = 0;
    /// virtual method which just print th array
    virtual void printArray(int **arr, int n) = 0;
};
