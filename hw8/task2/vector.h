#pragma once
#include <iostream>

using namespace std;

template<unsigned int const vSize>
/**
  * @class Vector - vector with an arbitrary length
  * it can add, substruct, calculate a scalar multiply and check for null
  *
  */
class Vector
{
public:
    Vector(){}

    /// copy constructor
    Vector(Vector* &vector)
    {
        for (int i = 1; i <= vSize; i++)
            v[i] = vector->at(i);
    }

    /// method returns a vector which is the sum of two vectors
    Vector* add(Vector* &vector)
    {
        Vector<vSize> *t = new Vector<vSize>();
        for (int i = 1; i <= vSize; i++)
            t->set(i, vector->at(i) + v[i]);
        return t;
    }

    Vector* substruct(Vector* &vector)
    {
        Vector<vSize> *t = new Vector<vSize>();
        for (int i = 1; i <= vSize; i++)
            t->set(i, vector->at(i) - v[i]);
        return t;
    }
    /// checking vector for null
    bool isNull()
    {
        bool f = true;
        for (int i = 1; i <= vSize; i++)
            if (v[i] != 0)
                f = false;
        return f;
    }

    /// it calculates scalar multiply of two vectors
    int scalarMultiply(Vector* &vector)
    {
        int sum = 0;
        for (int i = 1; i <= vSize; i++)
            sum += v[i] * vector->at(i);
        return sum;
    }

    void showVector()
    {
        cout << "( ";
        for (int i = 1; i <= vSize; i++)
            cout << at(i) << ", ";
        cout << ")" << endl;
    }

    int at(int i)
    {
        return v[i];
    }

    void set(int i, int value)
    {
        v[i] = value;
    }

private:
    int v[vSize];
};


