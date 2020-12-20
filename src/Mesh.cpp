#include "Mesh.h"
#include <glm/gtc/type_ptr.hpp>

Mesh::Mesh() = default;

Mesh::Mesh(const std::vector<Vertex> *vertices, const std::vector<unsigned int> *indices, bool active) {
    m_active = active;
    fillBuffers(vertices->data(), indices->data(), vertices->size(), indices->size());
}

Mesh::Mesh(const Vertex *vertices, const unsigned int *indices, unsigned int verticesSize, unsigned int indicesSize, bool active) {
    m_active = active;
    fillBuffers(vertices, indices, verticesSize, indicesSize);
}

void Mesh::fillBuffers(const Vertex *vertices, const unsigned int *indices, unsigned int verticesSize,
                       unsigned int indicesSize) {

    for (int i = 0; i < verticesSize; i++) {
        m_vertices.push_back((vertices + i)->x);
        m_vertices.push_back((vertices + i)->y);
        m_vertices.push_back((vertices + i)->z);
        m_vertices.push_back((vertices + i)->r);
        m_vertices.push_back((vertices + i)->g);
        m_vertices.push_back((vertices + i)->b);
        m_vertices.push_back((vertices + i)->a);
    }

    for (int i = 0; i < indicesSize; i++) {
        m_indices.push_back(*(indices+i));
    }

    genBuffers();

}

const float *Mesh::getModelMatrix() const {
    return glm::value_ptr(m_modelMatrix);
}

void Mesh::setActive(bool isActive) {
    m_active = isActive;
}

bool Mesh::isActive() const {
    return m_active;
}

unsigned int Mesh::getVAO() const {
    return m_VAO;
}

unsigned int Mesh::vertexCount() const {
        return m_indices.size();
}

#include <iostream>


void Mesh::genBuffers() {

    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_EBO);

    glBindVertexArray(m_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);

    glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(double), m_vertices.data(), GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(double), m_indices.data(), GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 7*sizeof(double), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 4, GL_DOUBLE, GL_FALSE, 7*sizeof(double), (void*)(3 * sizeof(double)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}