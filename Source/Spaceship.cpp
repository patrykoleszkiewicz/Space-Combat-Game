#include "Spaceship.hpp"

#include <SFML/Graphics.hpp>

void Spaceship::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Vector2d textureSize(_texture.getSize());
	
	Vector2d topLeft(-textureSize.x / 2.0, -textureSize.y / 2.0);
	Vector2d topRight(textureSize.x / 2.0, -textureSize.y / 2.0);
	Vector2d bottomLeft(-textureSize.x / 2.0, textureSize.y / 2.0);
	Vector2d bottomRight(textureSize.x / 2.0, textureSize.y / 2.0);
	
	sf::VertexArray drawable(sf::TriangleStrip);
	drawable.append(sf::Vertex(sf::Vector2f(0.0f,0.0f), sf::Vector2f(0.0f,0.0f)));
	drawable.append(sf::Vertex(sf::Vector2f(141.0f,0.0f), sf::Vector2f(141.0f,0.0f)));
	drawable.append(sf::Vertex(sf::Vector2f(0.0f,158.0f), sf::Vector2f(0.0f,158.0f)));
	drawable.append(sf::Vertex(sf::Vector2f(141.0f,158.0f), sf::Vector2f(141.0f,158.0f)));
	
	states.texture = &_texture;
	target.draw(drawable, states);
}

void Spaceship::setTexture(Texture& texture)
{
	_texture = texture;
}