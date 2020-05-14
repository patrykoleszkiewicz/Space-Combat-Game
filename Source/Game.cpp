#include "Game.hpp"

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <vector>

sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML");

int Game::init()
{
	std::ifstream ifs;
	ifs.open("textures/list.txt", std::ios::in);
	
	std::vector<std::string> textureList;
	
	if(ifs.good())
	{
		while(!ifs.eof())
		{
			std::string line;
			getline(ifs, line);
			if(line.length() > 0)
			{
				textureList.push_back(line);
			}
		}
		ifs.close();
	}
	else
	{
		log << "Unable to open textures/list.txt" << std::endl;
		return -1;
	}
	
	for(auto& file : textureList)
	{
		Texture txt(file);
		if(!txt.loadFromFile("textures/" + file + ".png"))
		{
			log << "Unable to load texture from textures/" << file << ".png" << std::endl;
		}
		_textures.push_back(txt);
	}
	
	return 0;
}

int Game::run()
{
	_gameState = 1;
	log.open("latest.log",std::ios::out | std::ios::trunc);
	
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
	
	log.close();
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
		
		if(gameClock.getElapsedTime().asMilliseconds() - lastTime.asMilliseconds() >= 25)
		{
			_engine.tickPhysics();
			lastTime = gameClock.getElapsedTime();
		}
	
		double framePercentage = (double)(gameClock.getElapsedTime().asMicroseconds() - lastTime.asMicroseconds()) / 25000.0;
		_engine.drawFrame(window, framePercentage);
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