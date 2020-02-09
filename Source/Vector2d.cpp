#include "Vector2d.hpp"

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