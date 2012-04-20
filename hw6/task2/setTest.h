#pragma once
#include <QObject>
#include <QtTest/QtTest>
#include "set.h"

using namespace std;

class SetTest : public QObject
{
    Q_OBJECT
public:
    explicit SetTest(QObject *parent = 0) {}

private slots:
    void init()
    {
        s = new Set<int>;
    }

    void cleanup()
    {
        delete s;
    }

    void addElementTest()
    {
        s->addElement(5);
        QVERIFY(s->isElement(5));
    }

    void addElementTest2()
    {
        s->addElement(4);
        s->addElement(2);
        QVERIFY(s->sizeOfSet() == 2);
    }

    void deleteElementTest()
    {
        s->addElement(2);
        s->deleteElement(2);
        QVERIFY(s->sizeOfSet() == 0);
        QVERIFY(!s->isElement(2));
    }

    void intersectionTest()
    {
        s->addElement(1);
        s->addElement(2);
        s->addElement(3);
        Set<int> s1;
        s1.addElement(2);
        s1.addElement(3);
        s1.addElement(4);
        Set<int> resultSet = s->intersection(s1);
        QVERIFY(resultSet.at(0) == 2);
        QVERIFY(resultSet.at(1) == 3);
    }

    void associationTest()
    {
        s->addElement(0);
        s->addElement(1);
        s->addElement(2);
        Set<int> s1;
        s1.addElement(1);
        s1.addElement(2);
        s1.addElement(3);
        Set<int> resultSet = s->association(s1);
        for (int i = 0; i < 4; i++)
            QVERIFY(resultSet.at(i) == i);
    }

private:
    Set<int> *s;
};

QTEST_MAIN(SetTest)
