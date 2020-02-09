#pragma once

#include "Engine.hpp"

class Game
{
public:
	int run();
private:
	int _gameState;
	Engine _engine;
	
	int game();
	int menu();
};