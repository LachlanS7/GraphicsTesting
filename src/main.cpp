#include <iostream>
#include <cmath>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Display.h"

#define PI 3.14159265359

void drawPolygon(float centreX, float centreY, float radius, int numberOfEdges, float *dataBuffer, int *indexBuffer) {
    *(dataBuffer    ) = centreX;
    *(dataBuffer + 1) = centreY;
    *(dataBuffer + 2) = 0.0;

    //Colour
    *(dataBuffer + 3) = 1.0;
    *(dataBuffer + 4) = 1.0;
    *(dataBuffer + 5) = 1.0;

    dataBuffer+=6;

    float deltaAngle = 2 * PI / numberOfEdges;
    float currentAngle = 0;

    for (int i = 0; i < numberOfEdges; i++) {
        //Positions
        *(dataBuffer+6*i  ) = radius * std::cos(currentAngle) + centreX;
        *(dataBuffer+6*i+1) = radius * std::sin(currentAngle) + centreY;
        *(dataBuffer+6*i+2) = 0.0;

        //Colour
        *(dataBuffer+6*i+3) = std::cos(currentAngle);
        *(dataBuffer+6*i+4) = std::sin(currentAngle);
        *(dataBuffer+6*i+5) = 0;

        //Indexing
        *(indexBuffer+3*i  ) = 0;
        *(indexBuffer+3*i+1) = i+1;
        *(indexBuffer+3*i+2) = (i+2)%(numberOfEdges+1);

        currentAngle+=deltaAngle;
    }

    *(indexBuffer+3*numberOfEdges-1) = 1;

}

int main() {

    std::string a = "Hello Classes";
    Display window(800, 800, a);

    window.setClearColour(1.0, 0.7, 0.0, 1.0);

    window.registerKey(GLFW_KEY_ESCAPE);
    window.registerKey(GLFW_KEY_A);
    window.registerKey(GLFW_KEY_S);

    // ------------------------- Shaders ---------------------------

    auto *shaderProgram = new ShaderProgram;
    shaderProgram->fromFile("../assets/default.vert", "../assets/default.frag");

    // -------------------------- Buffers --------------------------


    /*float vertices[6000] = {0};

    int indices[6000] = {0};

    drawPolygon(0.0, 0.0, 0.8, 100, vertices, indices);
*/

    MeshManager meshManager;

    Vertex v1(-0.5, -0.5, 0.0, 1, 0, 0, 1);
    Vertex v2( 0.5, -0.5, 0.0, 1, 0, 0, 1);
    Vertex v3( 0.0,  0.5, 0.0, 1, 0, 0, 1);


    std::vector<Vertex> v = {v1, v2, v3};
    std::vector<unsigned int> i = {0, 1, 2};
    Mesh *m1 = new Mesh(&v, &i, true);

    meshManager.addMesh(m1);

    meshManager.updateShaderProgram(shaderProgram);




    // ----------------------- Linear Algebra! --------------------

    glm::mat4 view = glm::mat4(1.0);
    meshManager.updateView(view);
    //view = glm::perspective(glm::radians(45.0f), (float)(window.getWidth()) / (float)(window.getHeight()), 0.1f, 100.0f);

    // ------------------------- Draw Loop -------------------------

    while (!window.shouldClose()) {
        window.update(meshManager);

        if(window.checkKey(GLFW_KEY_ESCAPE) == KeyState::down) {
            window.setShouldClose(true);
        }

    }

    glfwTerminate();

    return 0;
}