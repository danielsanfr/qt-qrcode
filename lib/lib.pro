TARGET = qtqrcode
TEMPLATE = lib

DEFINES += \
    QTQRCODE_LIBRARY \
    QTQRCODE_PLUS_FEATURES

contains(DEFINES, QTQRCODE_PLUS_FEATURES) {
    QT      += gui svg
} else {
    QT      -= gui
}

SOURCES += \
    qtqrcode.cpp \
    qtqrcodepainter.cpp

HEADERS +=\
    qtqrcode_global.h \
    qtqrcode.h \
    qtqrcodepainter.h

INCLUDEPATH += $$PWD

include(libqrencode.pri)

unix {
    target.path = /usr/lib
    INSTALLS += target
}
