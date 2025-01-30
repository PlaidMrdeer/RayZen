//
// Created by plaidmrdeer on 2024/12/20.
//
#include <lum/Window.h>

#include "lum/Shader.h"

int main()
{
    float vertices[] = {
    0.5f, 0.0f, 0.0f,
   -0.5f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f
    };
    ray::Window window{800, 600, "triangle"};
    window.create();
    ray::Opengl gl;
    gl.init(vertices, sizeof(vertices));
    window.show(gl);
    window.cleanup();
    gl.deleteVBO();
    gl.deleteVAO();
}
