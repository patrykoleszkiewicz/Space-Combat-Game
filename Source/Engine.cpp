#include "Engine.hpp"

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