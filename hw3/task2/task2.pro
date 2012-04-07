#-------------------------------------------------
#
# Project created by QtCreator 2012-03-25T22:08:26
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = task2
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += qtestlib

TEMPLATE = app


SOURCES += \
    printtoconsole.cpp \
    printtofile.cpp

HEADERS += \
    output.h \
    printtoconsole.h \
    printtofile.h \
    printToConsoleTest.h \
    printToFileTest.h

OTHER_FILES += \
    output.txt
