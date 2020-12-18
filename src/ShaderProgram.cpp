#include "ShaderProgram.h"
#include "Utilities.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

ShaderProgram::ShaderProgram() = default;

void ShaderProgram::fromFile(const std::string &vertexShaderAddress, const std::string &fragmentShaderAddress) {

    auto vertexShaderSource = Utilities::loadFile(vertexShaderAddress);
    auto fragmentShaderSource = Utilities::loadFile(fragmentShaderAddress);

    makeProgram(vertexShaderSource.c_str(), fragmentShaderSource.c_str());
}

void ShaderProgram::fromString(const std::string &vertexShaderSource, const std::string &fragmentShaderSource) {
    makeProgram(vertexShaderSource.c_str(), fragmentShaderSource.c_str());
}

void ShaderProgram::makeProgram(const char* vertexShaderSource, const char* fragmentShaderSource) {

    int  success;
    char infoLog[512];

    unsigned int vertexShader = 0;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        return;
    }

    unsigned int fragmentShader = 0;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        return;
    }

    m_shaderProgramID = glCreateProgram();
    glAttachShader(m_shaderProgramID, vertexShader);
    glAttachShader(m_shaderProgramID, fragmentShader);
    glLinkProgram(m_shaderProgramID);

    glGetProgramiv(m_shaderProgramID, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(m_shaderProgramID, 512, nullptr, infoLog);
        std::cout << "ERROR::PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
        return;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void ShaderProgram::use() const {
    glUseProgram(m_shaderProgramID);
}

unsigned int ShaderProgram::id() const {
    return m_shaderProgramID;
}