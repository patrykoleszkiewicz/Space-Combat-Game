#include "Game.hpp"

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
		
	}
	return 0;
}

int Game::menu()
{
	while(GameState == 1)
	{
		
	}
	return 0;
}