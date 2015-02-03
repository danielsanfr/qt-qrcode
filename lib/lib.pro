QT       -= gui

TARGET = qtqrcode
TEMPLATE = lib

DEFINES += QTQRCODE_LIBRARY

SOURCES += \
    qtqrcode.cpp

HEADERS +=\
    qtqrcode_global.h \
    qtqrcode.h

INCLUDEPATH += $$PWD

include(libqrencode.pri)

unix {
    target.path = /usr/lib
    INSTALLS += target
}
