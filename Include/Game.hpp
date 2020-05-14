#pragma once

#include "Engine.hpp"

#include <fstream>

class Game
{
public:
	int run();
private:
	int _gameState;
	std::ofstream log;
    
    std::vector<Texture> _textures;
    std::vector<Model> _models;
    std::vector<Spaceship> _spaceshipTemplates;
	
	int init();
    int loadTextures();
    int loadModels();
    int loadSpaceshipTemplates();
    
	int menu();
	int game();
};