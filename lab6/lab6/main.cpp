#include <GL/glew.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stdexcept>

#include "utils.h"

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
    GLuint vbo, prog;

    aiScene* scene = 0;
    aiMesh* mesh = 0;

    Vector camPos(0.0, 1.0, -150.0), camXAxis(1.0, 0.0, 0.0);

    float camRotationSpeed = 5.0;
}

void renderSceneNode()
{
    glPushMatrix();

    // rendering node itself
    glBindBuffer(GL_ARRAY_BUFFER, Global::vbo);
    glDrawArrays(GL_TRIANGLES, 0, Global::mesh->mNumVertices);

    glPopMatrix();
}

void prepareSceneNode()
{
    Global::scene = (aiScene*) aiImportFile("../data/pyro/pyro.3ds", aiProcessPreset_TargetRealtime_MaxQuality);

    Global::mesh = Global::scene->mMeshes[Global::scene->mRootNode->mChildren[0]->mMeshes[0]];

    // create and fill VBO
    glGenBuffers(1, &Global::vbo);
    glBindBuffer(GL_ARRAY_BUFFER, Global::vbo);

    // 2 components per vertex * 3 vertices
    unsigned int numBytes = sizeof(aiVector3D) * Global::mesh->mNumVertices;
    glBufferData(GL_ARRAY_BUFFER, numBytes, &Global::mesh->mVertices, GL_STATIC_DRAW);
}

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

    std::vector<char> log(loglen, 'E');

    if (glIsShader(id))
        glGetShaderInfoLog(id, loglen, NULL, &log[0]);

    if (glIsProgram(id))
        glGetProgramInfoLog( id, loglen, NULL, &log[0]);

    throw std::logic_error(std::string(log.begin(), log.end()));
}

GLuint createShader(const GLenum shaderType, const std::string shaderSource)
{
    GLuint shader = glCreateShader( shaderType );
    const GLchar* source = (const GLchar*) shaderSource.c_str();
    glShaderSource( shader, 1, &source, NULL );
    glCompileShader( shader );
    checkShaderObjectStatus( shader );
    return shader;
}

GLuint createShaderProgram(const std::string vertexShaderSource, const std::string fragmentShaderSource)
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
        throw std::runtime_error((char*) glewGetErrorString(glewError));
    }

    printf("GL_VERSION: %s\n", glGetString(GL_VERSION));
    printf("GL_RENDERER: %s\n", glGetString(GL_RENDERER));
    printf("GLEW_VERSION: %s\n", glewGetString(GLEW_VERSION));
    printf("GLSL_VERSION: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));

    if (!GLEW_VERSION_2_1)
    {
        throw std::runtime_error("OpenGL 2.1 or better required for GLSL support.");
    }

    glEnable(GL_DEPTH_TEST);

    glEnable(GL_CULL_FACE);
    glEnable(GL_TEXTURE_2D);

    std::string vert = getFileContent("../data/vertex.glsl");
    std::string frag = getFileContent("../data/fragment.glsl");

    // load shaders
    Global::prog = createShaderProgram(vert, frag);

    // create and fill VBO
    prepareSceneNode();
}

void render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    gluLookAt(Global::camPos.x, Global::camPos.y, Global::camPos.z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glUseProgram(Global::prog);

    GLint position_loc = glGetAttribLocation(Global::prog, "position");

    glBindBuffer(GL_ARRAY_BUFFER, Global::vbo);
    glVertexAttribPointer(position_loc, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, 0);
    glEnableVertexAttribArray(position_loc);

    renderSceneNode();

    //glDisableVertexAttribArray(position_loc);
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

void handleKeys(sf::Window *window)
{
    const Vector camUp(0.0, 1.0, 0.0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        Global::camPos = Global::camPos.Rotate(Global::camXAxis, Radians(Global::camRotationSpeed));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        Global::camPos = Global::camPos.Rotate(Global::camXAxis, Radians(-Global::camRotationSpeed));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        Global::camPos = Global::camPos.Rotate(camUp, Radians(Global::camRotationSpeed));
        Global::camXAxis = Global::camXAxis.Rotate(camUp, Radians(Global::camRotationSpeed));

        printf("%0.3f, %0.3f, %0.3f\n", Global::camPos.x, Global::camPos.y, Global::camPos.z);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        Global::camPos = Global::camPos.Rotate(camUp, Radians(-Global::camRotationSpeed));
        Global::camXAxis = Global::camXAxis.Rotate(camUp, Radians(-Global::camRotationSpeed));

        printf("%0.3f, %0.3f, %0.3f\n", Global::camPos.x, Global::camPos.y, Global::camPos.z);
    }

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

            if (windowEvent.type == sf::Event::Resized)
            {
                windowResizeHandler(windowEvent.size.width, windowEvent.size.height);
            }
        }

        handleKeys(&window);

        render();

        window.display();
    }

    return 0;
}
