#include <GL/glew.h>
#include <GL/glut.h>
#include <glm/glm.hpp>

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
    std::vector<glm::vec2> points;
    GLuint vbo, prog;
};

void CheckStatus( const GLenum id )
{
    GLint status = GL_FALSE, loglen = 10;
    if( glIsShader(id) )    glGetShaderiv( id, GL_COMPILE_STATUS, &status );
    if( glIsProgram(id) )   glGetProgramiv( id, GL_LINK_STATUS, &status );
    if( GL_TRUE == status ) return;
    if( glIsShader(id) )    glGetShaderiv( id, GL_INFO_LOG_LENGTH , &loglen);
    if( glIsProgram(id) )   glGetProgramiv( id, GL_INFO_LOG_LENGTH , &loglen);
    vector< char > log( loglen, 'E' );
    if( glIsShader(id) )    glGetShaderInfoLog( id, loglen, NULL, &log[0] );
    if( glIsProgram(id) )   glGetProgramInfoLog( id, loglen, NULL, &log[0] );
    throw logic_error( string( log.begin(), log.end() ) );
}

GLuint CreateShader( const GLenum aType, const string aSource )
{
    GLuint shader = glCreateShader( aType );
    const GLchar* source = (const GLchar*) aSource.c_str();
    glShaderSource( shader, 1, &source, NULL );
    glCompileShader( shader );
    CheckStatus( shader );
    return shader;
}

GLuint CreateProgram( const string aVertexShader, const string aFragmentShader )
{
    GLuint vert = CreateShader( GL_VERTEX_SHADER, aVertexShader );
    GLuint frag = CreateShader( GL_FRAGMENT_SHADER, aFragmentShader );
    GLuint program = glCreateProgram();
    glAttachShader( program, vert );
    glAttachShader( program, frag );
    glLinkProgram( program );
    glDeleteShader( vert );
    glDeleteShader( frag );
    CheckStatus( program );
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
    Global::prog = CreateProgram(vert, frag);

    // fill vertices
    Global::points.push_back(glm::vec2(0.2, 0.5));
    Global::points.push_back(glm::vec2(0.7, 0.5));
    Global::points.push_back(glm::vec2(0.5, 0.2));

    // create and fill VBO
    glGenBuffers(1, &Global::vbo);
    glBindBuffer(GL_ARRAY_BUFFER, Global::vbo);
    unsigned int numBytes = sizeof(glm::vec2) * Global::points.size();
    glBufferData(GL_ARRAY_BUFFER, numBytes, &Global::points[0].x, GL_STATIC_DRAW);
}

void display(void)
{
    glClear( GL_COLOR_BUFFER_BIT );

    glUseProgram( Global::prog );

    GLint position_loc = glGetAttribLocation( Global::prog, "position" );
    glBindBuffer( GL_ARRAY_BUFFER, Global::vbo );
    glVertexAttribPointer( position_loc, 2, GL_FLOAT, GL_FALSE, sizeof( glm::vec2 ), 0 );
    glEnableVertexAttribArray( position_loc );

    glDrawArrays( GL_TRIANGLES, 0, Global::points.size() );

    glDisableVertexAttribArray( position_loc );

    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit( &argc, argv );
    glutInitWindowSize( 800,600 );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
    glutCreateWindow( "Sierpinski gasket" );
    init();
    glutDisplayFunc( display );
    glutMainLoop();
    return 0;
}
