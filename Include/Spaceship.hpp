#pragma once

#include "Texture.hpp"
#include "Vector2d.hpp"
#include "Physical.hpp"

#include <SFML/Graphics.hpp>

class Spaceship :public Physical, public sf::Drawable
{
public:
	void setTexture(Texture& texture);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	Spaceship();
private:
	Texture _texture;
};