#pragma once

#include "Texture.hpp"
#include "Controlable.hpp"

#include <SFML/Graphics.hpp>

class Spaceship :public Controlable
{
public:
	void setTexture(Texture* texture);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	Spaceship();
private:
	Texture* _texture;
};