#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aCol;

uniform mat4 view;
uniform mat4 model;

out vec4 col;

void main()
{
    col = aCol;
    gl_Position = view * model * vec4(aPos, 1.0);
}