#include "Controlable.hpp"

void Controlable::tickPhysics()
{
	_steer = _pilot->update();
	avionics();
	updateEngines();
	Physical::tickPhysics();
}

void Controlable::avionics()
{
	for(auto& thruster : _thrusters)
	{
		if(thruster.forward)
		{
			if(_steer.progradeAxis > DBL_EPSILON)
			{
				thruster.throttle = _steer.progradeAxis * _steer.mainThrottle;
			}
		}
		
		if(thruster.backward)
		{
			if(_steer.progradeAxis < -DBL_EPSILON)
			{
				thruster.throttle = abs(_steer.progradeAxis) * _steer.mainThrottle;
			}
		}
		
		if(thruster.left)
		{
			if(_steer.strafeAxis < -DBL_EPSILON)
			{
				thruster.throttle = abs(_steer.strafeAxis) * _steer.mainThrottle;
			}
		}
		
		if(thruster.right)
		{
			if(_steer.strafeAxis > DBL_EPSILON)
			{
				thruster.throttle = _steer.strafeAxis * _steer.mainThrottle;
			}
		}
		
		if(thruster.rotateLeft)
		{
			if(_steer.rotateAxis < -DBL_EPSILON)
			{
				thruster.throttle = abs(_steer.rotateAxis) * _steer.mainThrottle;
			}
		}
		
		if(thruster.rotateRight)
		{
			if(_steer.rotateAxis > DBL_EPSILON)
			{
				thruster.throttle = _steer.rotateAxis * _steer.mainThrottle;
			}
		}
	}
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

void setThrusters(std::vector<Thruster> &thrusters)
{
	_thrusters = thrusters;
}

void addThruster(Thruster &thruster)
{
	_thrusters.push_back(thruster);
}

std::vector<Thruster>& getThrusters()
{
	return _thrusters;
}

