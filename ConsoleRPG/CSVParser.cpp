#include "CSVParser.h"

void CSVParser::parseCSVShips(CustomVector<Ship*>& shipVector)
{
	ifstreamHandler fileIn("./schepen.csv");

	char type[32];
	char price[32];
	char loadSpace[32];
	char cannonry[32];
	char damagePoints[32];
	char specialties[32];

	//Ignore first line
	fileIn.getStream().ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	while (fileIn.getStream().good())
	{
		int intPrice = 0;
		int intLoadSpace = 0;
		int intCannonry = 0;
		int intDamagePoints = 0;

		fileIn.getStream().getline(type, 32, ';');
		fileIn.getStream().getline(price, 32, ';');
		fileIn.getStream().getline(loadSpace, 32, ';');
		fileIn.getStream().getline(cannonry, 32, ';');
		fileIn.getStream().getline(damagePoints, 32, ';');
		fileIn.getStream().getline(specialties, 32);

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
}

void CSVParser::parseCSVCities(CustomVector<City>& cityVector)
{
	ifstreamHandler fileIn1("./afstanden tussen steden.csv");
	ifstreamHandler fileIn2("./goederen hoeveelheid.csv");
	ifstreamHandler fileIn3("./goederen prijzen.csv");

	try
	{
		if (!fileIn1.getStream().good() || !fileIn2.getStream().good() || !fileIn3.getStream().good())
		{
			throw std::runtime_error("Could not open file");
		}
	}
	catch (...)
	{
		throw std::runtime_error("Could not open file");
	}

	parseCSVCitiesDestinations(cityVector, fileIn1);
	parseCSVCitiesGoods(cityVector, fileIn2, fileIn3);
}

void CSVParser::parseCSVCitiesDestinations(CustomVector<City>& cityVector, ifstreamHandler& file)
{
	
	//Ignore first 3 lines
	for (size_t i = 0; i < 3; i++)
	{
		file.getStream().ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	char input[256];
	file.getStream().getline(input, 256);
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
		file.getStream().getline(input, 256);

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

void CSVParser::parseCSVCitiesGoods(CustomVector<City>& cityVector, ifstreamHandler& quantityFile, ifstreamHandler& priceFile)
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
		priceFile.getStream().ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		quantityFile.getStream().ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	priceFile.getStream().ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	quantityFile.getStream().getline(quantityInput, 256);
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
		quantityFile.getStream().getline(quantityInput, 256);
		priceFile.getStream().getline(priceInput, 256);

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
