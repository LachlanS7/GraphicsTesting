#include "Display.h"

Display::Display(int width, int height, std::string &name) {

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SAMPLES, 8);

    m_window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);

    if (m_window == nullptr) {
        printf("ERROR: Could not make window!");
        glfwTerminate();
    }

    glfwMakeContextCurrent(m_window);

    glfwSwapInterval(1);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "ERROR: Failed to initialize GLAD" << std::endl;
    }

    glViewport(0, 0, width, height);
}

void Display::draw(MeshManager &meshManager) const {
/*
    auto sp = meshManager.getShaderProgram();
    sp->use();

    unsigned int viewLoc = glGetUniformLocation(sp->id(), "view");
    unsigned int modelLoc = glGetUniformLocation(sp->id(), "model");

    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, meshManager.getViewMatrixPtr());

    for (int i = 0; i < meshManager.meshCount(); i++) {
        Mesh *mesh = meshManager.getMesh(i);
        if(mesh->isActive()) {
            glBindVertexArray(mesh->getVAO());
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, mesh->getModelMatrix());

            glDrawElements(GL_TRIANGLES, mesh->vertexCount(), GL_FLOAT, nullptr);
        }
    }*/
}

void Display::update(MeshManager &meshManager) {

    //glfwMakeContextCurrent(m_window);

    glClear(GL_COLOR_BUFFER_BIT);

    //draw(meshManager);

    processInput(m_window);
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

void Display::makeContext() const {
    glfwMakeContextCurrent(m_window);
}

void Display::setClearColour(float R, float G, float B, float A) const {
    glClearColor(R, G, B, A);
}

void Display::frameBuffersizeCallback(GLFWwindow *window, int width, int height) {
    m_width = width;
    m_height = height;
    glViewport(0, 0, width, height);
}

void Display::setShouldClose(bool shouldClose) {
    glfwSetWindowShouldClose(m_window, shouldClose);
}

bool Display::shouldClose() {
    return glfwWindowShouldClose(m_window);
}

void Display::registerKey(int key) {
    m_keyMap.insert({key, KeyState::release});
}

void Display::removeKey(int key) {
    m_keyMap.erase(key);
}

void Display::processInput(GLFWwindow *window) {

    for (auto it = m_keyMap.begin(); it != m_keyMap.end(); ++it) {

        int key = it->first;
        m_keyMap[key] = (KeyState)glfwGetKey(m_window, key);
    }

}

KeyState Display::checkKey(int key) const {

    auto it = m_keyMap.find(key);

    if (it == m_keyMap.end()) {
        return KeyState::null;
    }

    return it->second;
}

int Display::getHeight() const {
    return m_height;
}

int Display::getWidth() const {
    return m_width;
}