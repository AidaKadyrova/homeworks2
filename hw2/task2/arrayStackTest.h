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
        QVERIFY(a->value[1] == 3);
        QVERIFY(a->value[2] == 9);
        QVERIFY(a->size == 2);
    }

    void frontTest()
    {
        a->push(2);
        QVERIFY(a->front() == a->value[1]);
    }
    void popTest()
    {
        a->push(3);
        QVERIFY(a->front() == a->pop());
        QVERIFY(a->size == 0);
    }


private:
    ArrayStack *a;
};


//QTEST_MAIN(ArrayStackTest)
