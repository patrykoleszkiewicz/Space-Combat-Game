#include "Spaceship.cpp"

#include <SFML/Graphics.hpp>

void Spaceship::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	
}

void Spaceship::setTexture(Texture& texture)
{
	_texture = &texture;
}