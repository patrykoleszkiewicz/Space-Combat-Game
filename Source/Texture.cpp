#include "Texture.hpp"

Texture::Texture(std::string name)
{
	_name = name;
}

void Texture::setName(std::string name)
{
	_name = name;
}

std::string Texture::getName()
{
	return _name;
}