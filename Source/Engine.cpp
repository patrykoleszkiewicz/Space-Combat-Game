#include "Engine.hpp"

int Engine::tickPhysics()
{
	
}

int Engine::drawFrame(sf::RenderWindow &window)
{
	window->clear();
	window->setView(view);
	//Render Game
	
	window->display();
}