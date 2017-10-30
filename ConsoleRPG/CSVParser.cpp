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

	char type[32];
	char price[32];
	char loadSpace[32];
	char cannonry[32];
	char damagePoints[32];
	char specialties[32];

	//Ignore first line
	fileIn.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	while (fileIn.good())
	{
		int intPrice = 0;
		int intLoadSpace = 0;
		int intCannonry = 0;
		int intDamagePoints = 0;

		fileIn.getline(type, 32, ';');
		fileIn.getline(price, 32, ';');
		fileIn.getline(loadSpace, 32, ';');
		fileIn.getline(cannonry, 32, ';');
		fileIn.getline(damagePoints, 32, ';');
		fileIn.getline(specialties, 32);

		if (strlen(type) == 0)
		{
			break;
		}

		try
		{
			intPrice = atoi(price);
			intLoadSpace = atoi(loadSpace);
			intCannonry = atoi(cannonry);
			intDamagePoints = atoi(damagePoints);
		}
		catch (...)
		{
			throw std::exception("error : failed parsing char array to int");
		}

		bool isSmall = false;

		if (strstr(specialties, "klein"))
		{
			isSmall = true;
		}

		if (strstr(specialties, "licht"))
		{
			shipVector.push_back(new LightShip(type, intPrice, intLoadSpace, intCannonry, intDamagePoints, isSmall));
		}
		else if (strstr(specialties, "log"))
		{
			shipVector.push_back(new LogShip(type, intPrice, intLoadSpace, intCannonry, intDamagePoints, isSmall));
		}
		else
		{
			shipVector.push_back(new NormalShip(type, intPrice, intLoadSpace, intCannonry, intDamagePoints, isSmall));
		}
	}

	fileIn.close();
}

void CSVParser::parseCSVCities(CustomVector<City>& cityVector)
{
	ifstream fileIn1;
	ifstream fileIn2;
	ifstream fileIn3;

	try
	{
		fileIn1.open("./afstanden tussen steden.csv");
		fileIn2.open("./goederen hoeveelheid.csv");
		fileIn3.open("./goederen prijzen.csv");

		if (!fileIn1.good() || !fileIn2.good() || !fileIn3.good())
		{
			fileIn1.close();
			fileIn2.close();
			fileIn3.close();
			throw std::runtime_error("Could not open file");
		}
	}
	catch (...)
	{
		fileIn1.close();
		fileIn2.close();
		fileIn3.close();
		throw std::runtime_error("Could not open file");
	}

	parseCSVCitiesDestinations(cityVector, fileIn1);
	parseCSVCitiesGoods(cityVector, fileIn2, fileIn3);

	fileIn1.close();
	fileIn2.close();
	fileIn3.close();
}

void CSVParser::parseCSVCitiesDestinations(CustomVector<City>& cityVector, ifstream& file)
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
		cityVector.push_back(City(p));
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
		for (int i = 0; i < cityVector.size(); i++)
		{
			if (strstr(cityVector.at(i).getName(), p))
			{
				cityRow = &cityVector.at(i);
			}
		}

		int distance = 0;
		int counter = 0;

		p = strtok(NULL, ";");
		while (p != NULL)
		{
			CityDestination cityDestination;

			distance = atoi(p);
			cityDestination.turns = distance;
			cityDestination.destination = &cityVector.at(counter);

			cityRow->addCityDestination(cityDestination);

			counter++;
			p = strtok(NULL, ";");
		}
	}
}

void CSVParser::parseCSVCitiesGoods(CustomVector<City>& cityVector, ifstream& quantityFile, ifstream& priceFile)
{
	CustomVector<Goods> allGoodsVector;
	char *save_ptr1, *save_ptr2;
	char quantityInput[256];
	char priceInput[256];
	char *quantityPointer;
	char *pricePointer;

	//Ignore first 6 lines
	for (size_t i = 0; i < 6; i++)
	{
		priceFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		quantityFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	priceFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	quantityFile.getline(quantityInput, 256);
	quantityPointer = strtok_s(quantityInput, ";", &save_ptr2);

	//Get all the Goods from the first row
	while (quantityPointer != NULL)
	{
		Goods good(quantityPointer);
		allGoodsVector.push_back(good);
		quantityPointer = strtok_s(NULL, ";", &save_ptr2);
	}

	//Copy the goods list for all the cities
	for (int i = 0; i < cityVector.size(); i++)
	{
		cityVector.at(i).setGoodsVector(allGoodsVector);
	}

	while (true)
	{
		//Get line per City
		quantityFile.getline(quantityInput, 256);
		priceFile.getline(priceInput, 256);

		//Check if line is empty
		if (quantityInput[0] == 0 || priceInput[0] == 0)
		{
			return;
		}

		//Split the line
		quantityPointer = strtok_s(quantityInput, ";", &save_ptr2);
		pricePointer = strtok_s(priceInput, ";", &save_ptr1);

		//Find the city of the row
		City* cityRow;
		for (int i = 0; i < cityVector.size(); i++)
		{
			if (strstr(cityVector.at(i).getName(), quantityPointer))
			{
				cityRow = &cityVector.at(i);
			}
		}

		int minAmount = 0;
		int maxAmount = 0;
		int minPrice = 0;
		int maxPrice = 0;
		int counter = 0;

		quantityPointer = strtok_s(NULL, "-", &save_ptr2);
		pricePointer = strtok_s(NULL, "-", &save_ptr1);
		while (quantityPointer != NULL)
		{
			minAmount = atoi(quantityPointer);
			minPrice = atoi(pricePointer);

			quantityPointer = strtok_s(NULL, ";", &save_ptr2);
			pricePointer = strtok_s(NULL, ";", &save_ptr1);

			maxAmount = atoi(quantityPointer);
			maxPrice = atoi(pricePointer);

			cityRow->getGoodsVector().at(counter).setMinAmount(minAmount);
			cityRow->getGoodsVector().at(counter).setMaxAmount(maxAmount);
			cityRow->getGoodsVector().at(counter).setMinPrice(minPrice);
			cityRow->getGoodsVector().at(counter).setMaxPrice(maxPrice);

			counter++;
			quantityPointer = strtok_s(NULL, "-", &save_ptr2);
			pricePointer = strtok_s(NULL, "-", &save_ptr1);
		}
	}
}
