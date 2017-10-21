#pragma once

#include "LocationState.h"
#include "CityDestination.h"
#include "Goods.h"
#include "CustomVector.h"

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

	void setGoodsVector(CustomVector<Goods>& pGoodsVector) { goodsVector = pGoodsVector; };

private:
	char name[32];

	CustomVector<Goods> goodsVector;
	CustomVector<CityDestination> cityDestinationVector;


};
