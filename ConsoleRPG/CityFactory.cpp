#include "CityFactory.h"

CityFactory::CityFactory() {

}

CityFactory::~CityFactory() {
	
}

City& CityFactory::getCityWithName(char* cityName)
{
	for (int i = 0; i < cityVector.size(); i++)
	{	
		if (strcmp(cityVector.at(i).getName(), cityName) == 0)
		{
			return cityVector.at(i);
		}
	}

	throw std::runtime_error("Exception caught: City not found");
}

CustomVector<City>& CityFactory::getCityVector() {
	return cityVector;
}

