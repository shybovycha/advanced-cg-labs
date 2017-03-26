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

    // Enable depth test
    glEnable(GL_DEPTH_TEST);

    // Setup a perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.f, 1.f, 1.f, 500.f);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    // setup some primitive camera!
    sf::Vector3f eye(0, 0, 500.0), lookat(0, 0, 0), up(0, 1, 0);

    GLfloat vertices[] = {
        0, 0, 0,
        20, 80, 0,
        40, 0, 0,
        0, 50, 0,
        40, 50, 0
    };

    GLuint indices[] = {
        0, 1,
        1, 2,
        2, 3,
        3, 4,
        4, 0
    };

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

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glLoadIdentity();

        glPushMatrix();
            gluLookAt(eye.x, eye.y, eye.z, lookat.x, lookat.y, lookat.z, up.x, up.y, up.z);
            // glTranslatef(0.f, 0.f, -100.f);

            glPushMatrix();
                // activate and specify pointer to vertex array
                glEnableClientState(GL_VERTEX_ARRAY);
                glVertexPointer(3, GL_FLOAT, 0, vertices);

                glColor3f(0.39, 0.81, 0.56);
                glDrawElements(GL_LINES, sizeof(indices) / sizeof(GLfloat), GL_UNSIGNED_INT, indices);
            glPopMatrix();
        glPopMatrix();

        window.display();
    }

    return 0;
}
