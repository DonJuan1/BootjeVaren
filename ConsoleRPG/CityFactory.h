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

	City& getCityWithName(const char* cityName) const;
	CustomVector<City>& getCityVector() ;

private:
	CustomVector<City> cityVector;
};
