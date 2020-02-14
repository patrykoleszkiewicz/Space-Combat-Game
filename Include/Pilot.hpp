#pragma once

struct Steer
{
	double mainThrottle;
	double progradeAxis;
	double strafeAxis;
	double rotateAxis;
	
	bool trigger;
};

enum class PilotType
{
	Player,
	Missile
};

class Pilot
{
public:
	virtual Steer update() = 0;
	virtual PilotType getType() const = 0;
};