#include "Physical.hpp"

Physical::Physical()
{
	_rotation = Vector3d();
	_position = Vector3d();
	_velocity = Vector3d();
	_angleVelocity = Vector3d();
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

void Physical::setPosition(double X, double Y, double Z)
{
	_position.x = X;
	_position.y = Y;
	_position.z = Z;
}

void Physical::setPosition(const Vector3d &V)
{
	_position = V;
}

Vector3d Physical::getPosition() const
{
	return _position;
}

void Physical::setRotation(double X, double Y, double Z)
{
	_rotation.x = X;
	_rotation.y = Y;
	_rotation.z = Z;
}

void Physical::setRotation(const Vector3d &V)
{
	_rotation = V;
}

Vector3d Physical::getRotation() const
{
	return _rotation;
}

void Physical::setVelocity(double X, double Y, double Z)
{
	_velocity.x = X;
	_velocity.y = Y;
	_velocity.z = Z;
}

void Physical::setVelocity(const Vector3d &V)
{
	_velocity = V;
}

Vector3d Physical::getVelocity() const
{
	return _velocity;
}