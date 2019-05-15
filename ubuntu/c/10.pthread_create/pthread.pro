TEMPLATE = lib
CONFIG += console c++11
CONFIG -= lib_bundle
CONFIG -= qt
CONFIG += debug

LIBS += \
    pthread.h

SOURCES += \
    pthread.c

HEADERS += \

DISTFILES += \
    Makefile \
    Readme.txt \
    pthread.sh

