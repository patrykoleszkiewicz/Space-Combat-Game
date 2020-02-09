#pragma once

#include <SFML/Graphics.hpp>

class Texture :public sf::Texture
{
public:
	Texture();
	Texture(std::string name);
	
	std::string getName();
private:
	const std::string _name;
};