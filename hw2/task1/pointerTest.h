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
        QVERIFY(p->value == 9);
        QVERIFY(p->next->value == 3);
        QVERIFY(p->size == 2);
    }

    void addToEndTest()
    {
        p->addToEnd(5);
        p->addToEnd(0);
        QVERIFY(p->value == 5);
        QVERIFY(p->next->value == 0);
        QVERIFY(p->size == 2);
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
        QVERIFY(p->size == 0);
    }

private:
    Pointer *p;
};
