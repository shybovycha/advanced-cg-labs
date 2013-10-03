TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

LIBS += -lGL -lGLU -lsfml-graphics -lsfml-system -lsfml-window

INCLUDEPATH += /home/shybovycha/SFML-2.1/include
