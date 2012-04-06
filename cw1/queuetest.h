#pragma once
#include <QObject>
#include <QtTest/QtTest>
#include <iostream>
#include "queue.h"

using namespace std;

class QueueTest : public QObject
{
    Q_OBJECT
public:
    explicit QueueTest(QObject *parent = 0) {}

private slots:
    void init()
    {
        q = new Queue<char>;
    }
    void cleanup()
    {
        delete q;
    }

    void enqueueTest()
    {
        q->enqueue('a', 1);
        QVERIFY(q->mFirst->mPriority == 1);
    }

    void enqueueTest2()
    {
        q->enqueue('e', 4);
        QVERIFY(q->mFirst->mValue == q->dequeue());
    }

    void dequeueTest()
    {
        q->enqueue('q', 4);
        try {
            q->dequeue();
        } catch (Queue<char>::EmptyQueue&)
        {
            cout << "removing from empty queue" <<endl;
        }
    }
private:
    Queue<char> *q;
};

QTEST_MAIN(QueueTest)
