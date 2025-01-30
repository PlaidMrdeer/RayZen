//
// Created by plaidmrdeer on 2025/1/24.
//

#include <cmath>
#include <iostream>
#include <lum/Opengl.h>

#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include <lum/Shader.h>


void ray::Opengl::init(float vertex[], const int vertexSize)
{
    this->vertexSize = vertexSize;
    this->vertex = vertex;


    shader = Shader{"/home/plaidmrdeer/dev/RayZen/examples/triangle/shader/shader.vert", "/home/plaidmrdeer/dev/RayZen/examples/triangle/shader/shader.frag"};
    shader.loadShader();
    createVAO();
    createVBO();
    bindVAO();
    bindVBO();
    putData();
    setAnalysis();
    
    unBindVBO();
    unBindVAO();
}

void ray::Opengl::createVAO()
{
    glGenVertexArrays(1, &vaoId);
}

void ray::Opengl::createVBO()
{
    glGenBuffers(1, &vboId);
}

void ray::Opengl::createEBO()
{
    glGenBuffers(1, &eboId);
}

void ray::Opengl::bindVAO() const
{
    glBindVertexArray(vaoId);
}

void ray::Opengl::bindVBO() const
{
    glBindBuffer(GL_ARRAY_BUFFER, vboId);
}

void ray::Opengl::bindEBO() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboId);
}


void ray::Opengl::unBindVAO()
{
    glBindVertexArray(0);
}

void ray::Opengl::unBindVBO()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void ray::Opengl::unBindEBO()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void ray::Opengl::putData() const
{
    glBufferData(GL_ARRAY_BUFFER, vertexSize, vertex, GL_STATIC_DRAW);
    // glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, indices, GL_STATIC_DRAW);
}

void ray::Opengl::setAnalysis()
{
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);
}

void ray::Opengl::deleteVAO() const
{
    glDeleteVertexArrays(1, &vaoId);
}

void ray::Opengl::deleteVBO() const
{
    glDeleteBuffers(1, &vboId);
}

void ray::Opengl::deleteEBO() const
{
    glDeleteBuffers(1, &eboId);
}

void ray::Opengl::draw() const
{
    glClear(GL_COLOR_BUFFER_BIT);

    shader.useShader();
    bindVAO();
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

