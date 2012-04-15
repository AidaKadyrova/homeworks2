#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "arraystack.h"

class ArrayStackTest : public QObject
{
    Q_OBJECT
public:
    explicit ArrayStackTest(QObject *parent = 0) {}

private slots:
    void init()
    {
        a = new ArrayStack();
    }

    void cleanup()
    {
        delete a;
    }

    void pushTest()
    {
        a->push(3);
        a->push(9);
        QVERIFY(a->at(1) == 3);
        QVERIFY(a->at(2) == 9);
        QVERIFY(a->sizeOfStack() == 2);
    }

    void frontTest()
    {
        a->push(2);
        QVERIFY(a->front() == a->at(1));
    }
    void popTest()
    {
        a->push(3);
        QVERIFY(a->front() == a->pop());
        QVERIFY(a->sizeOfStack() == 0);
    }


private:
    ArrayStack *a;
};


//QTEST_MAIN(ArrayStackTest)
