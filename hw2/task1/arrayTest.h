#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "array.h"



class ArrayTest : public QObject
{
    Q_OBJECT
public:
    explicit ArrayTest(QObject *parent = 0) {}

private slots:
    void init()
    {
        a = new Array();
    }

    void cleanup()
    {
        delete a;
    }

    void addToBeginTest()
    {
        a->addToBegin(3);
        a->addToBegin(9);
        QVERIFY(a->mas[0] == 9);
        QVERIFY(a->mas[1] == 3);
        QVERIFY(a->size == 2);
    }

    void addToEndTest()
    {
        a->addToEnd(5);
        a->addToEnd(0);
        QVERIFY(a->mas[0] == 5);
        QVERIFY(a->mas[1] == 0);
        QVERIFY(a->size == 2);
    }

    void isElementTest()
    {
        a->addToBegin(2);
        QVERIFY(a->isElement(2));
    }
    void deleteElementTest()
    {
        a->addToBegin(3);
        a->deleteElement(3);
        QVERIFY(a->size == 0);
    }

private:
    Array *a;
};

