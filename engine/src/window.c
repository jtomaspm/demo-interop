#include "../engine.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

static GLFWwindow* WINDOW = NULL;

void glfw_framebuffer_size_callback(GLFWwindow* window, int width, int height){
    (void)window;
    glViewport(0, 0, width, height);
}

void glfw_error_callback(int code, const char* description)
{
    printf("[ERROR][GLFW](%d): %s\n", code, description);
}

int engine_InitWindow(int width, int height){
    glfwSetErrorCallback(glfw_error_callback);

    if (!glfwInit()) {
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    WINDOW = glfwCreateWindow(width, height, "Demo Interop", NULL, NULL);
    if (WINDOW == NULL) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(WINDOW);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        glfwTerminate();
        return -2;
    }

    glViewport(0, 0, width, height);
    glfwSetFramebufferSizeCallback(WINDOW, glfw_framebuffer_size_callback);
    
    return 0;
}

int engine_WindowShouldClose(){
    return glfwWindowShouldClose(WINDOW);
}

void engine_RefreshWindow(){
    glfwSwapBuffers(WINDOW);
    glfwPollEvents();
}

void engine_ProcessInput(){
    if(glfwGetKey(WINDOW, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(WINDOW, 1);
}

void engine_TerminateWindow(){
    glfwTerminate();
}
