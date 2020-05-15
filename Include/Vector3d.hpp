#pragma once
#include "Vector2d.hpp"

#include <SFML/Graphics.hpp>

class Vector3d
{
public:
    double x, y, z;
    
    Vector3d();
    Vector3d(double X, double Y, double Z);
    Vector3d(double X, double Y);
    
    Vector3d(const Vector3d& V);
    Vector3d(sf::Vector3f V);
    Vector3d(sf::Vector3i V);
    
    Vector3d(const Vector2d& V);
    Vector3d(sf::Vector2f V);
    Vector3d(sf::Vector2i V);
    Vector3d(sf::Vector2u V);
    
    double length() const;
    Vector3d unit() const;
    Vector3d cross(const Vector3d &V) const;
    double dot(const Vector3d &V) const;
    
    sf::Vector3f sfVector3f() const;
    sf::Vector2f sfVector2f() const;
};

Vector3d operator-(const Vector3d& right);

Vector3d& operator+=(Vector3d& left, const Vector3d& right);

Vector3d& operator-=(Vector3d& left, const Vector3d& right);

Vector3d operator+(const Vector3d& left, const Vector3d& right);

Vector3d operator-(const Vector3d& left, const Vector3d& right);

Vector3d operator*(const Vector3d& left, double right);

Vector3d operator*(double left, const Vector3d& right);

Vector3d& operator*=(Vector3d& left, double right);

Vector3d operator/(const Vector3d& left, double right);

Vector3d& operator/=(Vector3d& left, double right);

bool operator==(const Vector3d& left, const Vector3d& right);

bool operator!=(const Vector3d& left, const Vector3d& right);

#include "Vector3d.inl"