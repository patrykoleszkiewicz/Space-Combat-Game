#include "Vector2d.hpp"

#include <cmath>

Vector2d::Vector2d()
{
	x = 0.0;
	y = 0.0;
}

Vector2d::Vector2d(double X, double Y)
:x(Y), y(Y)
{
	
}

Vector2d::Vector2d(Vector2d &V)
{
	x = V.x;
	y = V.y;
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

const Vector2d Vector2d::operator+(Vector2d const &V)
{
	Vector2d result;
	result.x = x + V.x;
	result.y = y + V.y;
	return result;
}

const Vector2d Vector2d::operator-(Vector2d const &V)
{
	Vector2d result;
	result.x = x - V.x;
	result.y = y - V.y;
	return result;
}

const Vector2d Vector2d::operator*(double number)
{
	Vector2d result;
	result.x = x * number;
	result.y = y * number;
	return result;
}

const Vector2d Vector2d::operator/(double number)
{
	Vector2d result;
	result.x = x / number;
	result.y = y / number;
	return result;
}