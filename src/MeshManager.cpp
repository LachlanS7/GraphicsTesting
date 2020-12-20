#include "MeshManager.h"
#include <glm/gtc/type_ptr.hpp>

MeshManager::MeshManager() = default;

const float *MeshManager::getViewMatrixPtr() {
    return glm::value_ptr(*m_viewMatrix);
}

void MeshManager::updateShaderProgram(ShaderProgram *shaderProgram) {
    m_shaderProgram = shaderProgram;
}

ShaderProgram *MeshManager::getShaderProgram() {
    return m_shaderProgram;
}

void MeshManager::addMesh(Mesh *mesh) {
    m_meshes.push_back(mesh);
}

Mesh * MeshManager::getMesh(unsigned int position) {
    return m_meshes[position];
}

glm::mat4 *MeshManager::getViewMatrix() {
    return m_viewMatrix;
}

unsigned int MeshManager::meshCount() {
    return m_meshes.size();
}

Mesh *MeshManager::operator[](unsigned int index) {
    return m_meshes[index];
}

std::vector<Mesh *>::iterator MeshManager::begin() {
    return m_meshes.begin();
}

std::vector<Mesh *>::iterator MeshManager::end() {
    return m_meshes.end();
}