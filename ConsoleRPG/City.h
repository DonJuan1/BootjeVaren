#pragma once

#include <iostream>

#include "ShipReplacer.h"
#include "LocationState.h"
#include "CityDestination.h"
#include "Goods.h"
#include "CustomVector.h"
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
	City& operator=(const City&);

	void processState(Game& game) override;

	const char* getName() const { return name; };
	const CustomVector<Goods>& getGoodsVector() const { return goodsVector; };
	const CustomVector<CityDestination>& getCityDestinationVector() const { return cityDestinationVector; };
	const CustomVector<Cannon*>& getCannonVector() const { return cannonVector; };

	void setGoodsVector(const CustomVector<Goods>& pGoodsVector) { goodsVector = pGoodsVector; };
	void addCityDestination(const CityDestination& cityDestination) { cityDestinationVector.push_back(cityDestination); };


private:
	char name[32];

	CustomVector<Goods> goodsVector;
	CustomVector<CityDestination> cityDestinationVector;
	CustomVector<Cannon*> cannonVector;

	void buyGoods(const Game& game);
	void sellGoods(const Game& game);
	void buyCannons(const Game& game);
	void sellCannons(const Game& game);

	void sailAway(Game& game);
	void repairShip(const Game& game);
	void replaceShip(Game& game);

};
