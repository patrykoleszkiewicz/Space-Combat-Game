#include "Bullet.hpp"

void Bullet::setLifetime(int life)
{
	_lifetime = life;
}
	
int Bullet::getLifetimeLeft() const
{
	return _lifetime;
}
	
void Bullet::tickPhysics()
{
    Physical::tickPhysics();
	--_lifetime;
}