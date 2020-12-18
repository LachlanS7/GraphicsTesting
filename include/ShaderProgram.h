#pragma once

#include <iostream>

class ShaderProgram {

public:
    ShaderProgram();
    void fromFile(const std::string &vertexShaderAddress, const std::string &fragmentShaderAddress);
    void fromString(const std::string &vertexShaderSource, const std::string &fragmentShaderSource);
    //~ShaderProgram();
    void use() const;
    unsigned int id() const;

private:
    unsigned int m_shaderProgramID = 0;
    void makeProgram(const char* vertexShaderSource, const char* fragmentShaderSource);

};