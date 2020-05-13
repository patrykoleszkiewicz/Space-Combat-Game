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

    int tickBullets();
    int tickSpaceships();
    int removeBullets();

    void setupView(sf::RenderWindow &window, Spaceship* player);
    int drawSpaceships(sf::RenderWindow &window, double framePercentage);
    int drawBullets(sf::RenderWindow &window, double framePercentage);
    int drawHUD(sf::RenderWindow &window, Spaceship* player);
    
    Spaceship* findPlayer();
    
	sf::View _view;
	
	std::vector<Texture> _textures;
	std::vector<Spaceship> _spaceships;
	std::vector<Bullet> _bullets;
};