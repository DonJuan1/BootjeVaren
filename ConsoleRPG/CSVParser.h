#pragma once

#include <iostream>
#include <fstream> 
#include <String.h>

#include "Ship.h"
#include "LightShip.h"
#include "NormalShip.h"
#include "LogShip.h"
#include "City.h"
#include "CityDestination.h"
#include "Goods.h"
#include "CustomVector.h"
#include "ifstreamHandler.h"

class CSVParser
{
public:
	CSVParser() {};
	~CSVParser() {};

	void parseCSVShips(CustomVector<Ship*>&);
	void parseCSVCities(CustomVector<City>&);

private:

	void parseCSVCitiesDestinations(CustomVector<City>&, ifstreamHandler&);
	void parseCSVCitiesGoods(CustomVector<City>&, ifstreamHandler&, ifstreamHandler&);
};
