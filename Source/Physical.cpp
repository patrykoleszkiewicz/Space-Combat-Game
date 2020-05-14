#include "Physical.hpp"

Physical::Physical()
{
	_rotation = 0.0;
	_position = Vector2d();
	_velocity = Vector2d();
	_angleVelocity = 0.0;
	_texture = nullptr;
}

void Physical::setTexture(Texture* texture)
{
	_texture = texture;
}

void Physical::tickPhysics()
{
	_position += _velocity;
	_rotation += _angleVelocity;
}

void Physical::setPosition(double X, double Y)
{
	_position.x = X;
	_position.y = Y;
}

void Physical::setPosition(const Vector2d &V)
{
	_position = V;
}

Vector2d Physical::getPosition() const
{
	return _position;
}

void Physical::setRotation(double rot)
{
	_rotation = rot;
}

double Physical::getRotation() const
{
	return _rotation;
}

void Physical::setVelocity(double X, double Y)
{
	_velocity.x = X;
	_velocity.y = Y;
}

void Physical::setVelocity(const Vector2d &V)
{
	_velocity = V;
}

Vector2d Physical::getVelocity() const
{
	return _velocity;
}