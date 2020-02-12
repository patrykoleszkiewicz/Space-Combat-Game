#include "Spaceship.hpp"

#include <SFML/Graphics.hpp>

Spaceship::Spaceship()
{
	_texture = nullptr;
}

void Spaceship::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Vector2f textureSize(_texture->getSize());
	
	sf::Vector2f topLeft(-textureSize.x / 2.0, -textureSize.y / 2.0);
	sf::Vector2f topRight(textureSize.x / 2.0, -textureSize.y / 2.0);
	sf::Vector2f bottomLeft(-textureSize.x / 2.0, textureSize.y / 2.0);
	sf::Vector2f bottomRight(textureSize.x / 2.0, textureSize.y / 2.0);
	
	sf::VertexArray drawable(sf::TriangleStrip);
	drawable.append(sf::Vertex(topLeft, sf::Vector2f(0.0f, 0.0f)));
	drawable.append(sf::Vertex(topRight, sf::Vector2f(textureSize.x, 0.0f)));
	drawable.append(sf::Vertex(bottomLeft, sf::Vector2f(0.0f, textureSize.y)));
	drawable.append(sf::Vertex(bottomRight, sf::Vector2f(textureSize.x, textureSize.y)));
	
	sf::Transform transform;
	transform.translate(_position.x, _position.y);
	transform.rotate(_rotation);
	
	states.texture = _texture;
	states.transform = transform;
	target.draw(drawable, states);
	
	Controlable::draw(target, sf::RenderStates());
}

void Spaceship::setTexture(Texture* texture)
{
	_texture = texture;
}