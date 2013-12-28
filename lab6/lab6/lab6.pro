TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    utils.cpp

LIBS += -lGL -lGLU -lGLEW -lglut -ljpeg -lsfml-graphics -lsfml-window  -lsfml-system

OTHER_FILES += \
    vertex.glsl \
    ../data/vertex.glsl \
    ../data/fragment.glsl

HEADERS += \
    utils.h
