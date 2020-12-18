#pragma once

#include <vector>
#include "Vertex.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Mesh {
public:
    Mesh();
    Mesh(const std::vector<Vertex> *vertices, const std::vector<unsigned int> *indices, bool active);
    Mesh(const Vertex *vertices, const unsigned int *indices, unsigned int verticesSize, unsigned int indicesSize, bool active);

    const float *getModelMatrix() const;
    void setActive(bool isActive);
    bool isActive() const;
    unsigned int getVAO() const;
    unsigned int vertexCount() const;

private:

    void fillBuffers(const Vertex *vertices, const unsigned int *indices, unsigned int verticesSize, unsigned int indicesSize);
    void genBuffers();

    std::vector<double> m_vertices;
    std::vector<double> m_indices;
    glm::mat4 m_modelMatrix = glm::mat4(1.0f);
    bool m_active = true;

    unsigned int m_VBO = 0;
    unsigned int m_EBO = 0;
    unsigned int m_VAO = 0;

};