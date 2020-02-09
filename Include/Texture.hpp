#pragma once

#include <SFML/Graphics.hpp>

class Texture :public sf::Texture
{
public:
	Texture();
	Texture(std::string name);
	
	const std::string getName();
private:
	std::string _name;
};