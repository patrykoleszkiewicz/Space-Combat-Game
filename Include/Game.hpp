#pragma once

#include "Engine.hpp"

#include <fstream>

class Game
{
public:
	int run();
private:
	int _gameState;
	Engine _engine;
	std::ofstream log;
	
	int init();
	int menu();
	int game();
};