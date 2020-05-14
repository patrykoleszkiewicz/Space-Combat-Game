#pragma once

#include "Pilot.hpp"

class PilotDummy :public Pilot
{
public:
	Steer update();
	PilotType getType() const;
};