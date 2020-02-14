#pragma once

#include <SFML/Graphics.hpp>

class Texture :public sf::Texture
{
public:
	Texture();
	Texture(std::string name);
	
	std::string getName() const;
private:
	std::string _name;
};