#include "Spaceship.hpp"

void Spaceship::tickPhysics()
{
	Controlable::tickPhysics();
	
	for(auto& gun : _guns)
	{
		if(gun.charge < gun.maxCharge)
		{
			++gun.charge;
		}
	}
}

void Spaceship::setGuns(std::vector<Gun>& guns)
{
	_guns = guns;
}

void Spaceship::addGun(Gun& gun)
{
	_guns.push_back(gun);
}

std::vector<Gun> Spaceship::getGuns() const
{
	return _guns;
}

std::vector<Bullet> Spaceship::fireGuns()
{
	std::vector<Bullet> bullets;
	
	if(_steer.trigger)
	{
		for(auto& gun : _guns)
		{
			if(gun.charge >= gun.maxCharge)
			{
				Bullet bullet;
				
				bullet.setPosition(_position + gun.position);
				
				bullet.setRotation(_rotation);
				const Vector3d velocity = gun.direction * gun.bulletVelocity;
				bullet.setVelocity(_velocity + velocity);
				bullet.setLifetime(gun.bulletLifetime);
				
				bullets.push_back(bullet);
				
				gun.charge = 0;
			}
		}
	}
	
	return bullets;
}