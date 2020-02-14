#pragma once

#include "Controlable.hpp"
#include "Bullet.hpp"

struct Gun
{
	Vector2d position;
	double angle;
	int charge;
	int maxCharge;
	double spread;
	
	Vector2d bulletSize;
	double bulletVelocity;
	int bulletLifetime;
};

class Spaceship :public Controlable
{
public:
	void tickPhysics();

	void setGuns(std::vector<Gun> &guns);
	void addGun(Gun& gun);
	
	std::vector<Gun> getGuns() const;
	
	std::vector<Bullet> fireGuns() const;
	
private:
	std::vector<Gun> _guns;
};