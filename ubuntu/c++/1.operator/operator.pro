TEMPLATE = lib
CONFIG += console c++11
CONFIG -= lib_bundle
CONFIG -= qt
CONFIG += debug

LIBS += \

SOURCES += \
    operator.cpp

HEADERS += \
    operator.hpp
DISTFILES += \
    Makefile \
    Readme.txt \
    operator.sh

