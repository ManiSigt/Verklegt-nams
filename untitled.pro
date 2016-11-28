QT += core
QT -= gui

CONFIG += c++11

TARGET = untitled
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    classui.cpp \
    listworker.cpp \
    datalayer.cpp

HEADERS += \
    classui.h \
    listworker.h \
    datalayer.h

DISTFILES += \
    example.txt
