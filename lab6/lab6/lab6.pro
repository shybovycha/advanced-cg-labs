TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    utils.cpp \
    mesh.cpp

LIBS += -lGL -lGLU -lGLEW -lglut -ljpeg -lsfml-graphics -lsfml-window  -lsfml-system -lassimp

OTHER_FILES += \
    vertex.glsl \
    ../data/vertex.glsl \
    ../data/fragment.glsl

HEADERS += \
    utils.h \
    mesh.h
