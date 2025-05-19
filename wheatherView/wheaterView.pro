TEMPLATE = app
TARGET = wheaterView


QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 

HEADERS += window.h \
           circularBar.h

SOURCES += main.cpp \
           window.cpp \
           circularBar.cpp
