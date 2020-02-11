#pragma once

struct Steer
{
	double mainThrottle;
	double progradeAxis;
	double strafeAxis;
	double rotateAxis;
};

class Pilot
{
public:
	Steer getSteer();
	
	virtual void update() = 0;
protected:
	Steer _steer;
};