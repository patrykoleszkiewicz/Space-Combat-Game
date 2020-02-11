#pragma once

#define DBL_EPSILON 2.2204460492503131e-16

inline Vector2d operator-(const Vector2d& right)
{
	return Vector2d(-right.x, -right.y);
}

inline Vector2d& operator+=(Vector2d& left, const Vector2d& right)
{
	left.x += right.x;
	left.y += right.y;
	
	return left;
}

inline Vector2d& operator-=(Vector2d& left, const Vector2d& right)
{
	left.x -= right.x;
	left.y -= right.y;
	
	return left;
}

inline Vector2d operator+(const Vector2d& left, const Vector2d& right)
{
	return Vector2d(left.x + right.x, left.y + right.y);
}

inline Vector2d operator-(const Vector2d& left, const Vector2d& right)
{
	return Vector2d(left.x - right.x, left.y - right.y);
}

inline Vector2d operator*(const Vector2d& left, double right)
{
	return Vector2d(left.x * right, left.y * right);
}

inline Vector2d operator*(double left, const Vector2d& right)
{
	return Vector2d(left * right.x, left * right.y);
}

inline Vector2d& operator*=(Vector2d& left, double right)
{
	left.x *= right;
	left.y *= right;
	
	return left;
}

inline Vector2d operator/(const Vector2d& left, double right)
{
	return Vector2d(left.x / right, left.y / right);
}

inline Vector2d& operator/=(Vector2d& left, double right)
{
	left.x /= right;
	left.y /= right;
	
	return left;
}

inline bool operator==(const Vector2d& left, const Vector2d& right)
{
	return abs(left.x - right.x) < DBL_EPSILON && abs(left.y - right.y) < DBL_EPSILON;
}

inline bool operator!=(const Vector2d& left, const Vector2d& right)
{
	return !(left == right);
}