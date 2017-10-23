#pragma once

#include <iostream>
#include <iomanip>
#include "LocationState.h"
#include "CityDestination.h"
#include "Goods.h"
#include "CustomVector.h"
#include "CustomPointerVector.h"
#include "Cannon.h"
#include "LightCannon.h"
#include "MediumCannon.h"
#include "HeavyCannon.h"

class Game;
class Sea;

class City : public LocationState
{
public:
	City();
	City(char* pName);
	City(City& otherCity);
	~City();

	void processState(Game* game) override;

	char* getName() { return name; };
	CustomVector<Goods>& getGoodsVector() { return goodsVector; };
	CustomVector<CityDestination>& getCityDestinationVector() { return cityDestinationVector; };
	CustomPointerVector<Cannon*>& getCannonVector() { return cannonPointerVector; };

	void setGoodsVector(CustomVector<Goods>& pGoodsVector) { goodsVector = pGoodsVector; };

private:
	char name[32];

	CustomVector<Goods> goodsVector;
	CustomVector<CityDestination> cityDestinationVector;
	CustomPointerVector<Cannon*> cannonPointerVector;

	void buyGoods(Game* game);
	void sellGoods(Game* game);
	void buyCannons(Game* game);
	void sellCannons(Game* game);

	void sailAway(Game* game);
	void repairShip(Game* game);

};
