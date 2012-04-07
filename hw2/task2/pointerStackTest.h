#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "pointerstack.h"

class PointerStackTest : public QObject
{
    Q_OBJECT
public:
    explicit PointerStackTest(QObject *parent = 0) {}

private slots:
    void init()
    {
        a = new PointerStack();
    }

    void cleanup()
    {
        delete a;
    }

    void pushTest()
    {
        a->push(3);
        a->push(9);
        QVERIFY(a->next->value == 9);
    }

    void frontTest()
    {
        a->push(2);
        QVERIFY(a->front() == 2);
    }
    void popTest()
    {
        a->push(3);
        QVERIFY(a->front() == a->pop());
        QVERIFY(a->next == NULL);
    }
private:
    PointerStack *a;
};


//QTEST_MAIN(PointerStackTest)
