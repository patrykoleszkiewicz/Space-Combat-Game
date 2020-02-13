#pragma once

#include "Vector2d.hpp"

#include <SFML/Graphics.hpp>

class Bullet :public sf::Drawable
{
public:
	void tickPhysics();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	void setLifetime(int life);
	
	int getLifetimeLeft();
	
	void setPosition(double X, double Y);
	void setPosition(Vector2d &V);
	
	Vector2d getPosition();
	
	void setRotation(double rot);
	
	double getRotation();
	
	void setVelocity(double X, double Y);
	void setVelocity(Vector2d &V);
	
	Vector2d getVelocity();
	
	void setSize(double X, double Y);
	void setSize(Vector2d &V);
	
	Vector2d getSize();
private:
	Vector2d _position;
	Vector2d _velocity;
	double _rotation;
	
	int _lifetime;
	Vector2d _size;
};