#include "Game.hpp"

int Game::run(){}

Game::Game(){}

int Game::game(){}

int Game::menu(){}
/*#include <SFML/Graphics.hpp>

sf::RenderWindow window(sf::VideoMode(1280, 720), "");

Game::Game()
{
	while(1){}
}

int Game::run()
{
	GameState = 1;
	while(GameState > 0)
	{
		int status;
		switch(GameState)
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
			return status;
		}
	}
	return 0;
}

int Game::game()
{
	while(GameState == 2)
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			switch(event.type)
			{
			case sf::Event::Closed:
				GameState = 1;
				break;
			}
		}
	}
	return 0;
}

int Game::menu()
{
	while(GameState == 1)
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			switch(event.type)
			{
			case sf::Event::Closed:
				GameState = 0;
				break;
			}
		}
	}
	return 0;
}*/