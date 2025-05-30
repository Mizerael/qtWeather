TEMPLATE = app
TARGET = weatherControl

QT = core gui
greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets

CONFIG += c++17

HEADERS += window.h \
           datasource.h \
           settingsWidget.h \
           dateTimeWidget.h \
           locationWidget.h

SOURCES += main.cpp \
           window.cpp \
           datasource.cpp \
           settingsWidget.cpp \
           dateTimeWidget.cpp \
           locationWidget.cpp

