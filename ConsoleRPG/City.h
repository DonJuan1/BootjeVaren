#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "Game.h"
#include "LocationState.h"
#include "Sea.h"
#include "Goods.h"
#include "CustomVector.h"
#include "CityDestination.h"

class Game;
class Goods;
class CityDestination;

class City : public LocationState
{
public:
	City();
	City(char* pName);
	~City();

	void processState(Game* game) override;

	char* getName() { return name; };
	CustomVector<Goods>& getGoodsVector() { return goodsVector; };
	CustomVector<CityDestination*>& getCityDestinationVector() { return cityDestinationVector; };

	void setGoodsVector(CustomVector<Goods>& pGoodsVector) { goodsVector = pGoodsVector; };

private:
	char name[32];

	CustomVector<Goods> goodsVector;
	CustomVector<CityDestination*> cityDestinationVector;


};
