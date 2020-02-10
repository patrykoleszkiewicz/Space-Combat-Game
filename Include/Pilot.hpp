#pragma once

struct Steer
{
	double mainThrottle;
	bool forward;
	bool backward;
	bool left;
	bool right;
	bool rotateLeft;
	bool rotateRight;
};

class Pilot
{
public:
	Steer getSteer();
	
	virtual void update() = 0;
protected:
	Steer _steer;
};