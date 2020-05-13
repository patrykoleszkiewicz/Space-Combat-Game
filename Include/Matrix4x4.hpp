#pragma once

#include "Vector3d.hpp"

class Matrix4x4
{
public:
    Matrix4x4();
    
    Vector3d multiply(const Vector3d &V) const;
    
    double mat[4][4];
};