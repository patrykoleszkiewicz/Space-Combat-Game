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

sf::Vector2f Vector2d::sfVector2f()
{
	sf::Vector2f V;
	V.x = (float)x;
	V.y = (float)y;
	return V;
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

Vector2d& Vector2d::operator=(const Vector2d V)
{
	if(this != &V)
	{
		x = V.x;
		y = V.y;
	}
	return *this;
}

Vector2d& Vector2d::operator=(const sf::Vector2f &V)
{
	x = (double)V.x;
	y = (double)V.y;
	return *this;
}

Vector2d& Vector2d::operator=(const sf::Vector2u &V)
{
	x = (double)V.x;
	y = (double)V.y;
	return *this;
}

Vector2d& Vector2d::operator=(const sf::Vector2i &V)
{
	x = (double)V.x;
	y = (double)V.y;
	return *this;
}