#pragma once

struct Steer
{
    double mainThrottle;
    
    double progradeAxis;
    double strafeAxis;
    double elevationAxis;
    
    double pitch;
    double yaw;
    double roll;
    
    bool trigger;
};

enum class PilotType
{
    Dummy,
    Player,
    Missile
};

class Pilot
{
public:
    virtual Steer update() = 0;
    virtual PilotType getType() const = 0;
};