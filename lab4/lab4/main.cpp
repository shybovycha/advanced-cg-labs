#include <GL/glew.h>
#include <GL/glu.h>
#include <GL/gl.h>

#include <stdio.h>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "utils.h"

#ifdef WIN32
    #ifdef _DEBUG
        #pragma comment(lib, "sfml-main-d.lib")
        #pragma comment(lib, "sfml-graphics-d.lib")
        #pragma comment(lib, "sfml-system-d.lib")
        #pragma comment(lib, "sfml-window-d.lib")
        #pragma comment(lib, "glew32.lib")
        #pragma comment(lib, "glu32.lib")
        #pragma comment(lib, "opengl32.lib")
        #pragma comment(lib, "assimp.lib")
    #else
        #pragma comment(lib, "sfml-main.lib")
        #pragma comment(lib, "sfml-graphics.lib")
        #pragma comment(lib, "sfml-system.lib")
        #pragma comment(lib, "sfml-window.lib")
        #pragma comment(lib, "glew32.lib")
        #pragma comment(lib, "glu32.lib")
        #pragma comment(lib, "opengl32.lib")
        #pragma comment(lib, "assimp.lib")
    #endif
#endif

int main()
{
    // create the window (remember: it's safer to create it in the main thread due to OS limitations)
    sf::Window window(sf::VideoMode(800, 600), "OpenGL");

    // activate the window's context
    window.setActive(true);

    glFrontFace(GL_CW);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    /*
     *Set GL_LIGHT_0's position to something like 45 degrees to the 'vertical'. Coordinate (1,1,0) should work nicely in most cases.
Set GL_LIGHT_0's Ambient color to 0,0,0,1
Set GL_LIGHT_0's Diffuse color to 1,1,1,1
Set GL_LIGHT_0's Specular color to 1,1,1,1
Set the glLightModel's global ambient to 0.2,0.2,0.2,1 (this is the default).
Don't set any other glLight or glLightModel options - just let them default.
Enable GL_LIGHTING and GL_LIGHT_0.
Enable GL_COLOR_MATERIAL and set glColorMaterial to GL_AMBIENT_AND_DIFFUSE. This means that glMaterial will control the polygon's specular and emission colours and the ambient and diffuse will both be set using glColor.
Set the glMaterial's Specular colour to 1,1,1,1
Set the glMaterial's Emission colour to 0,0,0,1
Set the glColor to whatever colour you want each polygon to basically appear to be. That sets the Ambient and Diffuse to the same value which is what you generally want.
     */

    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR);

    // Ruby material
    GLfloat mat_ambient[] = { 0.1745, 0.01175, 0.01175, 0.55 };
    GLfloat mat_diffuse[] = { 0.61424, 0.04136, 0.04136, 0.45 };
    GLfloat mat_specular[] = { 0.727811, 0.626959, 0.626959, 0.55 };
    GLfloat mat_shininess[] = { 76.8 };

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, mat_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffuse);
    glLightfv(GL_LIGHT0,GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT | GL_BACK, GL_SHININESS, mat_shininess);

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

    // Setup a perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.f, ((GLfloat) window.getSize().x) / ((GLfloat) window.getSize().y), 0.1f, 10000.f);
    glMatrixMode(GL_MODELVIEW);

    // setup some primitive camera!
    Vector eye(0, 0, -250.0), lookat(0, 0, 0), up(0, 1, 0);

    GLfloat euler_camera[] = { 0, 0, 0 };

    GLfloat vertices[] = {
        0, 0, 0,
        0, 0, 10,
        0, 10, 0,
        0, 10, 10,
        10, 0, 0,
        10, 0, 10,
        10, 10, 0,
        10, 10, 10
    };

    GLfloat normals[] = {
        -0.5, -0.5, 0.5,
        -0.5, -0.5, -0.5,
        -0.5, 0.5, 0.5,
        -0.5, 0.5, -0.5,
        0.5, -0.5, 0.5,
        0.5, -0.5, -0.5,
        0.5, 0.5, 0.5,
        0.5, 0.5, -0.5
    };

    GLfloat uvs[] = {
        0, 0,
        0, 0,
        0, 1,
        0, 1,
        1, 0,
        1, 0,
        1, 1,
        1, 1
    };

    GLuint indices[] = {
        0, 2, 6, 4,
        4, 6, 7, 5,
        2, 3, 7, 6,
        2, 3, 1, 0,
        3, 7, 5, 1,
        0, 1, 5, 4
    };

    sf::Texture wood_texture, raspberry_texture, honeycomb_texture;

    wood_texture.loadFromFile("../../test/textures/wood.jpg");
    raspberry_texture.loadFromFile("../../test/textures/Raspberr.jpg");
    honeycomb_texture.loadFromFile("../../test/textures/honycomb.jpg");

    int old_mouse_x = window.getSize().x / 2, old_mouse_y = window.getSize().y / 2;
    sf::Mouse::setPosition(sf::Vector2i(old_mouse_x, old_mouse_y));

    GLfloat light_position_a[] = { -50, -50, 80, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position_a);

    // the rendering loop
    while (window.isOpen())
    {
        sf::Event event;

        // while there are pending events...
        while (window.pollEvent(event))
        {
            // check the type of the event...
            switch (event.type)
            {
                case sf::Event::MouseMoved:
                    euler_camera[0] += Degree((GLfloat) (old_mouse_y - event.mouseMove.y) / 100.0f);
                    euler_camera[1] += Degree((GLfloat) (old_mouse_x - event.mouseMove.x) / 100.0f);

                    while (euler_camera[0] > 360.0) euler_camera[0] -= 360.0;
                    while (euler_camera[0] < 0.0) euler_camera[0] += 360.0;
                    while (euler_camera[1] > 360.0) euler_camera[1] -= 360.0;
                    while (euler_camera[1] < 0.0) euler_camera[1] += 360.0;

                    old_mouse_x = event.mouseMove.x;
                    old_mouse_y = event.mouseMove.y;
                break;

                case sf::Event::Closed:
                    window.close();
                break;

                case sf::Event::Resized:
                    glViewport(0, 0, (GLsizei) event.size.width, (GLsizei) event.size.height);

                    glMatrixMode(GL_PROJECTION);
                    glLoadIdentity();
                    gluPerspective(45.0, event.size.width / (GLdouble) event.size.height, 0.1, 10000.0);

                    glMatrixMode(GL_MODELVIEW);
                    glLoadIdentity();
                break;

                default:
                break;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            euler_camera[1] -= Degree(0.01);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            euler_camera[1] += Degree(0.01);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            euler_camera[0] -= Degree(0.01);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            euler_camera[0] += Degree(0.01);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();

        glClearColor(1, 1, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glLoadIdentity();

        glDisable(GL_LIGHTING);

        glPushMatrix();
            gluLookAt(eye.x, eye.y, eye.z, lookat.x, lookat.y, lookat.z, up.x, up.y, up.z);

            // TODO: replace all this sh*t with quaternion rotations!
            glRotatef(euler_camera[0], 1, 0, 0);
            glRotatef(euler_camera[1], 0, 1, 0);
            glRotatef(euler_camera[2], 0, 0, 1);

                glColor3f(0, 1, 0);

                glBegin(GL_LINES);
                    glVertex3f(0, 0, 0);
                    glVertex3f(0, 100, 0);
                glEnd();

                glColor3f(1, 0, 0);

                glBegin(GL_LINES);
                    glVertex3f(0, 0, 0);
                    glVertex3f(100, 0, 0);
                glEnd();

                glColor3f(0, 0, 1);

                glBegin(GL_LINES);
                    glVertex3f(0, 0, 0);
                    glVertex3f(0, 0, 100);
                glEnd();

            glTranslatef(-50, -50, 50);

            glDisable(GL_BLEND);
            sf::Texture::bind(&raspberry_texture);
            glColor4f(0.6, 0.6, 0.6, 1.0);

            glBegin(GL_QUADS);
                glVertex2f(20, 20);
                glTexCoord2f(0, 0);
                glNormal3f(0, 0, 1);

                glVertex2f(20, 80);
                glTexCoord2f(0, 1);
                glNormal3f(0, 0, 1);

                glVertex2f(80, 80);
                glTexCoord2f(1, 0);
                glNormal3f(0, 0, 1);

                glVertex2f(80, 20);
                glTexCoord2f(1, 1);
                glNormal3f(0, 0, 1);
            glEnd();

            sf::Texture::bind(0);

            glEnable(GL_LIGHTING);

            glTranslatef(-50, -50, -150);

            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

            sf::Texture::bind(&honeycomb_texture);
            glColor4f(1.0, 0.1, 0.1, 0.7);

            glBegin(GL_POLYGON);
                glVertex2f(10, 0);
                glTexCoord2f(0.25, 1.0);
                glNormal3f(0, 0, 1);

                glVertex2f(0, 20);
                glTexCoord2f(0, 0.5);
                glNormal3f(0, 0, 1);

                glVertex2f(20, 40);
                glTexCoord2f(0.5, 0);
                glNormal3f(0, 0, 1);

                glVertex2f(40, 20);
                glTexCoord2f(1, 0.5);
                glNormal3f(0, 0, 1);

                glVertex2f(30, 0);
                glTexCoord2f(0.75, 1);
                glNormal3f(0, 0, 1);
            glEnd();

            sf::Texture::bind(0);

            glPushMatrix();
                sf::Texture::bind(&wood_texture);

                // activate and specify pointer to vertex array
                glEnableClientState(GL_VERTEX_ARRAY);
                glVertexPointer(3, GL_FLOAT, 0, vertices);

                glEnableClientState(GL_TEXTURE_COORD_ARRAY);
                glTexCoordPointer(2, GL_FLOAT, 0, uvs);

                glEnableClientState(GL_NORMAL_ARRAY);
                glNormalPointer(GL_FLOAT, 0, normals);

                glEnable(GL_BLEND);
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

                // glColor4f(0.39, 0.81, 0.56, 0.6);
                glColor4f(1.0, 0.1, 0.1, 0.7);
                glDrawElements(GL_QUADS, sizeof(indices) / sizeof(GLfloat), GL_UNSIGNED_INT, indices);

                sf::Texture::bind(0);
            glPopMatrix();
        glPopMatrix();

        window.display();
    }

    return 0;
}
