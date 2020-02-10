#include "Engine.hpp"

int Engine::start()
{
	return 0;
}

int Engine::tickPhysics()
{
	return 0;
}

int Engine::drawFrame(sf::RenderWindow &window)
{
	window.clear();
	//Render Game
	Spaceship ship;
	ship.setTexture(_textures.at(0));
	window.draw(ship);
	
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