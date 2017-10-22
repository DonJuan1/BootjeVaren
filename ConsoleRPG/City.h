#pragma once

#include <iostream>
#include <iomanip>
#include "LocationState.h"
#include "CityDestination.h"
#include "Goods.h"
#include "CustomVector.h"
#include "Cannon.h"

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
	CustomVector<Cannon*>& getCannonVector() { return cannonVector; };

	void setGoodsVector(CustomVector<Goods>& pGoodsVector) { goodsVector = pGoodsVector; };

private:
	char name[32];

	CustomVector<Goods> goodsVector;
	CustomVector<CityDestination> cityDestinationVector;
	CustomVector<Cannon*> cannonVector;

	void buyGoods(Game* game);
	void sellGoods(Game* game);
	void buyCannons(Game* game);
	void sellCannons(Game* game);

	void sailAway(Game* game);
	void repairShip(Game* game);

};
