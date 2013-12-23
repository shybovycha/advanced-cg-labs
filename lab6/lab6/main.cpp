#define GLEW_STATIC

#include <stdio.h>
#include <map>

#include <GL/glew.h>
#include <GL/glu.h>
#include <GL/gl.h>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Application
{
protected:
    GLuint vbo, ibo, elementsNum;
    sf::Window* window;
    GLint uniColor;

    char* getShaderSource(char* filename)
    {
        FILE *f = fopen(filename, "r");

        fseek(f, 0, SEEK_END);
        int file_size = ftell(f);
        rewind(f);

        char* data = (char*) malloc(file_size * sizeof(char));

        fclose(f);

        return data;
    }

    GLuint loadVertexShader(char* filename)
    {
        char* source = getShaderSource(filename);

        GLuint shader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(shader, 1, (const GLchar**) &source, NULL);
        glCompileShader(shader);

        return shader;
    }

    GLuint loadFragmentShader(char* filename)
    {
        char* source = getShaderSource(filename);

        GLuint shader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(shader, 1, (const GLchar**) &source, NULL);
        glCompileShader(shader);

        return shader;
    }

    /*GLuint linkShaders(GLuint vertexShader, GLuint fragmentShader)
    {
        GLuint program = glCreateProgram();
        glAttachShader(program, vertexShader);
        glAttachShader(program, fragmentShader);

        glBindFragDataLocation(program, 0, "outColor");

        glLinkProgram(program);
        glUseProgram(program);

        return program;
    }*/

public:
    Application()
    {
        sf::ContextSettings settings;
        settings.antialiasingLevel = 16;
        settings.depthBits = 24;
        settings.stencilBits = 24;

        window = new sf::Window(sf::VideoMode(800, 600), "moofoo", sf::Style::Close, settings);

        GLboolean glewExperimental = GL_TRUE;

        if (glewInit() != GLEW_OK)
        {
            printf("Could not initialize GLEW\n");
            return;
        }

        initData();
    }

    void processWindowEvents()
    {
        sf::Event windowEvent;

        while (window->pollEvent(windowEvent))
        {
            if ((windowEvent.type == sf::Event::Closed) || ((windowEvent.type == sf::Event::KeyPressed) && (windowEvent.key.code == sf::Keyboard::Escape)))
            {
                window->close();
                return;
            }
        }
    }

    void initData()
    {
        float vertices[] = {
             0.0f,  0.5f, // Vertex 1 (X, Y)
             0.5f, -0.5f, // Vertex 2 (X, Y)
            -0.5f, -0.5f  // Vertex 3 (X, Y)
        };

        glGenBuffers(1, &this->vbo); // Generate 1 buffer
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        unsigned int indices[] = {
            0, 1, 2
        };

        this->elementsNum = sizeof(indices);

        glGenBuffers(1, &this->ibo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ibo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        char* source = getShaderSource("../data/vertex.glsl");

        // Create and compile the vertex shader
        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, (const GLchar**) &source, NULL);
        glCompileShader(vertexShader);

        source = getShaderSource("../data/fragment.glsl");

        // Create and compile the fragment shader
        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, (const GLchar**) &source, NULL);
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
        glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);

        // Get the location of the color uniform
        uniColor = glGetUniformLocation(shaderProgram, "triangleColor");
    }

    void render()
    {
        glUniform3f(uniColor, 0.5f, 0.0f, 0.0f);

        // Clear the screen to black
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ibo);
        // Draw a triangle from the 3 vertices
        glDrawElements(GL_TRIANGLES, this->elementsNum, GL_UNSIGNED_INT, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void run()
    {
        while (window->isOpen())
        {
            processWindowEvents();

            render();

            window->display();
        }
    }
};

int main()
{
    Application app;

    app.run();

    return 0;
}
