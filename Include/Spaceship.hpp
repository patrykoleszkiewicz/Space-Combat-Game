#pragma once

#include "Texture.hpp"
#include "Vector2d.hpp"

class Spaceship :public sf::Drawable
{
public:
	void setTexture(Texture& texture);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	void setPosition(double X, double Y);
	void setPosition(Vector2d &V);
	
	Vector2d getPosition();
	
	void setRotation(double rot);
	
	double getRotation();
private:
	Texture _texture;
	Vector2d _position;
	double _rotation;
};