#include "Ship.h"

Ship::Ship(char* pType, int pPrice, int pLoadSpace, int pCannory, int pDamagePoint, bool pIsSmall)
	: type(pType), price{pPrice}, loadSpace{pLoadSpace}, cannonry{pCannory}, damagePoints{pDamagePoint}, isSmall{pIsSmall}
{
	cannons = new Cannon*[cannonry];
}

Ship::~Ship()
{}

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
		cannons[i]->getDamage();
	}

	return damage;

}
