#define _CRT_SECURE_NO_WARNINGS


#include "Battle.h"

Battle::Battle(Sea * sea)
{
	seaState = sea;
}



void Battle::processState(Game * game)
{

	cout << "You are in battle with a pirate." << endl;

	cout << "The pirate says arrr to you." << endl;
	
	cout << lastCommandMessage << endl;


	cout << "" << endl;
	cout << "0: Shoot" << endl;
	cout << "1: Flight" << endl;
	cout << "2: Surrender" << endl;
	cout << "3: Quit" << endl;
	cout << "" << endl;

	int choice = 0;
	cin >> choice;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');


	switch (choice) {
	case 0:
	{
		int dmgToPirate = game->getShip()->shootCannons();

		sprintf(buf, "%s%d", "You shoot the cannons and do damage: ", dmgToPirate);
		printf("%s\n", buf);
		lastCommandMessage = buf;

		break;
	}
	case 1:

		game->setState(seaState);
		delete this;
		break;
	case 2:


		game->setState(seaState);
		delete this;
		break;
	case 3:
		game->setState(nullptr);
		delete seaState;
		delete this;
		break;
	default:
		cout << "This is not a valid command.";
		break;
	}

}

