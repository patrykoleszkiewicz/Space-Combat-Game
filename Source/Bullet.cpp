#include "Bullet.hpp"

void Bullet::setLifetime(int life)
{
	_lifetime = life;
}
	
int Bullet::getLifetimeLeft() const
{
	return _lifetime;
}
	
void Bullet::tickPhysics()
{
	_position += _velocity;
	--_lifetime;
}

void Bullet::setPosition(double X, double Y)
{
	_position.x = X;
	_position.y = Y;
}

void Bullet::setPosition(const Vector2d &V)
{
	_position = V;
}

Vector2d Bullet::getPosition() const
{
	return _position;
}

void Bullet::setRotation(double rot)
{
	_rotation = rot;
}

double Bullet::getRotation() const
{
	return _rotation;
}

void Bullet::setVelocity(double X, double Y)
{
	_velocity.x = X;
	_velocity.y = Y;
}

void Bullet::setVelocity(const Vector2d &V)
{
	_velocity = V;
}

Vector2d Bullet::getVelocity() const
{
	return _velocity;
}

void Bullet::setSize(double X, double Y)
{
	_size.x = X;
	_size.y = Y;
}

void Bullet::setSize(const Vector2d &V)
{
	_size = V;
}

Vector2d Bullet::getSize() const
{
	return _size;
}