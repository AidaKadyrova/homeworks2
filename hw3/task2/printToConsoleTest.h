#pragma once
#include <QObject>
#include <QtTest/QtTest>
#include "printtoconsole.h"

class PrintToConsoleTest : public QObject
{
    Q_OBJECT
public:
    explicit PrintToConsoleTest(QObject *parent = 0) {}

private slots:
    void init()
    {
        a = new PrintToConsole();
    }

    void cleanup()
    {
        delete a;
    }

    void printTest()
    {
        int c = 0;
        int const dim= 3;
        int **pArr = new int*[dim];
        for (int i = 0; i < dim; i++)
        {
            pArr[i] = new int[dim];
            for (int j = 0; j < dim; j++)
                pArr[i][j] = c++;
        }

        a->printSpirally(pArr, dim);
        int tmp[dim*dim] = {4, 5, 8, 7, 6, 3, 0, 1, 2};
        for (int i = 0; i < dim*dim; i++)
            QVERIFY(tmp[i] == a->mas[i]);

        for (int i = 0; i < dim; i++)
            delete[]pArr[i];
        delete[]pArr;
    }

private:
    PrintToConsole *a;
};

//QTEST_MAIN(PrintToConsoleTest)
