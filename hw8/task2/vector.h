#pragma once

class Vector
{
public:
    Vector();
    //copy constructor
    Vector(const Vector &vector);
    // method returns a vector which is the sum of two vectors
    Vector* add(Vector* &vector);
    Vector* substruct(Vector* &vector);
    bool isNull();
    // it calculate scalar multiply of two vectors
    int scalarMultiply(Vector* &v);
    void showVector();
    int getX();
    int getY();
    void setX(int value);
    void setY(int value);
private:
    int x;
    int y;
};


