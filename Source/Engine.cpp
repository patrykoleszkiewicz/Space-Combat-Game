#include "Engine.hpp"

#include "PilotPlayer.hpp"

int Engine::start()
{
	_spaceships.clear();
	
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