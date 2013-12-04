#include <stdio.h>

#include <GL/glu.h>
#include <GL/gl.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "utils.h"

sf::Texture texture;
Vector lightPos(0.0, 1.0, -1.0), lightAxis(1.0, 0.0, 0.0);
const float lightRotationSpeed = 3.0;

void initialize()
{
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 10.0 };
    GLfloat light_position[] = { 0.0, 1.0, 1.0, 0.0 };
    GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

    glDisable(GL_CULL_FACE);
    glEnable(GL_TEXTURE_2D);

    if (!texture.loadFromFile("earth.jpg"))
    {
        printf("Could not load texture");
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLfloat lightPosition[] = { lightPos.x, lightPos.y, lightPos.z, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    glEnable(GL_TEXTURE_2D);
    sf::Texture::bind(&texture);

    GLUquadric *qobj = gluNewQuadric();
    gluQuadricTexture(qobj, GL_TRUE);

    gluSphere(qobj, 0.8, 50, 50);

    gluDeleteQuadric(qobj);

    glDisable(GL_TEXTURE_2D);
}

void windowResizeHandler(int width, int height)
{
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (width < height)
    {
        glOrtho(-1.5, 1.5, -0.5 * (GLfloat) height / (GLfloat) width, 0.5 * (GLfloat) height / (GLfloat) width, -10.0, 10.0);
    } else
    {
        glOrtho(-1.5 * (GLfloat) width / (GLfloat) height, 1.5 * (GLfloat) width / (GLfloat) height, -1.5, 1.5, -10.0, 10.0);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main()
{
    sf::Window window(sf::VideoMode(800, 600), "OpenGL");

    initialize();

    window.setActive(true);

    while (window.isOpen())
    {
        sf::Event event;

        // while there are pending events...
        while (window.pollEvent(event))
        {
            // check the type of the event...
            if (event.type == sf::Event::Resized)
            {
                windowResizeHandler(event.size.width, event.size.height);
            } else if (event.type == sf::Event::KeyPressed)
            {
                const Vector lightUp(0.0, 1.0, 0.0);

                if (event.key.code == sf::Keyboard::Up)
                {
                    lightPos = ((lightPos * -1).Rotate(lightAxis, Radians(lightRotationSpeed)) * -1);
                } else if (event.key.code == sf::Keyboard::Down)
                {
                    lightPos = ((lightPos * -1).Rotate(lightAxis, Radians(-lightRotationSpeed)) * -1);
                } else if (event.key.code == sf::Keyboard::Left)
                {
                    lightPos = lightPos.Rotate(lightUp, Radians(lightRotationSpeed));
                    lightAxis = lightAxis.Rotate(lightUp, Radians(lightRotationSpeed));
                } else if (event.key.code == sf::Keyboard::Right)
                {
                    lightPos = lightPos.Rotate(lightUp, Radians(-lightRotationSpeed));
                    lightAxis = lightAxis.Rotate(lightUp, Radians(-lightRotationSpeed));
                } else if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
            } else if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        render();

        window.display();
    }

    return 0;
}
