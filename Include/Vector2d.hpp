#pragma once

#include <SFML/Graphics.hpp>

class Vector2d
{
public:
	double x, y;
	
	Vector2d();
	Vector2d(double X, double Y);
	Vector2d(Vector2d &V);
	
	double length();
	const Vector2d unit();
	
	const Vector2d operator+(Vector2d const &V);
	const Vector2d operator-(Vector2d const &V);
	const Vector2d operator*(double number);
	const Vector2d operator/(double number);
};