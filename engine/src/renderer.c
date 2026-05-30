#include "../engine.h"
#include <glad/glad.h>
#include <stdio.h>


void setup_shaders() {
    static const char *vertexShaderSource = 
        "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    int success;    
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success){
        char info[520]; 
        glGetShaderInfoLog(vertexShader, 520, NULL, info);
        printf("[ERROR][GL]: %s\n", &info[0]);
    }

    static const char *fragmentShaderSource = 
        "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\0";

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success){
        char info[520]; 
        glGetShaderInfoLog(fragmentShader, 520, NULL, info);
        printf("[ERROR][GL]: %s\n", &info[0]);
    }

    unsigned int program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(!success){
        char info[520]; 
        glGetProgramInfoLog(program, 520, NULL, info);
        printf("[ERROR][GL]: %s\n", &info[0]);
    }

    glUseProgram(program);
}

void draw_triangle(){
    static float vertices[] = {
        0.0f, 0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
    };

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    setup_shaders();
}

void engine_RenderPass(){
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    draw_triangle();
}