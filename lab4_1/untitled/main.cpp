#include <stdio.h>

#include <GL/glu.h>
#include <GL/gl.h>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "utils.h"

sf::Texture texture;
Vector lightPos(0.0, 1.0, -1.0), lightPos2(0.0, 1.0, 1.0), lightAxis(1.0, 0.0, 0.0), lightAxis2(-1.0, 0.0, 0.0);
const float lightRotationSpeed = 3.0;

void initialize()
{
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 10.0 };
    GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat grey_light[] = { 0.6, 0.6, 0.6, 1.0 };

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);

    GLfloat blue_light[] = { 0.0, 0.0, 1.0, 1.0 };

    glLightfv(GL_LIGHT1, GL_DIFFUSE, blue_light);
    glLightfv(GL_LIGHT1, GL_SPECULAR, blue_light);

    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 60.0);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 3.3);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, grey_light);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_CULL_FACE);
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    gluLookAt(0.0, 0.0, -3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glPushMatrix();
        sf::Texture::bind(&texture);

        GLUquadric *qobj = gluNewQuadric();
        gluQuadricTexture(qobj, GL_TRUE);

        gluSphere(qobj, 0.8, 50, 50);

        gluDeleteQuadric(qobj);
        sf::Texture::bind(0);
    glPopMatrix();

    glPushMatrix();
        GLfloat lightPosition[] = { lightPos.x, lightPos.y, lightPos.z, 1.0 };
        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

        glTranslatef(lightPos.x, lightPos.y, lightPos.z);

        qobj = gluNewQuadric();

        glColor3f(0.0, 0.0, 1.0);
        gluSphere(qobj, 0.1, 50, 50);

        gluDeleteQuadric(qobj);
    glPopMatrix();

    glPushMatrix();
        GLfloat lightPosition2[] = { lightPos2.x, lightPos2.y, lightPos2.z, 1.0 };
        GLfloat lightDirection2[] = { -lightPos2.x, -lightPos2.y, -lightPos2.z, 1.0 };

        glLightfv(GL_LIGHT1, GL_POSITION, lightPosition2);
        glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, lightDirection2);

        glTranslatef(lightPos2.x, lightPos2.y, lightPos2.z);

        qobj = gluNewQuadric();

        glColor3f(0.0, 0.0, 1.0);
        gluSphere(qobj, 0.1, 50, 50);

        gluDeleteQuadric(qobj);
    glPopMatrix();
}

void windowResizeHandler(int width, int height)
{
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(90.0f, (float) width / (float) height, 0.1f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void handleLightControls()
{
    const Vector lightUp(0.0, 1.0, 0.0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        lightPos = lightPos.Rotate(lightAxis, Radians(lightRotationSpeed));
        lightPos2 = lightPos2.Rotate(lightAxis2, Radians(lightRotationSpeed));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        lightPos = lightPos.Rotate(lightAxis, Radians(-lightRotationSpeed));
        lightPos2 = lightPos2.Rotate(lightAxis2, Radians(-lightRotationSpeed));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        lightPos = lightPos.Rotate(lightUp, Radians(lightRotationSpeed));
        lightPos2 = lightPos2.Rotate(lightUp, Radians(lightRotationSpeed));
        lightAxis = lightAxis.Rotate(lightUp, Radians(lightRotationSpeed));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        lightPos = lightPos.Rotate(lightUp, Radians(-lightRotationSpeed));
        lightPos2 = lightPos2.Rotate(lightUp, Radians(-lightRotationSpeed));
        lightAxis = lightAxis.Rotate(lightUp, Radians(-lightRotationSpeed));
    }
}

int main()
{
    sf::ContextSettings settings;

    settings.depthBits = 24;
    settings.antialiasingLevel = 16;
    settings.stencilBits = 24;

    sf::Window window(sf::VideoMode(800, 600), "OpenGL", sf::Style::Default, settings);

    window.setActive(true);

    initialize();

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
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
            } else if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        handleLightControls();

        render();

        window.display();
    }

    return 0;
}
