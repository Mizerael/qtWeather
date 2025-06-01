TEMPLATE = app
TARGET = weatherView


QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += websockets
CONFIG += c++17 

HEADERS += window.h \
           circularBar.h \
           weatherWidget.h \
           journal.h \
           weatherServer.h

SOURCES += main.cpp \
           window.cpp \
           circularBar.cpp \
           weatherWidget.cpp \
           journal.cpp \
           weatherServer.cpp

