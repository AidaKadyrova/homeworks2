#pragma once
#include <QObject>
#include "debug/debug.h"
#include <QtTest/QtTest>
#include "uniqueList.h"


class UniqueListTest : public QObject
{
    Q_OBJECT
public:
    explicit UniqueListTest(QObject *parent = 0) {}

private slots:
    void init()
    {
        q = new UniqueList;
    }

    void cleanup()
    {
        delete q;
    }
    void addTest()
    {
        q->add(3);
        try {
            q->add(3);
        } catch (UniqueList::AlreadyExistItemException&)
        {
            qDebug("adding an existing item");
        }
    }

    void removeTest()
    {
        q->add(2);
        try {
            q->remove(2);
        } catch (UniqueList::RemoveMissingItemExpression&)
        {
            qDebug("removing missing item");
        }
    }

    void removeTest2()
    {
        q->add(3);
        try {
            q->remove(2);
        } catch (UniqueList::RemoveMissingItemExpression&)
        {
            qDebug("removing missing item");
        }
    }
private:
    UniqueList *q;
};

QTEST_MAIN(UniqueListTest)
