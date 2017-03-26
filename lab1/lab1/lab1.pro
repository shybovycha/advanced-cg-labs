TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

LIBS += -lGL -lGLU -lassimp -lsfml-graphics -lsfml-window -lsfml-system
INCLUDEPATH += /home/shybovycha/SFML-2.1/include/
