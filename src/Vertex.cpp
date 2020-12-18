#include "Vertex.h"

Vertex::Vertex(double x, double y, double z, double r, double g, double b, double a) :
    x(x), y(y), z(z), r(r), g(g), b(b), a(a){ }

Vertex::Vertex(glm::vec3 position, glm::vec4 colour) :
    x(position.x), y(position.y), z(position.z), r(colour.r), g(colour.g), b(colour.b), a(colour.a) { }