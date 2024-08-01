#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "OpenGL Check", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    if (GLEW_ARB_shader_storage_buffer_object) {
        std::cout << "GL_SHADER_STORAGE_BUFFER is supported" << std::endl;
    } else {
        std::cout << "GL_SHADER_STORAGE_BUFFER is not supported" << std::endl;
    }

    if (GLEW_VERSION_4_2) {
        std::cout << "OpenGL 4.2 is supported" << std::endl;
    } else {
        std::cout << "OpenGL 4.2 is not supported" << std::endl;
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
