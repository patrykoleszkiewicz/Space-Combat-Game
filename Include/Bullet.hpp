#pragma once

#include "Vector2d.hpp"

#include <SFML/Graphics.hpp>

class Bullet :public sf::Drawable
{
public:
	void tickPhysics();
	
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	void setLifetime(int life);
	int getLifetimeLeft() const;
	
	void setPosition(double X, double Y);
	void setPosition(const Vector2d &V);
	Vector2d getPosition() const;
	
	void setRotation(double rot);
	double getRotation() const;
	
	void setVelocity(double X, double Y);
	void setVelocity(const Vector2d &V);
	Vector2d getVelocity() const;
	
	void setSize(double X, double Y);
	void setSize(const Vector2d &V);
	Vector2d getSize() const;
	
private:
	Vector2d _position;
	Vector2d _velocity;
	double _rotation;
	
	int _lifetime;
	Vector2d _size;
};