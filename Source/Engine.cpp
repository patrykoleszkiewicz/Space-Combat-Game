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
	window.setView(view);
	//Render Game
	
	window.display();
	return 0;
}

int Engine::reset()
{
	return 0;
}