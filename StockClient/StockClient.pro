#-------------------------------------------------
#
# Project created by QtCreator 2016-09-17T14:43:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StockClient
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    clientapp.cpp \
    HelperThread.cpp \
    MESendEvent.cpp

HEADERS  += mainwindow.h \
    clientapp.h \
    HelperThread.h \
    MESendEvent.h

FORMS    += mainwindow.ui

unix:!macx {
    LIBS += -lzmq
    INCLUDEPATH += ../StockCommon
}
macx: {
    LIBS+=/usr/local/lib/libzmq.dylib
    INCLUDEPATH+=/usr/local/include
    INCLUDEPATH+=../l_common
}
