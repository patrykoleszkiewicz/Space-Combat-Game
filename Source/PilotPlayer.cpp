#include "PilotPlayer.hpp"

#include <SFML/Graphics.hpp>

void PilotPlayer::update()
{
	_steer.mainThrottle = 1.0;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		_steer.progradeAxis = 1.0;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		_steer.progradeAxis = -1.0;
	}
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		_steer.strafeAxis = 1.0;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		_steer.strafeAxis = -1.0;
	}
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		_steer.rotateAxis = 1.0;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		_steer.rotateAxis = -1.0;
	}
}