#include "Texture.hpp"

Texture::Texture()
{
	
}

Texture::Texture(std::string name)
:_name(name)
{
	
}

std::string Texture::getName() const
{
	return _name;
}