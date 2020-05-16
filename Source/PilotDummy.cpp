#include "PilotDummy.hpp"

Steer PilotDummy::update()
{
    Steer steer = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, false };
    return steer;
}

PilotType PilotDummy::getType() const
{
    return PilotType::Dummy;
}