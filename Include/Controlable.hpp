#pragma once

#include "Physical.hpp"

#include <vector>

struct Thruster
{
	double thrust;
	double throttle;
	double angle;
	Vector2d position;
};

class Controlable :public Physical
{
public:
	void tickPhysics();
protected:
	void updatePilot();
	void avionics();
	void updateEngines();
	
	std::vector<Thruster> _thrusters;
};