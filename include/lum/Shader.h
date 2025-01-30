//
// Created by plaidmrdeer on 2025/1/26.
//

#ifndef SHADER_H
#define SHADER_H

#include <string>

namespace ray
{
    class Shader
    {
    public:
        Shader() = default;
        Shader(const char *vertexFilePath, const char *fragmentFilePath);
        void loadShader();
        void useShader() const;
        void deleteProgram() const;
    private:
        std::string vertexStr;
        std::string fragmentStr;
        const char *vertexSource{};
        const char *fragmentSource{};
        unsigned int vertexID = 0;
        unsigned int fragmentID = 0;
        unsigned int programID = 0;
    };
} // lum

#endif //SHADER_H
