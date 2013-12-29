#include <GL/glew.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;

std::string getFileContent(char* filename)
{
    std::ifstream ifile(filename);
    std::string filetext;

    while (ifile.good())
    {
        std::string line;
        std::getline(ifile, line);
        filetext.append(line + "\n");
    }

    return filetext;
}

namespace Global
{
    GLfloat points[] = {
        0.2, 0.5,
        0.7, 0.5,
        0.5, 0.2
    };

    int points_num = 3;

    GLuint vbo, prog;
};

void checkShaderObjectStatus(const GLenum id)
{
    GLint status = GL_FALSE, loglen = 10;

    if (glIsShader(id))
        glGetShaderiv(id, GL_COMPILE_STATUS, &status);

    if (glIsProgram(id))
        glGetProgramiv(id, GL_LINK_STATUS, &status);

    if (GL_TRUE == status)
        return;

    if (glIsShader(id))
        glGetShaderiv(id, GL_INFO_LOG_LENGTH , &loglen);

    if (glIsProgram(id))
        glGetProgramiv(id, GL_INFO_LOG_LENGTH , &loglen);

    vector<char> log(loglen, 'E');

    if (glIsShader(id))
        glGetShaderInfoLog(id, loglen, NULL, &log[0]);

    if (glIsProgram(id))
        glGetProgramInfoLog( id, loglen, NULL, &log[0]);

    throw logic_error(string(log.begin(), log.end()));
}

GLuint createShader(const GLenum shaderType, const string shaderSource)
{
    GLuint shader = glCreateShader( shaderType );
    const GLchar* source = (const GLchar*) shaderSource.c_str();
    glShaderSource( shader, 1, &source, NULL );
    glCompileShader( shader );
    checkShaderObjectStatus( shader );
    return shader;
}

GLuint createShaderProgram(const string vertexShaderSource, const string fragmentShaderSource)
{
    GLuint vert = createShader(GL_VERTEX_SHADER, vertexShaderSource);
    GLuint frag = createShader(GL_FRAGMENT_SHADER, fragmentShaderSource);
    GLuint program = glCreateProgram();

    glAttachShader(program, vert);
    glAttachShader(program, frag);
    glLinkProgram(program);

    glDeleteShader(vert);
    glDeleteShader(frag);

    checkShaderObjectStatus(program);

    return program;
}

void init()
{
    GLenum glewError = glewInit();

    if (GLEW_OK != glewError)
    {
        throw runtime_error((char*) glewGetErrorString(glewError));
    }

    printf("GL_VERSION: %s\n", glGetString(GL_VERSION));
    printf("GL_RENDERER: %s\n", glGetString(GL_RENDERER));
    printf("GLEW_VERSION: %s\n", glewGetString(GLEW_VERSION));
    printf("GLSL_VERSION: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));

    if (!GLEW_VERSION_2_1)
    {
        throw runtime_error("OpenGL 2.1 or better required for GLSL support.");
    }

    std::string vert = getFileContent("../data/vertex.glsl");
    std::string frag = getFileContent("../data/fragment.glsl");

    // load shaders
    Global::prog = createShaderProgram(vert, frag);

    // create and fill VBO
    glGenBuffers(1, &Global::vbo);
    glBindBuffer(GL_ARRAY_BUFFER, Global::vbo);
    // 2 components per vertex * 3 vertices
    unsigned int numBytes = sizeof(GLfloat) * 2 * Global::points_num;
    glBufferData(GL_ARRAY_BUFFER, numBytes, &Global::points, GL_STATIC_DRAW);
}

void render()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(Global::prog);

    GLint position_loc = glGetAttribLocation(Global::prog, "position");
    glBindBuffer(GL_ARRAY_BUFFER, Global::vbo);
    glVertexAttribPointer(position_loc, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 2, 0);
    glEnableVertexAttribArray(position_loc);

    glDrawArrays(GL_TRIANGLES, 0, Global::points_num);

    glDisableVertexAttribArray(position_loc);
}

void handleKeys(sf::Window *window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        window->close();
    }
}

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 16;
    settings.depthBits = 24;
    settings.stencilBits = 24;

    sf::Window window(sf::VideoMode(800, 600), "lab6", sf::Style::Close, settings);

    init();

    while (window.isOpen())
    {
        sf::Event windowEvent;

        while (window.pollEvent(windowEvent))
        {
            if (windowEvent.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        handleKeys(&window);

        render();

        window.display();
    }

    return 0;
}
