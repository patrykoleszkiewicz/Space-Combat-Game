#include "Vector3d.hpp"

#include <cmath>

Vector3d::Vector3d()
{
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

Vector3d::Vector3d(double X, double Y, double Z)
:x(X), y(Y), z(Z)
{
    
}

Vector3d::Vector3d(const Vector3d& V)
{
    x = V.x;
    y = V.y;
    z = V.z;
}

Vector3d::Vector3d(sf::Vector3f V)
{
    x = (double)V.x;
    y = (double)V.y;
    z = (double)V.z;
}

Vector3d::Vector3d(sf::Vector3i V)
{
    x = (double)V.x;
    y = (double)V.y;
    z = (double)V.z;
}

Vector3d::Vector3d(double X, double Y)
:x(X), y(Y), z(0.0)
{
    
}

Vector3d::Vector3d(const Vector2d& V)
{
    x = V.x;
    y = V.y;
    z = 0.0;
}

Vector3d::Vector3d(sf::Vector2f V)
{
    x = (double)V.x;
    y = (double)V.y;
    z = 0.0;
}

Vector3d::Vector3d(sf::Vector2i V)
{
    x = (double)V.x;
    y = (double)V.y;
    z = 0.0;
}

Vector3d::Vector3d(sf::Vector2u V)
{
    x = (double)V.x;
    y = (double)V.y;
    z = 0.0;
}

double Vector3d::length() const
{
    return sqrt(x*x + y*y + z*z);
}

Vector3d Vector3d::unit() const
{
    double len = length();
    Vector3d result;
    result.x = x / len;
    result.y = y / len;
    result.z = z / len;
    return result;
}

Vector3d Vector3d::cross(const Vector3d &V) const
{
    Vector3d result;
    result.x = y * V.z - z * V.y;
    result.y = z * V.x - x * V.z;
    result.z = x * V.y - y * V.x;
    return result;
}

sf::Vector3f Vector3d::sfVector3f() const
{
    sf::Vector3f V;
    V.x = (float)x;
    V.y = (float)y;
    V.z = (float)z;
    return V;
}

sf::Vector2f Vector3d::sfVector2f() const
{
    sf::Vector2f V;
    V.x = (float)x;
    V.y = (float)y;
    return V;
}