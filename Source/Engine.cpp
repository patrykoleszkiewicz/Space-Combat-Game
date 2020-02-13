#include "Engine.hpp"

#include "PilotPlayer.hpp"

Engine::Engine()
{
	_view = sf::View(sf::Vector2f(0.0f,0.0f),sf::Vector2f(1280.0f,720.0f));
}

int Engine::start()
{
	_spaceships.clear();
	_bullets.clear();
	
	//TEST CODE
	Spaceship ship;
	
	ship.setTexture(&_textures.at(0));
	ship.setPilot((Pilot*) new PilotPlayer());
	
	ship.setPosition(300.0,300.0);
	ship.setRotation(0.0);
	
	Thruster th;
	th.thrust = 1.0;
	th.forward = true;
	th.position = Vector2d(0.0,79.0);
	ship.addThruster(th);
	
	_spaceships.push_back(ship);
	
	return 0;
}

int Engine::tickPhysics()
{
	for(auto& spaceship : _spaceships)
	{
		spaceship.tickPhysics();
		
		std::vector<Bullet> bullets = spaceship.fireGuns();
		
		for(auto& bullet : bullets)
		{
			_bullets.push_back(bullet);
		}
	}
	
	for(auto& bullet : _bullets)
	{
		bullet.tickPhysics();
	}
	
	return 0;
}

int Engine::drawFrame(sf::RenderWindow &window)
{
	window.clear();
	
	Spaceship* player = nullptr;
	
	for(auto& spaceship : _spaceships)
	{
		if(spaceship.getPilot()->getType() == PilotType::Player)
		{
			player = &spaceship;
		}
	}
	
	sf::Vector2f windowSize(window.getSize());
	
	if(player != nullptr)
	{
		_view.setCenter(player->getPosition().sfVector2f());
		_view.setRotation(player->getRotation());
	}
	_view.setSize(windowSize);
	
	window.setView(_view);
	
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