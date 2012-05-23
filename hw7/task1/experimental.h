#pragma once
#include "exceptionTest.h"
#include <debug/debug.h>

class Exception
{
public:
    Exception(){}
};
/**
  * @class our test subject, which can only throw an exception
  */
class Experimental
{
public:
    Experimental()
    {
        qDebug(" constructor' called");
    }
    ~Experimental()
    {
        qDebug(" destructor's called");
    }
    void thrower()
    {
        qDebug(" thrower's called");
        throw Exception();
    }
};
