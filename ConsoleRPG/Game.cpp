#include "Game.h"

Game::Game()
{
	try
	{
		ReadCSVFiles();
	}
	catch (const runtime_error& error)
	{
		cout << error.what() << endl;
		cin.get();
		return;
	}
	catch (...)
	{
		cout << "Error during loading csv files!" << endl;
		cin.get();
		return;
	}

	try
	{
		ship = shipFactory.getShipWithType("Oorlogsgaljoen").clone();
		state = new City(cityFactory.getCityWithName("Roatan"));
	}
	catch (const runtime_error& error)
	{
		cout << error.what() << endl;
		cin.get();
		return;
	}

	ship->changeGold(10000);

	while (state != nullptr) {
		
		state->processState(this);

		if (ship->isDead()) { 

			system("cls");

			ship->printStats();

			cout << endl;
			cout << "GAME OVER" << endl;
			cout << "Your ship breaks in two and everything sinks to the bottom of the sea..." << endl;
			cout << endl;
			cin.get();
			return;
		}

		if (ship->getGold() >= 1000000)
		{
			system("cls");

			ship->printStats();

			cout << endl;
			cout << "You win!" << endl;
			cout << "You have reach 1 million gold!" << endl;
			cout << endl;
			cin.get();
			return;
		}
	}
}

Game::~Game()
{
	delete ship;
	delete state;
}

void Game::setState(LocationState * s)
{
	state = s;
}

Ship* Game::getShip() const
{
	return ship;
}

void Game::ReadCSVFiles() {
	CSVParser parser;

	parser.parseCSVShips(shipFactory.getShipVector());
	parser.parseCSVCities(cityFactory.getCityVector());
}
