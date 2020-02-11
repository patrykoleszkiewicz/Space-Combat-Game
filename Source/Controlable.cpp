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
	Vector2d thrustTotal(0.0,0.0);
	double momentumTotal = 0.0;
	
	for(auto& thruster : _thrusters)
	{
		Vector2d thrust = Vector2d(0.0,-1.0).rotate(thruster.angle) * thruster.thrust * thruster.throttle;
		thrustTotal += thrust;
		
		double momentum = thruster.position.x * thrust.y - thruster.position.y * thrust.x;
		momentumTotal += momentum;
	}
	
	_velocity += thrustTotal / _mass;
	_angleVelocity += momentumTotal / _mass;
}