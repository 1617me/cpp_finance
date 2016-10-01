QT += core
QT -= gui

TARGET = ConsolClient
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

LIBS += /usr/local/lib/libzmq.dylib

INCLUDEPATH += /usr/local/include
INCLUDEPATH += ../l_common

