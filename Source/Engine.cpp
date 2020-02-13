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
	
	Gun gun;
	gun.position = Vector2d(-23,-12.0);
	gun.angle = 0.0;
	gun.charge = 0;
	gun.maxCharge = 10;
	gun.spread = 0.1;
	
	gun.bulletSize = Vector2d(2.0,10.0);
	gun.bulletVelocity = 50.0;
	gun.bulletLifetime = 10;
	
	ship.addGun(gun);
	
	gun.position = Vector2d(23,-12.0);
	ship.addGun(gun);
	
	_spaceships.push_back(ship);
	
	return 0;
}

int Engine::tickPhysics()
{
	for(auto& bullet : _bullets)
	{
		bullet.tickPhysics();
	}
	
	for(auto& spaceship : _spaceships)
	{
		spaceship.tickPhysics();
		
		std::vector<Bullet> bullets = spaceship.fireGuns();
		
		for(auto& bullet : bullets)
		{
			_bullets.push_back(bullet);
		}
	}
	
	if(_bullets.size() > 0)
	{
		for(unsigned int deleter = 0; deleter < _bullets.size();++deleter)
		{
			if(_bullets.at(deleter).getLifetimeLeft() <= 0)
			{
				//_bullets.erase(_bullets.begin() + deleter);
				//--deleter;
			}
		}
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
	
	for(auto& bullet : _bullets)
	{
		window.draw(bullet);
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