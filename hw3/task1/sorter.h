#pragma once

class Sorter
{
public:
    virtual void sorting(int array[], int start, int end) = 0;
protected:
    virtual void swap(int &a, int &b) = 0;
};
