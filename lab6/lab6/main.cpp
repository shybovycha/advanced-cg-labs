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

    GLushort indices[] = { 0, 1, 2 };

    // Create Index Buffer Object
    GLuint ibo;
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * sizeof(GLushort), indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // Create a Vertex Buffer Object and copy the vertex data to it
    GLfloat vertices[] = {
         0.0f,  0.5f, 1.0f, 0.0f, 0.0f,
         0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f
    };

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    // here, 3 * sizeof(vertex_struct). since vertex_struct is just a set of 5 elements, we get this: 3 * (5 * sizeof(GLfloat))
    glBufferData(GL_ARRAY_BUFFER, 3 * (5 * sizeof(GLfloat)), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Create Vertex Array Object
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Bind the VBO and setup pointers for the VAO
    GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
    GLint colAttrib = glGetAttribLocation(shaderProgram, "color");

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);
    glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));
    glEnableVertexAttribArray(posAttrib);
    glEnableVertexAttribArray(colAttrib);

    // Bind the IBO for the VAO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

    // cleanup
    glBindVertexArray(0);
    glDisableVertexAttribArray(posAttrib);
    glDisableVertexAttribArray(colAttrib);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    printLog(ibo);
    printLog(vbo);
    printLog(vao);
    printOpenGLError();

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

        // Draw command
        // The first to last vertex is 0 to 3
        // 3 indices will be used to render a single triangle.
        // The last parameter is the start address in the IBO => zero
        glUseProgram(shaderProgram);
        glBindVertexArray(vao);
        glDrawRangeElements(GL_TRIANGLES, 0, 3, 3, GL_UNSIGNED_SHORT, NULL);

        // Swap buffers
        window.display();
    }

    glDeleteProgram(shaderProgram);
    glDeleteShader(fragmentShader);
    glDeleteShader(vertexShader);

    glDeleteBuffers(1, &vbo);

    glDeleteVertexArrays(1, &vao);
}
