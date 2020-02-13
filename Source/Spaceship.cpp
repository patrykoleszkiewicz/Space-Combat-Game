#include "Spaceship.hpp"

void Spaceship::setGuns(std::vector<Gun>& guns)
{
	_guns = guns;
}

void Spaceship::addGun(Gun& gun)
{
	_guns.push_back(gun);
}

std::vector<Gun> getGuns() const
{
	return _guns;
}

std::vector<Bullet> fireGuns()
{
	std::vector<Bullet> bullets;
	
	if(_steer.trigger)
	{
		for(auto& gun : _guns)
		{
			Bullet bullet;
			
			bullet.setPosition(_position + gun.position.rotate(_rotation);
			bullet.setRotation(_rotation + gun.angle);
			bullet.setVelocity(_velocity + Vector2d(0.0,-gun.bulletVelocity).rotate(bullet.getRotation));
			bullet.setSize(gun.bulletSize);
			
			bullets.push_back(bullet);
		}
	}
	
	return bullets;
}