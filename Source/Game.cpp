#include "Game.hpp"
#include <SFML/Graphics.hpp>

sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML");

int Game::init()
{
	return 0;
}

int Game::run()
{
	_gameState = 1;
	
	if(init() != 0)
	{
		_gameState = -1;
	}
	
	while(_gameState > 0)
	{
		int status;
		switch(_gameState)
		{
		case 1:
			status = menu();
			break;
		case 2:
			status = game();
			break;
		}
		if(status != 0)
		{
			_gameState = status;
		}
	}
	
	return _gameState;
}

int Game::game()
{
	_engine.start();
	sf::Clock gameClock;
	sf::Time lastTime = gameClock.getElapsedTime();
	
	while(_gameState == 2)
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			switch(event.type)
			{
			case sf::Event::Closed:
				_gameState = 0;
				break;
			}
		}
		
		if(gameClock.getElapsedTime().asMilliseconds() - lastTime.asMilliseconds() >= 50)
		{
			_engine.tickPhysics();
			lastTime = gameClock.getElapsedTime();
		}
	
		_engine.drawFrame(window);
	}
	
	_engine.reset();
	
	return 0;
}

int Game::menu()
{
	_gameState = 2;
	while(_gameState == 1)
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			switch(event.type)
			{
			case sf::Event::Closed:
				_gameState = 0;
				break;
			}
		}
	
		window.clear();
		window.display();
	}
	return 0;
}