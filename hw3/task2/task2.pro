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

TEMPLATE = app


SOURCES += main.cpp \
    printtoconsole.cpp \
    printtofile.cpp

HEADERS += \
    output.h \
    printtoconsole.h \
    printtofile.h

OTHER_FILES += \
    output.txt
