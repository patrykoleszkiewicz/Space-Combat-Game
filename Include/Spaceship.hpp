#pragma once

#include "Texture.hpp"
#include "Vector2d.hpp"

class Spaceship :public sf::Drawable
{
public:
	void setTexture(Texture& texture);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	Texture _texture;
	Vector2d _position;
	double _rotation;
};