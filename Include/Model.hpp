#pragma once

struct Triangle
{
    Vector3d point1, point2, point3;
}

class Model
{
public:
    std::vector<Triangle> _triangles;
}