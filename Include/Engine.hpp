#pragma once

#include "Texture.hpp"
#include "Spaceship.hpp"

#include <SFML/Graphics.hpp>
#include <vector>

class Engine
{
public:
	Engine();

	int start();
	int reset();
	int tickPhysics();
	int drawFrame(sf::RenderWindow &window, double framePercentage);
	
	void setTextures(std::vector<Texture> txt);
private:
	sf::View _view;
	
	std::vector<Texture> _textures;
	std::vector<Spaceship> _spaceships;
	std::vector<Bullet> _bullets;
};