#pragma once
#include <QObject>
#include <QtTest/QtTest>
#include "printtofile.h"
#include <fstream>
#include <iostream>

using namespace std;

class PrintToFileTest : public QObject
{
    Q_OBJECT
public:
    explicit PrintToFileTest(QObject *parent = 0) {}

private slots:
    void init()
    {
        a = new PrintToFile();
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
        ifstream f("output.txt");
        int tmp[dim*dim] = {4, 5, 8, 7, 6, 3, 0, 1, 2};
        for (int i = 0; i < dim*dim; i++)
        {
            f >> c;
            QVERIFY(c == tmp[i]);
        }
        for (int i = 0; i < dim; i++)
            delete[]pArr[i];
        delete[]pArr;
    }

private:
    PrintToFile *a;
};


QTEST_MAIN(PrintToFileTest)
