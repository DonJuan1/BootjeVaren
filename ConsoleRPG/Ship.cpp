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
	damagePoints{ pDamagePoint },
	hitPoints{ pDamagePoint }, 
	gold { 5000 },
	loadSpaceUsed{ 0 },
	isSmall{ pIsSmall }
{
	strcpy(type, pType);
}

Ship::~Ship()
{
	
}

Ship::Ship(Ship& otherShip)
{
	strcpy(type, otherShip.getType());

	price = otherShip.price;
	loadSpace = otherShip.loadSpace;
	cannonry = otherShip.cannonry;
	damagePoints = otherShip.damagePoints;
	hitPoints = otherShip.hitPoints;
	gold = otherShip.gold;
	isSmall = otherShip.isSmall;
	loadSpaceUsed = otherShip.loadSpaceUsed;

	goodsOnShip = otherShip.goodsOnShip;
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

void Ship::addCannon(Cannon& cannon) 
{
	//cannons.push_back(cannon);
}

int Ship::shootCannons() 
{
	/*int damage = 0;

	for (int i = 0; i < cannons.size(); i++) {
		damage += cannons.at(i).getDamage();
	}

	return damage;*/
	return 0;
}

void Ship::addGoods(Goods& goods, int amount)
{
	loadSpaceUsed += amount;

	for (int i = 0; i < goodsOnShip.size(); i++)
	{
		if (strcmp(goods.getName(), goodsOnShip.at(i).getName()))
		{
			goodsOnShip.at(i).setAmount(goodsOnShip.at(i).getAmount() + amount);
		}
	}

	Goods newGoods(goods);
	newGoods.setAmount(amount);
	goodsOnShip.push_back(newGoods);
}

void Ship::printStats()
{
	cout << "----------------------------------------------------" << endl;
	cout << "Amount of Gold: " << gold << endl;
	cout << "Current ship: " << type << endl;
	cout << "Hitpoints of ship: " << hitPoints << "/" << damagePoints << endl;
	cout << "LoadSpace of ship: " << loadSpaceUsed << "/" << loadSpace << endl;
	cout << "----------------------------------------------------" << endl;
}
