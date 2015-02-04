TEMPLATE = app
TARGET = Widget

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DEFINES +=

SOURCES += main.cpp\
        MainWindow.cpp

HEADERS  += MainWindow.hpp

FORMS    += MainWindow.ui

CONFIG += mobility
MOBILITY = 

include(../defaults.pri)
# Default rules for deployment.
include(deployment.pri)
