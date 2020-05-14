#include "Game.hpp"

#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML");

int Game::init()
{
	int textureStatus = loadTextures();
	
    if(textureStatus != 0)
    {
        return -1;
    }
    
    int modelStatus = loadModels();
    
    if(modelStatus != 0)
    {
        return -1;
    }
	
	return 0;
}

int Game::loadTextures()
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
	
    bool isGood = true;
    
	for(auto& file : textureList)
	{
		Texture txt(file);
		if(!txt.loadFromFile("textures/" + file + ".png"))
		{
			log << "Unable to load texture from textures/" << file << ".png" << std::endl;
            isGood = false;
		}
		_textures.push_back(txt);
	}
    
    if(!isGood)
    {
        return -1;
    }
    
    return 0;
}

int Game::loadModels()
{
    std::ifstream ifs;
	ifs.open("models/list.txt", std::ios::in);
	
	std::vector<std::string> modelList;
	
	if(ifs.good())
	{
		while(!ifs.eof())
		{
			std::string line;
			getline(ifs, line);
			if(line.length() > 0)
			{
				modelList.push_back(line);
			}
		}
		ifs.close();
	}
	else
	{
		log << "Unable to open models/list.txt" << std::endl;
		return -1;
	}
	
    bool isGood = true;
    
	for(auto& file : modelList)
	{
        std::ifstream fs;
		fs.open("models/" + file + ".obj", std::ios::in);
		if (fs.good())
		{
            std::vector<Vector3d> vertices;
            std::vector<Triangle> triangles;
            
            while (!fs.eof())
			{
				std::string line;
				getline(fs, line);
                
                std::stringstream ss;
                ss << line;
                
                char junk;
                
				if(line[0] == 'v')
				{
                    Vector3d point;
                    ss >> junk >> point.x >> point.y >> point.z;
                    vertices.push_back(point);
                }
                else if(line[0] == 'f')
                {
                    int indexes[3];
                    ss >> junk >> indexes[0] >> indexes[1] >> indexes[2];
                    Triangle triangle;
                    try
                    {
                        triangle.point1 = vertices.at(indexes[0] - 1);
                        triangle.point2 = vertices.at(indexes[1] - 1);
                        triangle.point3 = vertices.at(indexes[2] - 1);
                    }
                    catch(...)
                    {
                        log << "File models/" + file + ".obj corrupted\n";
                        return -1;
                    }
                    triangles.push_back(triangle);
                }
            }
            
            Model model(nullptr);
            model._triangles = triangles;
            _models.push_back(model);
        }
        else
        {
            log << "Unable to load model from models/" << file << ".obj" << std::endl;
            isGood = false;
        }
	}
    
    if(!isGood)
    {
        return -1;
    }
    
    return 0;
}

int Game::run()
{
	_gameState = 1;
	log.open("latest.log", std::ios::out | std::ios::trunc);
	
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