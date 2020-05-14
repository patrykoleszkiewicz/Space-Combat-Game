#include "Controlable.hpp"

Controlable::Controlable(Model* model)
:Physical(model)
{
	_mass = 1.0;
}

void Controlable::tickPhysics()
{
	_steer = {0.0, 0.0, 0.0, 0.0, false };
	_steer = _pilot->update();
	avionics();
	updateEngines();
	Physical::tickPhysics();
}

void Controlable::avionics()
{
	for(auto& thruster : _thrusters)
	{
		thruster.throttle = 0.0;
	}
}

void Controlable::updateEngines()
{
	Vector3d thrustTotal(0.0, 0.0, 0.0);
	Vector3d momentumTotal(0.0, 0.0, 0.0);
	
	for(auto& thruster : _thrusters)
	{
		Vector3d thrust = thruster.direction * thruster.thrust * thruster.throttle;
		thrustTotal += thrust;
		
		Vector3d momentum = thruster.position.cross(thrust);
		momentumTotal += momentum;
	}
	
	_velocity += thrustTotal / _mass;
	_angleVelocity += momentumTotal / _mass;
}

void Controlable::setThrusters(std::vector<Thruster> &thrusters)
{
	_thrusters = thrusters;
}

void Controlable::addThruster(Thruster &thruster)
{
	_thrusters.push_back(thruster);
}

std::vector<Thruster>& Controlable::getThrusters()
{
	return _thrusters;
}

void Controlable::setPilot(Pilot *pilot)
{
	_pilot = pilot;
}

Pilot* Controlable::getPilot()
{
	return _pilot;
}

void Controlable::setMass(double mass)
{
	_mass = mass;
}

double Controlable::getMass() const
{
	return _mass;
}