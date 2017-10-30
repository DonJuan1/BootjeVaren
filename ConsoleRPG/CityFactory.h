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
	const CustomVector<City>& getCityVector() const ;
	void addCity(City& city) { cityVector.push_back(city); }

private:
	CustomVector<City> cityVector;
};
