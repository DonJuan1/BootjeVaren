#define _CRT_SECURE_NO_WARNINGS

#include "CSVParser.h"

CSVParser::CSVParser()
{

}

CSVParser::~CSVParser()
{

}

void CSVParser::parseCSVShips(CustomVector<Ship*>& shipVector)
{
	ifstream fileIn("./schepen.csv");

	char price[32];
	char loadSpace[32];
	char cannonry[32];
	char damagePoints[32];
	char isSmall[32];

	//Ignore first line
	fileIn.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	while (fileIn.good())
	{
		char* type = new char[32];

		fileIn.getline(type, 32, ';');
		fileIn.getline(price, 32, ';');
		fileIn.getline(loadSpace, 32, ';');
		fileIn.getline(cannonry, 32, ';');
		fileIn.getline(damagePoints, 32, ';');
		fileIn.getline(isSmall, 32);

		if (strlen(type) == 0)
		{
			delete[] type;
			break;
		}

		int intPrice = atoi(price);
		int intLoadSpace = atoi(loadSpace);
		int intCannonry = atoi(cannonry);
		int intDamagePoints = atoi(damagePoints);
		
		Ship* ship = new Ship(type, intPrice, intLoadSpace, intCannonry, intDamagePoints, false);
		
		shipVector.push_back(ship);	
	}

	fileIn.close();
}

void CSVParser::parseCSVCities(CustomVector<City*>& cityVector)
{
	ifstream fileIn1;
	ifstream fileIn2;

	try
	{
		fileIn1.open("./afstanden tussen steden.csv");
		fileIn2.open("./goederen hoeveelheid.csv");

		if (!fileIn1.good() || !fileIn1.good())
		{
			fileIn1.close();
			fileIn2.close();
			throw std::runtime_error("Could not open file");
		}
	}
	catch (...)
	{
		fileIn1.close();
		fileIn2.close();
		throw std::runtime_error("Could not open file");
	}

	parseCSVCitiesDestinations(cityVector, fileIn1);
	parseCSVCitiesGoodsQuantity(cityVector, fileIn2);

	fileIn1.close();
	fileIn2.close();
}

void CSVParser::parseCSVCitiesDestinations(CustomVector<City*>& cityVector, ifstream& file)
{
	
	//Ignore first 3 lines
	for (size_t i = 0; i < 3; i++)
	{
		file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	char input[256];
	file.getline(input, 256);
	char *p = strtok(input, ";");;

	//Get all the cities from the first row
	while (p != NULL)
	{
		City* city = new City(p);
		cityVector.push_back(city);
		p = strtok(NULL, ";");
	}

	while (true)
	{
		//Get line per City
		file.getline(input, 256);

		//Check if line is empty
		if (input[0] == 0)
		{
			return;
		}

		//Split the line
		p = strtok(input, ";");
		
		//Find the city of the row
		City* cityRow;
		for (size_t i = 0; i < cityVector.size(); i++)
		{
			if (strstr(cityVector.at(i)->getName(), p))
			{
				cityRow = cityVector.at(i);
			}
		}

		int distance = 0;
		int counter = 0;

		p = strtok(NULL, ";");
		while (p != NULL)
		{
			CityDestination* cityDestination = new CityDestination();

			distance = atoi(p);
			cityDestination->turns = distance;
			cityDestination->destination = cityVector.at(counter);

			cityRow->getCityDestinationVector().push_back(cityDestination);

			counter++;
			p = strtok(NULL, ";");
		}
	}
}

void CSVParser::parseCSVCitiesGoodsQuantity(CustomVector<City*>& cityVector, ifstream& file)
{
	CustomVector<Goods> allGoodsVector;

	//Ignore first 6 lines
	for (size_t i = 0; i < 6; i++)
	{
		file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	char input[256];
	file.getline(input, 256);
	char *p = strtok(input, ";");

	//Get all the Goods from the first row
	while (p != NULL)
	{
		Goods good(p);
		allGoodsVector.push_back(good);
		p = strtok(NULL, ";");
	}

	for (size_t i = 0; i < cityVector.size(); i++)
	{
		cityVector.at(i)->setGoodsVector(allGoodsVector);
	}

	
}
