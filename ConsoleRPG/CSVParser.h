#pragma once

#include <iostream>
#include <fstream> 

#include "Ship.h"
#include "City.h"
#include "CityDestination.h"
#include "Goods.h"
#include "CustomVector.h"

class City;
class Ship;

class CSVParser
{
public:
	CSVParser();
	~CSVParser();

	void parseCSVShips(CustomVector<Ship*>&);
	void parseCSVCities(CustomVector<City*>&);

private:

	void parseCSVCitiesDestinations(CustomVector<City*>&, ifstream&);
	void parseCSVCitiesGoodsQuantity(CustomVector<City*>&, ifstream&);
};
