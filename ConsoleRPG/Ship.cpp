#include <iostream>
#include "Ship.h"
#include "LightShip.h"

Ship::Ship()
{
	
}

Ship::Ship(char* pType, int pPrice, int pLoadSpace, int pCannory, int pDamagePoint, bool pIsSmall)
	: price{ pPrice }, 
	loadSpace{ pLoadSpace }, 
	cannonry{ pCannory }, 
	hitPoints{ pDamagePoint }, 
	damagePoints {pDamagePoint}, 
	isSmall{ pIsSmall }
{
	strcpy(type, pType);
}

Ship::~Ship()
{
	
}

void Ship::getHit(int damage)
{
	if (damage >= hitPoints) {
		hitPoints = 0;
	}
	else {
		hitPoints = hitPoints - damage;
	}
}

void Ship::addCannon(Cannon* cannon) 
{
	cannons.push_back(cannon);
}

int Ship::shootCannons() 
{
	int damage = 0;

	for (int i = 0; i < cannons.size(); i++) {
		damage += cannons.at(i)->getDamage();
	}

	return damage;

}
