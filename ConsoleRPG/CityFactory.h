#pragma once

#include <iostream>
#include "CustomVector.h"
#include "RandomGenerator.h"
#include "City.h"

class CityFactory
{
public:
	CityFactory();
	~CityFactory();

	//CustomVector<City>& getCityVector();
	//void setCityVector(CustomVector<City>*);

private:
	char cityVector[20];
};
