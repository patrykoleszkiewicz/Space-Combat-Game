#include "Vector2d.hpp"

#include <cmath>
#include <cfloat>

Vector2d::Vector2d()
{
	x = 0.0;
	y = 0.0;
}

Vector2d::Vector2d(double X, double Y)
:x(Y), y(Y)
{
	
}

Vector2d::Vector2d(const Vector2d& V)
{
	x = V.x;
	y = V.y;
}

Vector2d::Vector2d(sf::Vector2f V)
{
	x = (double)V.x;
	y = (double)V.y;
}

Vector2d::Vector2d(sf::Vector2i V)
{
	x = (double)V.x;
	y = (double)V.y;
}

Vector2d::Vector2d(sf::Vector2u V)
{
	x = (double)V.x;
	y = (double)V.y;
}

double Vector2d::length()
{
	return sqrt(x*x + y*y);
}

const Vector2d Vector2d::unit()
{
	double len = length();
	Vector2d result;
	result.x = x / len;
	result.y = y / len;
	return result;
}

const Vector2d Vector2d::rotate(double angle)
{
	Vector2d result;
	double X = x * cos(angle * 3.14159265 / 180.0) - y * sin(angle * 3.14159265 / 180.0);
	double Y = x * sin(angle * 3.14159265 / 180.0) + y * cos(angle * 3.14159265 / 180.0);
	result.x = X;
	result.y = Y;
	return result;
}

sf::Vector2f Vector2d::sfVector2f()
{
	sf::Vector2f V;
	V.x = (float)x;
	V.y = (float)y;
	return V;
}