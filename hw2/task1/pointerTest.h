#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "pointer.h"



class PointerTest : public QObject
{
    Q_OBJECT
public:
    explicit PointerTest(QObject *parent = 0) {}

private slots:
    void init()
    {
        p = new Pointer();
    }

    void cleanup()
    {
        delete p;
    }

    void addToBeginTest()
    {
        p->addToBegin(3);
        p->addToBegin(9);
        QVERIFY(p->at(0) == 9);
        QVERIFY(p->at(1) == 3);
        QVERIFY(p->sizeOfList() == 2);
    }

    void addToEndTest()
    {
        p->addToEnd(5);
        p->addToEnd(0);
        QVERIFY(p->at(0) == 5);
        QVERIFY(p->at(1) == 0);
        QVERIFY(p->sizeOfList() == 2);
    }

    void isElementTest()
    {
        p->addToBegin(2);
        QVERIFY(p->isElement(2));
    }
    void deleteElementTest()
    {
        p->addToBegin(3);
        p->deleteElement(3);
        QVERIFY(p->sizeOfList() == 0);
    }

private:
    Pointer *p;
};


QTEST_MAIN(PointerTest)
