#include "utils.h"

#define printOpenGLError() printOglError(__FILE__, __LINE__)

int printOglError(char *file, int line)
{
    GLenum glErr;
    int    retCode = 0;

    glErr = glGetError();
    if (glErr != GL_NO_ERROR)
    {
        printf("glError in file %s @ line %d: %s\n",
                 file, line, gluErrorString(glErr));
        retCode = 1;
    }
    return retCode;
}

void printLog(GLuint obj)
{
    int infologLength = 0;
    int maxLength;

    if(glIsShader(obj))
        glGetShaderiv(obj,GL_INFO_LOG_LENGTH,&maxLength);
    else
        glGetProgramiv(obj,GL_INFO_LOG_LENGTH,&maxLength);

    char infoLog[maxLength];

    if (glIsShader(obj))
        glGetShaderInfoLog(obj, maxLength, &infologLength, infoLog);
    else
        glGetProgramInfoLog(obj, maxLength, &infologLength, infoLog);

    if (infologLength > 0)
        printf("%s\n",infoLog);
}

char* getShaderSource(char* filename)
{
    FILE *f = fopen(filename, "r");

    fseek(f, 0, SEEK_END);
    int file_size = ftell(f);
    rewind(f);

    char* data = (char*) malloc(file_size * sizeof(char));

    fread((char*) data, file_size, sizeof(char), f);

    fclose(f);

    return data;
}

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 16;
    settings.depthBits = 24;
    settings.stencilBits = 24;

    sf::Window window(sf::VideoMode(800, 600), "moofoo", sf::Style::Close, settings);

    const GLchar* vertexSource = (const GLchar*) getShaderSource("../data/vertex.glsl");
    const GLchar* fragmentSource = (const GLchar*) getShaderSource("../data/fragment.glsl");

    // Initialize GLEW
        glewExperimental = GL_TRUE;
        glewInit();

        // Create Vertex Array Object
        GLuint vao;
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        // Create a Vertex Buffer Object and copy the vertex data to it
        GLuint vbo;
        glGenBuffers(1, &vbo);

        GLfloat vertices[] = {
             0.0f,  0.5f, 1.0f, 0.0f, 0.0f,
             0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
            -0.5f, -0.5f, 0.0f, 0.0f, 1.0f
        };

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        // Create and compile the vertex shader
        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexSource, NULL);
        glCompileShader(vertexShader);

        // Create and compile the fragment shader
        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
        glCompileShader(fragmentShader);

        // Link the vertex and fragment shader into a shader program
        GLuint shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glBindFragDataLocation(shaderProgram, 0, "outColor");
        glLinkProgram(shaderProgram);
        glUseProgram(shaderProgram);

        // Specify the layout of the vertex data
        GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
        glEnableVertexAttribArray(posAttrib);
        glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);

        GLint colAttrib = glGetAttribLocation(shaderProgram, "color");
        glEnableVertexAttribArray(colAttrib);
        glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));

        while (window.isOpen())
        {
            sf::Event windowEvent;
            while (window.pollEvent(windowEvent))
            {
                switch (windowEvent.type)
                {
                case sf::Event::Closed:
                    window.close();
                    break;
                }
            }

            // Clear the screen to black
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            // Draw a triangle from the 3 vertices
            glDrawArrays(GL_TRIANGLES, 0, 3);

            // Swap buffers
            window.display();
        }

        glDeleteProgram(shaderProgram);
        glDeleteShader(fragmentShader);
        glDeleteShader(vertexShader);

        glDeleteBuffers(1, &vbo);

        glDeleteVertexArrays(1, &vao);
}
