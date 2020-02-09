#pragma once

#include <SFML/Graphics.hpp>

class Vector2d
{
public:
	double x, y;
	
	Vector2d();
	Vector2d(double X, double Y);
	Vector2d(Vector2d &V);
	
	
};