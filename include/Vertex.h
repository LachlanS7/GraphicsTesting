#pragma once
#include <glm/glm.hpp>

struct Vertex {

public:

    double x;
    double y;
    double z;
    double r;
    double g;
    double b;
    double a;

    Vertex(double x, double y, double z, double r, double g, double b, double a);
    Vertex(glm::vec3 position, glm::vec4 colour);
};