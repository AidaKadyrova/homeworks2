#-------------------------------------------------
#
# Project created by QtCreator 2012-04-20T22:59:59
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = task1
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += qtestlib

TEMPLATE = app


SOURCES += \
    digit.cpp \
    operation.cpp \
    expression.cpp \
    addition.cpp \
    substraction.cpp \
    multiplication.cpp \
    division.cpp

HEADERS += \
    digit.h \
    operation.h \
    expression.h \
    addition.h \
    substraction.h \
    multiplication.h \
    division.h \
    expressionTest.h

OTHER_FILES += \
    input.txt
