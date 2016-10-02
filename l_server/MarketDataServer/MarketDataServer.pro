QT += core sql

TARGET = MarketDataServer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    SendMsg.cpp \
    QApp.cpp

LIBS += /usr/local/lib/libzmq.dylib

INCLUDEPATH += ../l_common/

INCLUDEPATH += /usr/local/include

HEADERS += \
    SendMsg.h \
    QApp.h







