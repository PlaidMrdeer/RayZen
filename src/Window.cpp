//
// Created by plaidmrdeer on 2024/12/21.
//


#include <glad/glad.h>
#include <lum/Window.h>
#include <lum/Opengl.h>

void framebufferSizeCallback(GLFWwindow* window, int width, int height);
GLFWwindow *ray::Window::windowHandle = nullptr;
ray::Window::Window(const int width, const int height, const char *title)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    settings.width = width;
    settings.height = height;
    settings.title = title;
}

void ray::Window::create() const
{
    windowHandle = glfwCreateWindow(settings.width, settings.height, settings.title, nullptr, nullptr);
    glfwMakeContextCurrent(windowHandle);
    gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));
    glfwSetFramebufferSizeCallback(windowHandle, framebufferSizeCallback);
}

void ray::Window::show(const Opengl &oepngl)
{
    while (!glfwWindowShouldClose(windowHandle))
    {

        
        oepngl.draw();
        glfwSwapBuffers(windowHandle);
        glfwPollEvents();
    }
}

GLFWwindow *ray::Window::getWindow()
{
    return windowHandle;
}


void ray::Window::cleanup() const
{
    glfwDestroyWindow(windowHandle);
    glfwTerminate();
}

void framebufferSizeCallback(GLFWwindow* window, const int width, const int height)
{
    glViewport(0, 0, width, height);
}
