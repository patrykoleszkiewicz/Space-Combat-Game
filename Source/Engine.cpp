#include "Engine.hpp"

int Engine::start()
{
	_spaceships.clear();
	
	Spaceship ship;
	ship.setTexture(_textures.at(0));
	ship.setVelocity(5.0,5.0);
	_spaceships.push_back(ship);
	
	return 0;
}

int Engine::tickPhysics()
{
	for(auto& spaceship : _spaceships)
	{
		spaceship.tickPhysics();
	}
	
	return 0;
}

int Engine::drawFrame(sf::RenderWindow &window)
{
	window.clear();
	
	for(auto& spaceship : _spaceships)
	{
		window.draw(spaceship);
	}
	
	window.display();
	return 0;
}

int Engine::reset()
{
	return 0;
}

void Engine::setTextures(std::vector<Texture> txt)
{
	_textures = txt;
}