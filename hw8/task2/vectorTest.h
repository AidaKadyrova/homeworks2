#pragma once
#include <QtTest/QtTest>
#include <QObject>
#include "vector.h"

class VectorTest : public QObject
{
    Q_OBJECT
public:
    explicit VectorTest(QObject *parent = 0) {}
private slots:
    void init()
    {
        v = new Vector();
    }

    void cleanup()
    {
        delete v;
    }

    void scalarMultipplyTest()
    {
        v->setX(4);
        v->setY(7);
        Vector *v1 = new Vector();
        v1->setX(5);
        v1->setY(2);
        QVERIFY(v->scalarMultiply(v1) == 34);
    }

    void getXYTest()
    {
        v->setX(6);
        v->setY(5);
        QVERIFY(v->getX() == 6 && v->getY() == 5);
    }

    void addTest()
    {
        v->setX(4);
        v->setY(7);
        Vector *v1 = new Vector(*v);
        QVERIFY(v->add(v1)->getX() == 8);
        QVERIFY(v->add(v1)->getY() == 14);
    }

    void substructAndIsNullTest()
    {
        v->setX(4);
        v->setY(7);
        Vector *v1 = new Vector(*v);
        QVERIFY(v->substruct(v1)->isNull());
    }

private:
    Vector *v;

};

QTEST_MAIN(VectorTest)
