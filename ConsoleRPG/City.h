#pragma once

#include <iostream>

#include "LocationState.h"
#include "CityDestination.h"
#include "Goods.h"
#include "CustomVector.h"
#include "CustomPointerVector.h"
#include "Cannon.h"
#include "LightCannon.h"
#include "MediumCannon.h"
#include "HeavyCannon.h"
#include "Sea.h"

class Game;

class City : public LocationState
{
public:
	City();
	City(const char* pName);
	City(const City& otherCity);
	~City();
	City& operator=(City&);

	void processState(Game* game) override;

	const char* getName() const { return name; };
	const CustomVector<Goods>& getGoodsVector() const { return goodsVector; };
	const CustomVector<CityDestination>& getCityDestinationVector() const { return cityDestinationVector; };
	const CustomVector<Cannon*>& getCannonVector() const { return cannonPointerVector; };

	void setGoodsVector(CustomVector<Goods>& pGoodsVector) { goodsVector = pGoodsVector; };
	void addCityDestination(const CityDestination& cityDestination) { cityDestinationVector.push_back(cityDestination); };


private:
	char name[32];

	CustomVector<Goods> goodsVector;
	CustomVector<CityDestination> cityDestinationVector;
	CustomVector<Cannon*> cannonPointerVector;

	void buyGoods(Game* game);
	void sellGoods(Game* game);
	void buyCannons(Game* game);
	void sellCannons(Game* game);

	void sailAway(Game* game);
	void repairShip(Game* game);
	void replaceShip(Game* game);

};
