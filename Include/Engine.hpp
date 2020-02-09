#pragma once

#include "Texture.hpp"

#include <SFML/Graphics.hpp>

class Engine
{
public:
	int start();
	int reset();
	int tickPhysics();
	int drawFrame(sf::RenderWindow &window);
private:
	sf::View view;
};