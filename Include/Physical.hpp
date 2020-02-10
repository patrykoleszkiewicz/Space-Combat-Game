#pragma once

#include "Vector2d.hpp"

class Physical
{
public:
	Physical();
	
	void tickPhysics();
	
	void setPosition(double X, double Y);
	void setPosition(Vector2d &V);
	
	Vector2d getPosition();
	
	void setRotation(double rot);
	
	double getRotation();
	
	void setVelocity(double X, double Y);
	void setVelocity(Vector2d &V);
	
	Vector2d getVelocity();
	
	void setMass(double mass);
	
	double getMass();
protected:
	Vector2d _position;
	Vector2d _velocity;
	
	double _rotation;
	double _angleVelocity;
	
	double _mass;
};