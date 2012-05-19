#include <iostream>
#include "vector.h"

Vector::Vector()
{
}

Vector::Vector(const Vector &vector)
{
    x = vector.x;
    y = vector.y;
}

bool Vector::isNull()
{
    return((x == 0) && (y == 0));
}

int Vector::getX()
{
    return x;
}

int Vector::getY()
{
    return y;
}

void Vector::showVector()
{
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}

Vector* Vector::add(Vector* &vector)
{
    Vector* t = new Vector();
    t->x = x + vector->x;
    t->y = y + vector->y;
    return t;
}

Vector* Vector::substruct(Vector* &vector)
{
    Vector* t = new Vector();
    t->x = x - vector->x;
    t->y = y - vector->y;
    return t;
}

int Vector::scalarMultiply(Vector* &v)
{
    return (x*v->x + y*v->y);
}

void Vector::setX(int value)
{
    x = value;
}

void Vector::setY(int value)
{
    y = value;
}
