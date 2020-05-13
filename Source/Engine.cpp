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
	
	return 0;
}

int Engine::tickPhysics()
{
	tickBullets();
	
	tickSpaceships();
	
	removeBullets();
	
	return 0;
}

int Engine::tickBullets()
{
    for(auto& bullet : _bullets)
	{
		bullet.tickPhysics();
	}
    return 0;
}

int Engine::tickSpaceships()
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
    return 0;
}

int Engine::removeBullets()
{
    if(_bullets.size() > 0)
	{
		for(unsigned int deleter = 0; deleter < _bullets.size();++deleter)
		{
			if(_bullets.at(deleter).getLifetimeLeft() <= 0)
			{
				_bullets.erase(_bullets.begin() + deleter);
				--deleter;
			}
		}
	}
    return 0;
}

int Engine::drawFrame(sf::RenderWindow &window, double framePercentage)
{
	window.clear();
	
    Spaceship* player = findPlayer();
	
	setupView(window, player);
	
	drawSpaceships(window, framePercentage);
	
	drawBullets(window, framePercentage);
	
    drawHUD(window, player);
    
	window.display();
    
	return 0;
}

Spaceship* Engine::findPlayer()
{
    Spaceship* player = nullptr;
	
	for(auto& spaceship : _spaceships)
	{
		if(spaceship.getPilot()->getType() == PilotType::Player)
		{
			player = &spaceship;
		}
	}
    
    return player;
}

void Engine::setupView(sf::RenderWindow &window, Spaceship* player)
{
    sf::Vector2f windowSize(window.getSize());
	
	if(player != nullptr)
	{
		_view.setCenter(player->getPosition().sfVector2f());
		_view.setRotation(player->getRotation());
	}
	_view.setSize(windowSize);
	
	window.setView(_view);
}

int Engine::drawSpaceships(sf::RenderWindow &window, double framePercentage)
{
    for(auto& spaceship : _spaceships)
	{
		window.draw(spaceship);
	}
    return 0;
}

int Engine::drawBullets(sf::RenderWindow &window, double framePercentage)
{
    for(auto& bullet : _bullets)
	{
		Vector2d drawOffset = bullet.getVelocity() * framePercentage;
		
		sf::Transform transform;
		transform.translate(drawOffset.sfVector2f());
		
		sf::RenderStates states;
		states.transform = transform;
		
		window.draw(bullet, states);
	}
    return 0;
}

int Engine::drawHUD(sf::RenderWindow &window, Spaceship* player)
{
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