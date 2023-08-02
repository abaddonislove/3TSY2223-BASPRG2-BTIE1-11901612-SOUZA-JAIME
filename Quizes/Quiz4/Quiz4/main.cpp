#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <ctime>
#include "Unit.h"
#include "SingleTarget.h"
#include "MultiTarget.h"
#include "Healer.h"
#include "main.h"

using namespace std;

void doAction(vector<Unit*> players, vector<Unit*>* enemies);
void checkDead(vector<Unit*>* players);
void checkWinner(vector<Unit*> players);

void swapUnits(Unit* a, Unit* b)
{
	Unit* temp = a;
	a = b;
	b = temp;
}

void printTeams(vector<Unit*> team1, vector<Unit*> team2)
{
	cout << "==================================" << endl;
	cout << "Team: Warcraft" << endl;
	cout << "==================================" << endl;
	for (int i = 0; i < team1.size(); i++)
	{
		Unit* unit = team1[i];
		cout << unit->getName() << "[HP: " << unit->getHP() << "]" << endl;
	}
	cout << endl;

	cout << "==================================" << endl;
	cout << "Team: Diablo" << endl;
	cout << "==================================" << endl;
	for (int i = 0; i < team2.size(); i++)
	{
		Unit* unit = team2[i];
		cout << unit->getName() << "[HP: " << unit->getHP() << "]" << endl;
	}
	cout << endl;
}



void printTurnOrder(vector<Unit*> players)
{
	cout << "=========== TURN ORDER ===========" << endl;
	for (int i = 0; i < players.size(); i++)
	{
		cout << "#" << i+1 << " [" << players[i]->getFaction() << "] " << players[i]->getName() << endl;
	}
	cout << "=========== TURN ORDER ===========" << endl << endl;
}

void printCurrentTurn(vector<Unit*> players)
{
	cout << "Current Turn: " << "[" << players[0]->getFaction() << "] " << players[0]->getName() << endl << endl;
	system("pause");
}

void createTurnOrder(vector<Unit*>* players)
{
	for (int i = 0; i < players->size(); i++)
	{
		int max_index = i;
		for (int j = i + 1; j < players->size(); j++)
		{
			if (players->at(j)->getAGI() > players->at(max_index)->getAGI())
			{
				max_index = j;
			}
		}
		//cout << max_index << " " << i << endl;
		swap(players->at(max_index), players->at(i));
	}
}

void shiftTurnOrder(vector<Unit*>* players)
{
	int last_index = players->size()-1;
	Unit* lastPlayer = players->at(0);
	for (int i = 0; i < players->size(); i++)
	{
		if (i < players->size()-1)
		{
			swap(players->at(i), players->at(i + 1));
		}
	}
	swap(players->at(last_index), lastPlayer);
}

void setWarcraftFaction(vector<Unit*>* players)
{
	for (int i = 0; i < players->size(); i++)
	{
		players->at(i)->setFaction("Warcraft");
	}
}

void setDiabloFaction(vector<Unit*>* players)
{
	for (int i = 0; i < players->size(); i++)
	{
		players->at(i)->setFaction("Diablo");
	}
}

void printAllStart(vector<Unit*> players, vector<Unit*> team1, vector<Unit*> team2)
{
	printTeams(team1, team2);
	printTurnOrder(players);
	printCurrentTurn(players);
}

void playTurn(vector<Unit*>* players, vector<Unit*> team1, vector<Unit*> team2)
{
	if (players->at(0)->getFaction() == "Diablo")
	{
		if (players->at(0)->getManaCost() > players->at(0)->getMP())
		{
			int targetIndex;
			do 
			{ 
				targetIndex = rand() % 3;
			} while (!team1[targetIndex]->isAlive());

			players->at(0)->attack(team1[targetIndex]);
		}

		else
		{
			int action = rand() % 2;

			if (action == 0)
			{
				int targetIndex;
				do
				{
					targetIndex = rand() % 3;
				} while (!team1[targetIndex]->isAlive());

				players->at(0)->attack(team1[targetIndex]);
			}
			else if (action == 1)
			{
				players->at(0)->specialAttack(*players);
			}
		}
	}
	else if (players->at(0)->getFaction() == "Warcraft")
	{
		doAction(*players, &team2);
	}
}

void playLoop(vector<Unit*>* players, vector<Unit*> team1, vector<Unit*> team2)
{
	printAllStart(*players, team1, team2);
	system("cls");
	playTurn(players, team1, team2);
	system("cls");
	checkDead(players);
	system("cls");
	checkWinner(*players);
	system("cls");
	shiftTurnOrder(players);
}

