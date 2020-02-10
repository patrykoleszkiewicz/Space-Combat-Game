#pragma once

#include "Texture.hpp"
#include "Vector2d.hpp"

class Spaceship :public Drawable
{
public:
	void setTexture(Texture &texture);
	draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	Texture* _texture;
	Vector2d _position;
	double _rotation;
};