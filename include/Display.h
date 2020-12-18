#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <unordered_map>

#include "ShaderProgram.h"
#include "MeshManager.h"

enum KeyState {
    release,
    down,
    null
};

class Display {
public:
    Display(int width, int height, std::string &name);
    //~Display();

    void makeContext() const;
    void update(MeshManager &meshManager);
    void setClearColour(float R, float G, float B, float A) const;
    void setShouldClose(bool shouldClose);
    bool shouldClose();

    int getWidth() const;
    int getHeight() const;

    void registerKey(int key);
    void removeKey(int key);
    KeyState checkKey(int key) const;

private:
    GLFWwindow *m_window;
    int m_width{}, m_height{};
    std::unordered_map<int, KeyState> m_keyMap;

    void draw(MeshManager &meshManager) const;
    void processInput(GLFWwindow *window);
    void frameBuffersizeCallback(GLFWwindow *window, int width, int height);
};