bool checkMana(Unit* caster)
{
	if (caster->getMP() < caster->getManaCost())
	{
		cout << "No mana" << endl;
		system("pause");
		return false;
	}
	return true;
}

void checkDead(vector<Unit*>* players)
{
	for (int i = players->size()-1; i > -1; i--)
	{
		if (players->at(i)->isAlive() != true)
		{
			players->erase(players->begin()+i);
		}
	}
}

void checkWinner(vector<Unit*> players)
{
	bool wc = false;
	bool diab = false;
	for (int i = 0; i < players.size(); i++)
	{
		if (players[i]->getFaction() == "Warcraft")
		{
			wc = true;
		}
		if (players[i]->getFaction() == "Diablo")
		{
			diab = true;
		}
	}
	if (wc == false)
	{
		system("cls");
		cout << "Diablo wins!" << endl << endl;
		system("pause");
		exit(0);
	}
	if (diab == false)
	{
		system("cls");
		cout << "Warcraft wins!" << endl << endl;
		system("pause");
		exit(0);
	}
}

void printCharacterWithAction(vector<Unit*> players)
{
	cout << "Name: " << players[0]->getName() << endl;
	cout << "HP: " << players[0]->getHP() << endl;
	cout << "MP: " << players[0]->getMP() << endl;
	cout << "Pow: " << players[0]->getPOW() << endl;
	cout << "Vit: " << players[0]->getVit() << endl;
	cout << "Dex: " << players[0]->getDEX() << endl;
	cout << "Agi: " << players[0]->getAGI() << endl;

	cout << "Choose an action..." << endl;
	cout << "===============================" << endl << endl;

	cout << "        [1] Attack (MP Cost: 0)" << endl;
	cout << "        [2] Special Attack (MP Cost: " << players[0]->getManaCost() << ")" << endl;
}

void doAction(vector<Unit*> players, vector<Unit*>* enemies)
{
	printCharacterWithAction(players);

	char choice;
	do
	{
		cin >> choice;
	} while (!cin.fail() && choice != '1' && choice != '2');

	if (choice == '2' && checkMana(players[0]) == false)
	{
		system("cls");
		doAction(players, enemies);
	}

	if (choice == '1')
	{
		
		int targetIndex;
		do
		{
			targetIndex = rand() % 3;
		} while (!enemies->at(targetIndex)->isAlive());
		players[0]->attack(enemies->at(targetIndex));
		system("cls");
		cout << enemies->at(targetIndex)->getName() << "took damage. " << "[HP: " << enemies->at(targetIndex)->getHP() << "]" << endl;
	}

	if (choice == '2')
	{
		players[0]->specialAttack(players);
		system("cls");
		for (int i = 0; i < players.size(); i++)
		{
			Unit* unit = players[i];
			cout << unit->getName() << "[HP: " << unit->getHP() << "]" << endl;
		}
		cout << endl;
	}
}

int main()
{
	int hp = 100;

	vector<Unit*> Warcraft;
	vector<Unit*> Diablo;
	vector<Unit*> turnOrder;

	SingleTarget* Illidan = new SingleTarget("Illidan", hp, 13, 5, 30, 60, 20);
	MultiTarget* ETC = new MultiTarget("E.T.C", hp, 10, 5, 10, 50, 20);
	Healer* LiLi = new Healer("LiLi", hp, 8, 5, 20, 70, 20);

	SingleTarget* Valla = new SingleTarget("Valla", hp, 13, 5, 30, 60, 20);
	MultiTarget* Johanna = new MultiTarget("Johanna", hp, 10, 5, 10, 50, 20);
	Healer* Kharazim = new Healer("Kharazim", hp, 8, 5, 20, 70, 20);

	Warcraft.push_back(Illidan);
	Warcraft.push_back(ETC);
	Warcraft.push_back(LiLi);

	Diablo.push_back(Valla);
	Diablo.push_back(Johanna);
	Diablo.push_back(Kharazim);

	setWarcraftFaction(&Warcraft);
	setDiabloFaction(&Diablo);
	
	//printAllStart(turnOrder, Warcraft, Diablo);


	turnOrder.push_back(Warcraft[0]);
	turnOrder.push_back(Warcraft[1]);
	turnOrder.push_back(Warcraft[2]);

	turnOrder.push_back(Diablo[0]);
	turnOrder.push_back(Diablo[1]);
	turnOrder.push_back(Diablo[2]);

	createTurnOrder(&turnOrder);

	while (true)
	{
		playLoop(&turnOrder, Warcraft, Diablo);
	}

	for (int i = 0; i < Warcraft.size(); i++)
	{
		delete Warcraft[i];
	}
	Warcraft.clear();
	return 0;
}