#pragma once

#include "Pilot.hpp"

class PilotPlayer :public Pilot
{
public:
	Steer update();
};