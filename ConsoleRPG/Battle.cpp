#include "Battle.h"
#include "Game.h"

Battle::Battle(const City* destination, int turns)
{
	cityDestination = destination;
	turnsLeft = turns;
}

Battle::~Battle()
{
	delete pirate;
}

void Battle::processState(Game& game)
{
	if (pirate == nullptr)
	{
		pirate = new Pirate(game.getShipFactory().getRandomShip().clone());
	}

	system("cls");

	game.getShip()->printStats();

	cout << "You are in battle with some pirates" << endl;
	cout << "" << endl;

	pirate->getShip()->printPirateStats();
	cout << "" << endl;

	cout << "1: Shoot" << endl;
	cout << "2: Flight" << endl;
	cout << "3: Surrender" << endl;
	cout << "" << endl;

	cout << "Option: ";

	int choice = 0;
	cin >> choice;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	switch (choice)
	{
		case 1:
		{
			int dmgToPirate = game.getShip()->shootCannons();
			pirate->getShip()->getHit(dmgToPirate);
			int pirateHitpoints = pirate->getShip()->getHitPoints();

			if (pirate->getShip()->isDead())
			{
				game.setState(new Sea(cityDestination, turnsLeft));
				delete this;
				return;
			}
			break;
		}
		case 2:
		{
			int flightRandom = RandomGenerator::getInstance().generate(0, 100);
			int flightChance = game.getShip()->getBaseFlightChance() + pirate->getShip()->getModifierFlightChance();

			if (flightRandom <= flightChance)
			{
				game.setState(new Sea(cityDestination, turnsLeft));
				delete this;
				return;
			}
			break;
		}
		case 3:
		{
			game.getShip()->removeAllGoods();
			game.setState(new Sea(cityDestination, turnsLeft));
			delete this;
			return;

		}
	}

	int dmgToPlayer = pirate->getShip()->shootCannons();
	game.getShip()->getHit(dmgToPlayer);
}

