QT       -= gui

TARGET = qtqrcode
TEMPLATE = lib

DEFINES += LIB_LIBRARY

SOURCES += \
    qtqrcode.cpp

HEADERS +=\
    qtqrcode_global.hpp \
    qtqrcode.h

INCLUDEPATH += $$PWD

include(libqrencode.pri)

unix {
    target.path = /usr/lib
    INSTALLS += target
}
