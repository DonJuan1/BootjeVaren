#include "CityFactory.h"

CityFactory::CityFactory() {

}

CityFactory::~CityFactory() {
	
}

City& CityFactory::getCityWithName(const char* cityName) const
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

const CustomVector<City>& CityFactory::getCityVector() const {
	return cityVector;
}

