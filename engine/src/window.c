#include "../engine.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

static GLFWwindow* WINDOW = NULL;

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    (void)window;
    glViewport(0, 0, width, height);
}


int engine_InitWindow(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    WINDOW = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Demo Interop", NULL, NULL);
    if (WINDOW == NULL) {
        printf("failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(WINDOW);

    if(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("failed to initialize GLAD\n");
        return -2;
    }

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glfwSetFramebufferSizeCallback(WINDOW, framebuffer_size_callback);
    
    return 0;
}

int engine_WindowShouldClose(){
    return glfwWindowShouldClose(WINDOW);
}

void engine_RenderPass(){
    glfwSwapBuffers(WINDOW);
    glfwPollEvents();
}

void engine_TerminateWindow(){
    glfwTerminate();
}