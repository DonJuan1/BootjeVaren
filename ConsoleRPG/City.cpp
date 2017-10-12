#include "City.h"

void City::processState(Game* game)
{

	cout << "You are in a city." << endl;
	cout << "Do you want to go to sea?" << endl;

	int choice;
	cin >> choice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore char input

	switch (choice) {
		case 1:
			game->setNextCity(new City());
			game->setState(new Sea());
			delete this;
			break;
	}

}
