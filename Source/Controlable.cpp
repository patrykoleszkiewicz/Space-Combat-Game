#include "Controlable.hpp"

void Controlable::tickPhysics()
{
	_steer = _pilot->update();
	avionics();
	updateEngines();
	Physical::tickPhysics();
}

void Controlable::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::VertexArray flameModel(sf::Triangles);
	flameModel.append(sf::Vertex(sf::Vector2f(-5.0f, 5.0f), sf::Color::Cyan));
	flameModel.append(sf::Vertex(sf::Vector2f(5.0f, 5.0f), sf::Color::Cyan));
	flameModel.append(sf::Vertex(sf::Vector2f(0.0f, 20.0f), sf::Color::Cyan));
	
	sf::CircleShape flameModel2(5);
	flameModel2.setPosition(-5.0f,0.0f);
	flameModel2.setFillColor(sf::Color::Cyan);
	
	for(auto& thruster : _thrusters)
	{
		if(thruster.throttle > 0.0)
		{
			Vector2d thPosition = Vector2d::rotate(thruster.position, _rotation);
			Vector2d position = _position + thPosition;
			double rotation = _rotation + thruster.angle;
			double scale = thruster.thrust * thruster.throttle;
			
			sf::Transform transform;
			transform.translate(sf::Vector2f(position.x, position.y));
			transform.rotate(rotation);
			transform.scale(scale, scale);
			
			states.transform = transform;
			target.draw(flameModel, states);
			target.draw(flameModel2, states);
		}
	}
}

void Controlable::avionics()
{
	for(auto& thruster : _thrusters)
	{
		thruster.throttle = 0.0;
		
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