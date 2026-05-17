#include "../engine.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

static GLFWwindow* WINDOW = NULL;

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    (void)window;
    glViewport(0, 0, width, height);
}

int engine_InitWindow(int width, int height){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    WINDOW = glfwCreateWindow(width, height, "Demo Interop", NULL, NULL);
    if (WINDOW == NULL) {
        printf("failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(WINDOW);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("failed to initialize GLAD\n");
        glfwTerminate();
        return -2;
    }

    glViewport(0, 0, width, height);
    glfwSetFramebufferSizeCallback(WINDOW, framebuffer_size_callback);
    
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
