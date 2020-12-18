#include <iostream>
#include <cmath>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Display.h"

int main() {

    std::string a = "Hello Classes";
    Display window(800, 800, a);

    window.registerKey(GLFW_KEY_ESCAPE);

    window.setClearColour(1.0, 0.7, 0.0, 1.0);

    // ------------------------- Shaders ---------------------------

    auto *shaderProgram = new ShaderProgram;
    shaderProgram->fromFile("../assets/default.vert", "../assets/default.frag");

    // -------------------------- Buffers --------------------------

    MeshManager meshManager;

    Vertex v1(-0.5, -0.5, 1, 1, 0, 0, 1);
    Vertex v2( 0.5, -0.5, 1, 1, 0, 0, 1);
    Vertex v3( 0.0,  0.5, 1, 1, 0, 0, 1);

    std::vector<Vertex> v = {v1, v2, v3};
    std::vector<unsigned int> i = {0, 1, 2};

    Mesh *m1 = new Mesh(&v, &i, true);
    meshManager.addMesh(m1);

    meshManager.updateShaderProgram(shaderProgram);





    // ----------------------- Linear Algebra! --------------------

    //glm::mat4 view = glm::mat4(1.0);
    //meshManager.updateView(view);
    //view = glm::perspective(glm::radians(45.0f), (float)(window.getWidth()) / (float)(window.getHeight()), 0.1f, 100.0f);

    // ------------------------- Draw Loop -------------------------

    while (!window.shouldClose()) {
        window.update(meshManager);
        if (window.checkKey(GLFW_KEY_ESCAPE)==KeyState::down) {
            window.setShouldClose(true);
        }

    }

    glfwTerminate();

    return 0;
}