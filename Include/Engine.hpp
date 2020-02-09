#pragma once
#include <SFML/Graphics.hpp>

class Engine
{
public:
	int tickPhysics();
	int drawFrame(sf::RenderWindow &window);
};