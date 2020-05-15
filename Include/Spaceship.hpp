#pragma once

#include "Controlable.hpp"
#include "Bullet.hpp"

struct Gun
{
    Vector3d position;
    Vector3d direction;
    int charge;
    int maxCharge;
    double spread;
    
    double bulletVelocity;
    int bulletLifetime;
};

class Spaceship :public Controlable
{
public:
    Spaceship(Model* model);
    void tickPhysics();

    void setGuns(std::vector<Gun> &guns);
    void addGun(Gun& gun);
    
    std::vector<Gun> getGuns() const;
    
    std::vector<Bullet> fireGuns();
    
private:
    std::vector<Gun> _guns;
};