TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    bush.cpp \
    container.cpp \
    flower.cpp \
    plant.cpp \
    tree.cpp

DISTFILES += \
    in.txt \
    out.txt

HEADERS += \
    bush.h \
    container.h \
    flower.h \
    plant.h \
    tree.h
