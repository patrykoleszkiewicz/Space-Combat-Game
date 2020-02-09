#pragma once

#include <SFML/Graphics.hpp>

class Texture :public sf::Texture
{
public:
	std::string getName();
private:
	std::string _name;
};