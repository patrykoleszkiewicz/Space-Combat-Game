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
	
	void setThrusters(std::vector<Thruster> &thrusters);
	void addThruster(Thruster &thruster);
	
	std::vector<Thruster>& getThrusters();
	
	void setPilot(Pilot &pilot);
	
	Pilot* getPilot();
	
protected:
	void avionics();
	void updateEngines();
	
	std::vector<Thruster> _thrusters;
	Steer _steer;
	Pilot* _pilot;
};