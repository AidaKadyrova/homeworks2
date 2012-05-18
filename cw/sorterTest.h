#pragma once
#include <QtTest/QtTest>
#include <QObject>
#include "sorter.h"
#include "comparator.h"

class SorterTest : public QObject
{
    Q_OBJECT
public:
    explicit SorterTest(QObject *parent = 0) {}

private slots:

    void bubbleSortTest()
    {
        QList<int> * list = new QList<int>;
        list->push_front(5);
        list->push_front(7);
        list->push_front(3);
        list->push_front(8);
        list->push_front(1);
        list->push_front(2);
        list->push_front(6);
        list->push_front(9);
        list->push_front(4);
        Comparator<int>* c = new Comparator<int>;
        Sorter<int> *sort = new Sorter<int>;
        sort->bubbleSort(list, c);
        QListIterator<int> iterator(*list);
        iterator.toFront();
        int i = 1;
        while(iterator.hasNext())
            QVERIFY(iterator.next() == i++);
    }

};

QTEST_MAIN(SorterTest)
