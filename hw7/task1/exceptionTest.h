#pragma once
#include <QObject>
#include <QtTest/QtTest>
#include "debug/debug.h"
#include "experimental.h"

class ExceptionTest : public QObject
{
    Q_OBJECT
public:
    explicit ExceptionTest(QObject *parent = 0) {}

private slots:
    void exprTest()
    {
        try
        {
            Experimental e;
            e.thrower();
        }
        catch(Exception&)
        {
            qDebug(" exception's handled\n");
        }
    }
};

QTEST_MAIN(ExceptionTest)
