#include "City.h"

void City::processState(Game* game)
{

	cout << "You are in the city " << name << endl;
	cout << "" << endl;
	cout << "0: Buy goods" << endl;
	cout << "1: Sell goods" << endl;
	cout << "2: Buy cannons" << endl;
	cout << "3: Sell cannons" << endl;
	cout << "4: Sail to next city" << endl;
	cout << "5: Repare ship" << endl;
	cout << "6: Quit" << endl;
	cout << "" << endl;

	int choice = 0;
	cin >> choice;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	switch (choice) {
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			game->setState(new Sea(new City()));
			delete this;
			break;
		case 5:
			break;
		case 6:
			game->setState(nullptr);
			delete this;
			break;
		default:
			cout << "This is not a valid command.";
			break;
	}

}
