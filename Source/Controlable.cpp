#include "Controlable.hpp"

void Controlable::tickPhysics()
{
	updatePilot();
	avionics();
	updateEngines();
	Physical::tickPhysics();
}

void Controlable::updatePilot()
{
	_pilot->update();
	_steer = _pilot->getSteer();
}

void Controlable::avionics()
{
	
}

void Controlable::updateEngines()
{
	for(auto& thruster : _thrusters)
	{
		
	}
}