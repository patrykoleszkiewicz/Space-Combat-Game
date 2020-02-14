#include "PilotPlayer.hpp"

#include <SFML/Graphics.hpp>

Steer PilotPlayer::update()
{
	Steer steer;
	steer.mainThrottle = 1.0;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		steer.progradeAxis = 1.0;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		steer.progradeAxis = -1.0;
	}
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		steer.strafeAxis = 1.0;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		steer.strafeAxis = -1.0;
	}
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		steer.rotateAxis = 1.0;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		steer.rotateAxis = -1.0;
	}
	
	steer.trigger = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
	
	return steer;
}

PilotType PilotPlayer::getType() const
{
	return PilotType::Player;
}