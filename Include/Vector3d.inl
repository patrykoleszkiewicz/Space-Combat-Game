#pragma once

#define DBL_EPSILON 2.2204460492503131e-16

inline Vector3d operator-(const Vector3d& right)
{
    return Vector3d(-right.x, -right.y, -right.z);
}

inline Vector3d& operator+=(Vector3d& left, const Vector3d& right)
{
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;
    
    return left;
}

inline Vector3d& operator-=(Vector3d& left, const Vector3d& right)
{
    left.x -= right.x;
    left.y -= right.y;
    left.z -= right.z;
    
    return left;
}

inline Vector3d operator+(const Vector3d& left, const Vector3d& right)
{
    return Vector3d(left.x + right.x, left.y + right.y, left.z + right.z);
}

inline Vector3d operator-(const Vector3d& left, const Vector3d& right)
{
    return Vector3d(left.x - right.x, left.y - right.y, left.z - right.z);
}

inline Vector3d operator*(const Vector3d& left, double right)
{
    return Vector3d(left.x * right, left.y * right, left.z * right);
}

inline Vector3d operator*(double left, const Vector3d& right)
{
    return Vector3d(left * right.x, left * right.y, left * right.z);
}

inline Vector3d& operator*=(Vector3d& left, double right)
{
    left.x *= right;
    left.y *= right;
    left.z *= right;
    
    return left;
}

inline Vector3d operator/(const Vector3d& left, double right)
{
    return Vector3d(left.x / right, left.y / right, left.z / right);
}

inline Vector3d& operator/=(Vector3d& left, double right)
{
    left.x /= right;
    left.y /= right;
    left.z /= right;
    
    return left;
}

inline bool operator==(const Vector3d& left, const Vector3d& right)
{
    return abs(left.x - right.x) < DBL_EPSILON && abs(left.y - right.y) < DBL_EPSILON && abs(left.z - right.z) < DBL_EPSILON;
}

inline bool operator!=(const Vector3d& left, const Vector3d& right)
{
    return !(left == right);
}