#pragma once
#include <QtTest/QtTest>
#include <QObject>
#include <iostream>
#include <fstream>
#include <string>
#include "expression.h"

using namespace std;

class ExpressionTest : public QObject
{
    Q_OBJECT
public:
    explicit ExpressionTest(QObject *parent = 0) {}

private slots:
    void calculateAndPrintTest()
    {
        ifstream f("input.txt");
        string s;
        getline(f, s);
        Expression *e = Expression::parse(s);
        int r = e->calculate();
        QVERIFY(r == -6);
        e->print();
        cout << endl;
    }


};

QTEST_MAIN(ExpressionTest)
