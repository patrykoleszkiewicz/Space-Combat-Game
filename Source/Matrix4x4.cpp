#include "Matrix4x4.hpp"

Matrix4x4::Matrix4x4()
{
    mat[0][0] = 0.0;
    mat[0][1] = 0.0;
    mat[0][2] = 0.0;
    mat[0][3] = 0.0;
    
    mat[1][0] = 0.0;
    mat[1][1] = 0.0;
    mat[1][2] = 0.0;
    mat[1][3] = 0.0;
    
    mat[2][0] = 0.0;
    mat[2][1] = 0.0;
    mat[2][2] = 0.0;
    mat[2][3] = 0.0;
    
    mat[3][0] = 0.0;
    mat[3][1] = 0.0;
    mat[3][2] = 0.0;
    mat[3][3] = 0.0;
}

Vector3d Matrix4x4::multiply(const Vector3d &V) const
{
    Vector3d output;
    output.x = V.x * mat[0][0] + V.y * mat[1][0] + V.z * mat[2][0] + mat[3][0];
    output.y = V.x * mat[0][1] + V.y * mat[1][1] + V.z * mat[2][1] + mat[3][1];
    output.z = V.x * mat[0][2] + V.y * mat[1][2] + V.z * mat[2][2] + mat[3][2];
    double w = V.x * mat[0][3] + V.y * mat[1][3] + V.z * mat[2][3] + mat[3][3];
    
    if(w != 0.0)
    {
        output /= w;
    }
    
    return output;
}