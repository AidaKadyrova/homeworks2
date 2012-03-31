#pragma once

/**
  * @class Sorter
  * it sorts an array by ascending
  */
class Sorter
{
public:
    /**
      * @param array[] is the array, which is sorted
      * @param start - left adge of the array
      * @param end - right adge
      */
    virtual void sorting(int array[], int start, int end) = 0;
protected:
    /// virtual method to swap two elements of the array
    virtual void swap(int &a, int &b)
    {
        a += b;
        b = a - b;
        a = a - b;
    }

};
