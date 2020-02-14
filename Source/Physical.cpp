#include "Physical.hpp"

Physical::Physical()
{
	_mass = 1.0;
	_rotation = 0.0;
	_position = Vector2d();
	_velocity = Vector2d();
	_angleVelocity = 0.0;
	_texture = nullptr;
}

void Physical::draw(sf::RenderTarget& target, sf::RenderStates states) const
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
}

void Physical::setTexture(Texture* texture)
{
	_texture = texture;
}

void Physical::tickPhysics()
{
	_position += _velocity;
	_rotation += _angleVelocity;
}

void Physical::setPosition(double X, double Y)
{
	_position.x = X;
	_position.y = Y;
}

void Physical::setPosition(const Vector2d &V)
{
	_position = V;
}

Vector2d Physical::getPosition() const
{
	return _position;
}

void Physical::setRotation(double rot)
{
	_rotation = rot;
}

double Physical::getRotation() const
{
	return _rotation;
}

void Physical::setVelocity(double X, double Y)
{
	_velocity.x = X;
	_velocity.y = Y;
}

void Physical::setVelocity(const Vector2d &V)
{
	_velocity = V;
}

Vector2d Physical::getVelocity() const
{
	return _velocity;
}

void Physical::setMass(double mass)
{
	_mass = mass;
}

double Physical::getMass() const
{
	return _mass;
}