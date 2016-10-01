QT += core sql
QT -= gui

TARGET = MarketDataServer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

LIBS += /usr/local/lib/libzmq.dylib

INCLUDEPATH += ../l_common/

INCLUDEPATH += /usr/local/include







