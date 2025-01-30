//
// Created by plaidmrdeer on 2025/1/26.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <lum/Shader.h>

#include <glad/glad.h>

ray::Shader::Shader(const char *vertexFilePath, const char *fragmentFilePath)
{
    std::ifstream vertexFile{vertexFilePath};
    std::ifstream fragmentFile{fragmentFilePath};
    std::stringstream vertexBuffer;
    std::stringstream fragmentBuffer;
    vertexBuffer << vertexFile.rdbuf();
    fragmentBuffer << fragmentFile.rdbuf();
    vertexFile.close();
    fragmentFile.close();
    vertexStr = vertexBuffer.str();
    fragmentStr = fragmentBuffer.str();
    vertexSource = vertexStr.c_str();
    fragmentSource = fragmentStr.c_str();
}

void ray::Shader::loadShader()
{
    vertexID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexID, 1, &vertexSource, nullptr);
    glCompileShader(vertexID);

    fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentID, 1, &fragmentSource, nullptr);
    glCompileShader(fragmentID);

    programID = glCreateProgram();
    glAttachShader(programID, vertexID);
    glAttachShader(programID, fragmentID);
    glLinkProgram(programID);

    glDeleteShader(vertexID);
    glDeleteShader(fragmentID);
}

void ray::Shader::useShader() const
{
    glUseProgram(programID);
}

void ray::Shader::deleteProgram() const
{
    glDeleteProgram(programID);
}


