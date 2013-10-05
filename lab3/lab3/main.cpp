#include <GL/glew.h>
#include <GL/glu.h>
#include <GL/gl.h>

#include <stdio.h>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

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

    // Setup a perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.f, ((GLfloat) window.getSize().x) / ((GLfloat) window.getSize().y), 0.1f, 10000.f);
    glMatrixMode(GL_MODELVIEW);

    // setup some primitive camera!
    sf::Vector3f eye(0, 0, 200.0), lookat(0, 0, 0), up(0, 1, 0);

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
                // window closed
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

                // we don't process other types of events
                default:
                break;
            }
        }

        glClearColor(1, 1, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glLoadIdentity();

        glPushMatrix();
            glTranslatef(-50, -50, -150);

            sf::Texture::bind(&raspberry_texture);
            glColor4f(0.6, 0.6, 0.6, 0);

            glBegin(GL_QUADS);
                glVertex2f(20, 20);
                glTexCoord2f(0, 0);

                glVertex2f(20, 80);
                glTexCoord2f(0, 1);

                glVertex2f(80, 80);
                glTexCoord2f(1, 0);

                glVertex2f(80, 20);
                glTexCoord2f(1, 1);
            glEnd();

            sf::Texture::bind(0);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-50, -50, -150);

            sf::Texture::bind(&honeycomb_texture);
            glColor4f(0.6, 0.6, 0.6, 0);

            glBegin(GL_POLYGON);
                glVertex2f(10, 0);
                glTexCoord2f(0.25, 1.0);

                glVertex2f(0, 20);
                glTexCoord2f(0, 0.5);

                glVertex2f(20, 40);
                glTexCoord2f(0.5, 0);

                glVertex2f(40, 20);
                glTexCoord2f(1, 0.5);

                glVertex2f(30, 0);
                glTexCoord2f(0.75, 1);
            glEnd();

            sf::Texture::bind(0);
        glPopMatrix();

        glPushMatrix();
            gluLookAt(eye.x, eye.y, eye.z, lookat.x, lookat.y, lookat.z, up.x, up.y, up.z);

            glTranslatef(30.f, 0.f, 0.f);
            glRotatef(3.14f, 0.f, 1.f, 0.f);
            glScalef(2.f, 1.f, 1.f);

            glPushMatrix();
                sf::Texture::bind(&wood_texture);

                // activate and specify pointer to vertex array
                glEnableClientState(GL_VERTEX_ARRAY);
                glVertexPointer(3, GL_FLOAT, 0, vertices);

                glEnableClientState(GL_TEXTURE_COORD_ARRAY);
                glTexCoordPointer(2, GL_FLOAT, 0, uvs);

                glColor3f(0.39, 0.81, 0.56);
                glDrawElements(GL_QUADS, sizeof(indices) / sizeof(GLfloat), GL_UNSIGNED_INT, indices);

                sf::Texture::bind(0);
            glPopMatrix();
        glPopMatrix();

        window.display();
    }

    return 0;
}
