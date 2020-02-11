#pragma once

#include "Physical.hpp"
#include "Pilot.hpp"

#include <vector>

struct Thruster
{
	double thrust;
	double throttle;
	double angle;
	Vector2d position;
	
	bool forward;
	bool backward;
	bool left;
	bool right;
	bool rotateLeft;
	bool rotateRight;
};

class Controlable :public Physical
{
public:
	void tickPhysics();
protected:
	void avionics();
	void updateEngines();
	
	std::vector<Thruster> _thrusters;
	Steer _steer;
	Pilot* _pilot;
};