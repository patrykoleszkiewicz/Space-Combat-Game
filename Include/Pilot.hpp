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
	virtual Steer update() = 0;
};