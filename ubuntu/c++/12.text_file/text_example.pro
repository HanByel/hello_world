TEMPLATE = lib
CONFIG += console c++11
CONFIG -= lib_bundle
CONFIG -= qt
CONFIG += debug

LIBS += \

SOURCES += \
    text_RW.cpp \
    main.cpp

HEADERS += \
    text_RW.hpp

DISTFILES += \
    Makefile \
    Readme.txt \
    text_example.sh

