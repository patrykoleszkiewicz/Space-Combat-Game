#pragma once

#include "Vector3d.hpp"
#include "Texture.hpp"

struct Triangle
{
    Vector3d point1, point2, point3;
};

class Model
{
    Model(Texture& texture);
public:
    std::vector<Triangle> _triangles;
    Texture& _texture;
};