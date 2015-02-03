DEFINES += __STATIC=static MAJOR_VERSION=3 MINOR_VERSION=9 MICRO_VERSION=0 VERSION=\'\"3.9.0\"\'

BASEDIR = libqrencode
INCLUDEPATH += libqrencode
SOURCES += \
    $$BASEDIR/bitstream.c \
    $$BASEDIR/qrencode.c \
    $$BASEDIR/mqrspec.c \
    $$BASEDIR/qrinput.c \
    $$BASEDIR/qrspec.c \
    $$BASEDIR/split.c \
    $$BASEDIR/rsecc.c \
    $$BASEDIR/mmask.c \
#    $$BASEDIR/qrenc.c \
    $$BASEDIR/mask.c
HEADERS += \
    $$BASEDIR/qrencode_inner.h \
    $$BASEDIR/bitstream.h \
    $$BASEDIR/qrencode.h \
    $$BASEDIR/mqrspec.h \
    $$BASEDIR/qrinput.h \
    $$BASEDIR/qrspec.h \
    $$BASEDIR/split.h \
    $$BASEDIR/rsecc.h \
    $$BASEDIR/mmask.h \
    $$BASEDIR/mask.h
