QT += core
QT -= gui
QT += core sql
CONFIG += c++11

TARGET = untitled
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    classui.cpp \
    listworker.cpp \
    datalayer.cpp \
    person.cpp \
    computer.cpp

HEADERS += \
    classui.h \
    listworker.h \
    datalayer.h \
    person.h \
    computer.h

DISTFILES += \
    example.txt

