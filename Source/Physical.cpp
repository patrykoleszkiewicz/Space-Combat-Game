#include "Physical.hpp"

Physical::Physical()
{
	_mass = 1.0;
	_rotation = 0.0;
	_position = Vector2d();
	_velocity = Vector2d();
	_angleVelocity = 0.0;
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

void Physical::setPosition(Vector2d &V)
{
	_position = V;
}

Vector2d Physical::getPosition()
{
	return _position;
}

void Physical::setRotation(double rot)
{
	_rotation = rot;
}

double Physical::getRotation()
{
	return _rotation;
}

void Physical::setVelocity(double X, double Y)
{
	_velocity.x = X;
	_velocity.y = Y;
}

void Physical::setVelocity(Vector2d &V)
{
	_velocity = V;
}

Vector2d Physical::getVelocity()
{
	return _velocity;
}

void Physical::setMass(double mass)
{
	_mass = mass;
}

double Physical::getMass()
{
	return _mass;
}