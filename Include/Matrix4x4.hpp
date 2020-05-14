#pragma once

#include "Vector3d.hpp"

class Matrix4x4
{
public:
    Matrix4x4();
    
    Vector3d multiplyByVector(const Vector3d &V) const;
    Matrix4x4 multiplyByMatrix(const Matrix4x4 &M) const;
    
    double mat[4][4];
};