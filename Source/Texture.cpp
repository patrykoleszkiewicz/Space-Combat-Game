#include "Texture.hpp"

Texture::Texture()
{
	
}

Texture::Texture(std::string name)
:_name(name)
{
	
}

const std::string Texture::getName()
{
	return _name;
}