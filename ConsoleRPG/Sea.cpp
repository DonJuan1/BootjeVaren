#include "Sea.h"
#include "Game.h"

Sea::Sea(CityDestination* pCityDestination)
{
	city = pCityDestination->destination;
	turns = pCityDestination->turns;
}

Sea::~Sea()
{
	
}

void Sea::processState(Game* game)
{
	if (turns <= 0) {
		game->setState(new City(*city));
		delete this;
		return;
	}

	int randomBattleChance = RandomGenerator::getInstance().generate(0,100);
	if (randomBattleChance <= 20) {
		game->setState(new Battle(this));
		return;
	}

	WindHandler* currentWind = wind[RandomGenerator::getInstance().generate(0, 19)];

	system("cls");

	game->getShip()->printStats();

	cout << endl;
	cout << "Your ship is on sea" << endl;
	cout << "You are going to: " << city->getName() << endl;
	cout << "Days left: " << turns << endl;
	cout << "Wind upcoming: " << currentWind->getWindName() << endl;	
	cout << "" << endl;

	cout << "1: Next day" << endl;
	cout << "2: Quit" << endl;
	cout << "" << endl;

	cout << "Option: " ;

	int choice;
	cin >> choice;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore char input

	if (choice == 2) {
		game->setState(nullptr);
		delete this;
		return;
	}

	turns = turns - currentWind->getSailTurns(*game->getShip());
	
}
