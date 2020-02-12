#include "Engine.hpp"

#include "PilotPlayer.hpp"

int Engine::start()
{
	_spaceships.clear();
	
	//TEST CODE
	Spaceship ship;
	ship.setTexture(_textures.at(0));
	ship.setPilot((Pilot*)new PilotPlayer());
	
	ship.setPosition(640.0,360.0);
	
	Thruster th;
	th.thrust = 1.0;
	th.throttle = 0.0;
	th.angle = 0.0;
	th.position = Vector2d(0.0,0.0);
	
	th.forward = true;
	th.backward = false;
	th.left = false;
	th.right = false;
	th.rotateLeft = false;
	th.rotateRight = false;
	
	ship.addThruster(th);
	
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