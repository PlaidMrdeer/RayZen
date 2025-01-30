//
// Created by plaidmrdeer on 2025/1/24.
//

#ifndef GL_H
#define GL_H
#include "Shader.h"

namespace ray
{
    class Opengl
    {
    public:
        void init(float vertex[], int vertexSize);
        void draw() const;

        void createVAO();
        void createVBO();
        void createEBO();
        void bindVAO() const;
        void bindVBO() const;
        void bindEBO() const;
        void unBindVAO();
        void unBindVBO();
        void unBindEBO();
        
        void putData() const;
        void setAnalysis();

        void deleteVAO() const;
        void deleteVBO() const;
        void deleteEBO() const;
    private:
        Shader shader{};
        unsigned int vaoId = 0, vboId = 0, eboId = 0;

        int vertexSize = 0;
        int indicesSize = 0;
        float *vertex = nullptr;
        unsigned int *indices = nullptr;
    };
}

#endif //GL_H
