#pragma once
#include <QtTest/QtTest>
#include <QObject>
#include "vector.h"
#include <iostream>
class VectorTest : public QObject
{
    Q_OBJECT
public:
    explicit VectorTest(QObject *parent = 0) {}
private slots:
    void init()
    {
        vec = new Vector<3>();
    }

    void cleanup()
    {
        delete vec;
    }

    void scalarMultipplyTest()
    {
        vec->set(1, 1);
        vec->set(2, 3);
        vec->set(3, 2);

        Vector<3> *vec1 = new Vector<3>();
        vec1->set(1, 4);
        vec1->set(2, 5);
        vec1->set(3, 6);
        QVERIFY(vec->scalarMultiply(vec1) == 31);
    }

    void getXYTest()
    {
        vec->set(1, 2);
        vec->set(2, 4);
        vec->set(3, 3);
        QVERIFY(vec->at(1) == 2);
        QVERIFY(vec->at(2) == 4);
        QVERIFY(vec->at(3) == 3);
    }

    void addTest()
    {   vec->set(1, 2);
        vec->set(2, 4);
        vec->set(3, 3);
        Vector<3> *vec1 = new Vector<3>(*vec);
        QVERIFY(vec->add(vec1)->at(1) == 4);
        QVERIFY(vec->add(vec1)->at(2) == 8);
    }

    void substructAndIsNullTest()
    {
        vec->set(1, 2);
        vec->set(2, 4);
        vec->set(3, 3);
        Vector<3> *vec1 = new Vector<3>(*vec);
        QVERIFY(vec->substruct(vec1)->isNull());
    }

private:
    Vector<3> *vec;

};

QTEST_MAIN(VectorTest)
