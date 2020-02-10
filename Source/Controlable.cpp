#include "Controlable.hpp"

void Controlable::tickPhysics()
{
	updatePilot();
	avionics();
	updateEngines();
	Physical::tickPhysics();
}

void Controlable::updatePilot()
{
	
}

void Controlable::avionics()
{
	
}

void Controlable::updateEngines()
{
	
}