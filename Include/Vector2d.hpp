#pragma once

#include <SFML/Graphics.hpp>

class Vector2d
{
public:
	double x, y;
	
	Vector2d();
	Vector2d(double X, double Y);
	Vector2d(const Vector2d& V);
	Vector2d(sf::Vector2f V);
	Vector2d(sf::Vector2i V);
	Vector2d(sf::Vector2u V);
	
	double length() const;
	Vector2d unit() const;
	Vector2d rotate(double angle) const;
	
	sf::Vector2f sfVector2f() const;
	
	static Vector2d rotate(const Vector2d& V, double angle);
};

Vector2d operator-(const Vector2d& right);

Vector2d& operator+=(Vector2d& left, const Vector2d& right);

Vector2d& operator-=(Vector2d& left, const Vector2d& right);

Vector2d operator+(const Vector2d& left, const Vector2d& right);

Vector2d operator-(const Vector2d& left, const Vector2d& right);

Vector2d operator*(const Vector2d& left, double right);

Vector2d operator*(double left, const Vector2d& right);

Vector2d& operator*=(Vector2d& left, double right);

Vector2d operator/(const Vector2d& left, double right);

Vector2d& operator/=(Vector2d& left, double right);

bool operator==(const Vector2d& left, const Vector2d& right);

bool operator!=(const Vector2d& left, const Vector2d& right);

#include "Vector2d.inl"