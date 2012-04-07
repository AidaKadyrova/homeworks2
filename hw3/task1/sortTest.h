#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "bubblesort.h"
#include "qsort.h"
#include "heapsort.h"

class SortTest : public QObject
{
    Q_OBJECT
public:
    explicit SortTest(QObject *parent = 0) {}

private slots:
    void BubbleSortTest()
    {
        Sorter * a = new BubbleSort();
        int const dim = 10;
        int array[dim] = {1,2,8,9,7,5,4,6,3,0};
        a->sorting(array, 0, dim);
        for (int i = 0; i < dim; i++)
            QVERIFY(array[i] == i);
        delete a;
    }

    void HeapSortTest()
    {
        Sorter * a = new HeapSort();
        int const dim = 10;
        int array[dim] = {1,2,8,9,7,5,4,6,0,3};
        a->sorting(array, 0, dim);
        for (int i = 0; i < dim; i++)
            QVERIFY(array[i] == i);
        delete a;
    }

    void QSortSortTest()
    {
        Sorter * a = new QSort();
        int const dim = 10;
        int array[dim] = {0,9,5,1,7,8,4,6,3,2};
        a->sorting(array, 0, dim - 1);
        for (int i = 0; i < dim; i++)
            QVERIFY(array[i] == i);
        delete a;
    }
};


QTEST_MAIN(SortTest)
