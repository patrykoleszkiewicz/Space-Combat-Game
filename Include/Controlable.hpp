#pragma once

#include "Physical.hpp"
#include "Pilot.hpp"

#include <vector>

struct Thruster
{
	double thrust;
	double throttle;
	Vector3d direction;
	Vector3d position;
};

class Controlable :public Physical
{
public:
	Controlable(const Model* model);

	void tickPhysics();
	
	void setThrusters(std::vector<Thruster> &thrusters);
	void addThruster(Thruster &thruster);
	std::vector<Thruster>& getThrusters();
	
	void setPilot(Pilot *pilot);
	
	Pilot* getPilot();
	
	void setMass(double mass);
	double getMass() const;
	
protected:
	void avionics();
	void updateEngines();
	
	std::vector<Thruster> _thrusters;
	Steer _steer;
	Pilot* _pilot;
	
	double _mass;
};