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
#include "ShipFactory.h"
#include "CityFactory.h"

class CSVParser
{
public:
	CSVParser() {};
	~CSVParser() {};

	void parseCSVShips(ShipFactory& shipFactory);
	void parseCSVCities(CityFactory& cityFactory);

private:

	void parseCSVCitiesDestinations(CityFactory& cityFactory, ifstreamHandler&);
	void parseCSVCitiesGoods(CityFactory& cityFactory, ifstreamHandler&, ifstreamHandler&);
};
