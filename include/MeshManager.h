#pragma once

#include <vector>
#include <Mesh.h>
#include <ShaderProgram.h>

class MeshManager {

public:
    MeshManager();
    void updateView(glm::mat4 viewMatrix);
    const float *getViewMatrixPtr();
    ShaderProgram *getShaderProgram();
    void updateShaderProgram(ShaderProgram *shaderProgram);
    glm::mat4 &getViewMatrix();
    void addMesh(Mesh *mesh);
    Mesh *getMesh(unsigned int position);
    unsigned int meshCount();

    Mesh *operator[](unsigned int index);
    std::vector<Mesh*>::iterator begin();
    std::vector<Mesh*>::iterator end();

private:
    glm::mat4 m_viewMatrix = glm::mat4(1.0f);
    std::vector<Mesh*> m_meshes = {new Mesh};
    ShaderProgram *m_shaderProgram = new ShaderProgram();
};