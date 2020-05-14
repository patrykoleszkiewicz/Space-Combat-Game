#pragma once

#include "Physical.hpp"

#include <SFML/Graphics.hpp>

class Bullet :public Physical
{
public:
	void tickPhysics();
	
	void setLifetime(int life);
	int getLifetimeLeft() const;
	
private:
	int _lifetime;
};