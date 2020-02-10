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
	
	double length();
	const Vector2d unit();
	
	sf::Vector2f sfVector2f();
	
	const Vector2d operator+(Vector2d const &V);
	const Vector2d operator-(Vector2d const &V);
	const Vector2d operator*(double number);
	const Vector2d operator/(double number);
	Vector2d& operator=(const Vector2d V);
	Vector2d& operator=(const sf::Vector2f &V);
	Vector2d& operator=(const sf::Vector2u &V);
	Vector2d& operator=(const sf::Vector2i &V);
};