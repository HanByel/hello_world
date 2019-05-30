TEMPLATE = lib
CONFIG += console c++11
CONFIG -= lib_bundle
CONFIG -= qt
CONFIG += debug

LIBS += \

SOURCES += \
    File_RW.cpp \
    main.cpp

HEADERS += \
    File_RW.hpp

DISTFILES += \
    Makefile \
    Readme.txt \
    File_RW.sh

