#include "City.h"


City::City()
{

}

City::City(char* pName)
{
	strcpy(name, pName);
}

City::~City()
{
	for (size_t i = 0; i < cityDestinationVector.size(); i++)
	{
		delete cityDestinationVector.at(i);
	}
}

void City::processState(Game* game)
{

	cout << "You are in the city " << name << endl;
	cout << "" << endl;
	cout << "1: Buy goods" << endl;
	cout << "2: Sell goods" << endl;
	cout << "3: Buy cannons" << endl;
	cout << "4: Sell cannons" << endl;
	cout << "5: Sail to next city" << endl;
	cout << "6: Repare ship" << endl;
	cout << "7: Quit" << endl;
	cout << "" << endl;

	int choice = 0;
	cin >> choice;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	switch (choice) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			game->setState(new Sea(new City()));
			delete this;
			break;
		case 6:
			break;
		case 7:
			game->setState(nullptr);
			delete this;
			break;
	}

}
