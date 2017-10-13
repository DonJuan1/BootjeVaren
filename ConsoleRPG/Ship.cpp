#include "Ship.h"

Ship::Ship()
{
	cannons = new Cannon*[cannonry];
}

Ship::~Ship()
{

	for (int i = cannonCount-1; i >= 0; i--) {
		delete cannons[i];
	}
	delete [] cannons;
}

void Ship::getHit(int damage)
{
	if (damage >= damagePoints) {
		damagePoints = 0;
	}
	else {
		damagePoints = damagePoints - damage;
	}
}

void Ship::addCannon(Cannon* cannon) 
{
	if (cannonCount < cannonry) {
		cannons[cannonCount] = cannon;
		cannonCount++;
	}
}

int Ship::shootCannons() 
{
	int damage = 0;

	for (int i = 0; i < cannonCount; i++) {
		damage += cannons[i]->getDamage();
	}

	return damage;

}