#-------------------------------------------------
#
# Project created by QtCreator 2016-12-12T11:03:45
#
#-------------------------------------------------

QT       += core gui
QT += core sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    computer.cpp \
    datalayer.cpp \
    linker.cpp \
    linkeroutput.cpp \
    listworker.cpp \
    person.cpp

HEADERS  += mainwindow.h \
    computer.h \
    datalayer.h \
    linker.h \
    linkeroutput.h \
    listworker.h \
    person.h

FORMS    += mainwindow.ui