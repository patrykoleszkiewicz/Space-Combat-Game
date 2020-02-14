#pragma once

#include "Texture.hpp"
#include "Vector2d.hpp"

class Physical
{
public:
	Physical();
	
	void tickPhysics();
	
	void setTexture(Texture* texture);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	void setPosition(double X, double Y);
	void setPosition(const Vector2d &V);
	Vector2d getPosition() const;
	
	void setRotation(double rot);
	double getRotation() const;
	
	void setVelocity(double X, double Y);
	void setVelocity(const Vector2d &V);
	Vector2d getVelocity() const;
	
protected:
	Texture* _texture;
	
	Vector2d _position;
	Vector2d _velocity;
	
	double _rotation;
	double _angleVelocity;
};