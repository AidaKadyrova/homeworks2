#pragma once

/**
@class Array
class that sorts an array of first elements of the columns
*/
class Array
{
public:

    /// constructor, which creates a dynamic array
    Array();
    /// destructor deletes the array after use
    ~Array();
    /// this method prints the array to the console
    void printArray();
    void columnSorting();
    int **arr;
private:
    /// it fills an array of randomly
    void random();
    /**
      * it swap the two columns
      *@param a - index of column, which you want to swap with the following
      */
    void swap(int a);
    /// size of the array
    static int const dim = 5;
};

