#pragma once
#include <QObject>
#include <QtTest/QtTest>
#include "bag.h"

class BagTest : public QObject
{
    Q_OBJECT
public:
    explicit BagTest(QObject *parent = 0) {}
private slots:
    void init()
    {
        b = new Bag<int>;
    }

    void cleanup()
    {
        delete b;
    }

    void findTest()
    {
        b->insert(3);
        b->insert(5);
        QVERIFY(b->find(3));
        QVERIFY(b->find(5));
    }

    void eraseTest()
    {
        b->insert(3);
        b->insert(5);
        b->erase(3);
        QVERIFY(!b->find(3));
        QVERIFY(b->find(5));
    }

    void amountTest()
    {
        b->insert(3);
        b->insert(5);
        b->insert(3);
        b->insert(5);
        QVERIFY(b->amountEl(3) == 2);
    }

    void sizeTest()
    {
        b->insert(3);
        b->insert(5);
        b->insert(3);
        b->insert(5);
        b->insert(2);
        QVERIFY(b->size() == 5);
    }

private:
    Bag<int> *b;

};


QTEST_MAIN(BagTest)
