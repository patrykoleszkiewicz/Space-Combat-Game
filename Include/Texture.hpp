#pragma once

#include <SFML/Graphics.hpp>

class Texture :public sf::Texture
{
public:
	Texture(std::string name);
	
	void setName(std::string name);
	
	std::string getName();
private:
	std::string _name;
};