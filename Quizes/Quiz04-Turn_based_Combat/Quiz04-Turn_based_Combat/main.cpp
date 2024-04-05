#include <iostream>
#include <algorithm>
#include <string>
#include "SingleTarget.h"
#include "BasicAttack.h"
#include "MultiTarget.h"
#include "Heal.h"
#include "Unit.h"

using namespace std;

vector<Unit*> UnitTurnOrder;
vector<Unit*> TeamWarcraft;
vector<Unit*> TeamDiablo;

//Unit: _name, _basicAction, _specialAction, _HP, _POW, _VIT, _AGI, _DEX);

Unit* MakeUnit(string _name, Action* _basicAttack, Action* _specialAttack)
{
	int HP = 20 + rand() % 13;
	int MP = 20 + rand() % 13;
	int POW = 3 + rand() % 20;
	int VIT = 1 + rand() % 4;
	int AGI = 1 + rand() % 4;
	int DEX = 1 + rand() % 5;

	return new Unit(_name, _basicAttack, _specialAttack, HP, MP, POW, VIT, AGI, DEX);
}

bool CompareAGI(Unit* _unit1, Unit* _unit2)
{
	return (_unit1->GetAGI() > _unit2->GetAGI());
}

void ShiftTurnOrder(vector<Unit*>* _unitTurnOrder)
{
	rotate(_unitTurnOrder->begin(), _unitTurnOrder->begin() + 1, _unitTurnOrder->end());
}

void SetUpTurnOrder(vector<Unit*> _team1, vector<Unit*> _team2)
{
	UnitTurnOrder.reserve(_team1.size() + _team2.size());
	UnitTurnOrder.insert(UnitTurnOrder.end(), _team1.begin(), _team1.end());
	UnitTurnOrder.insert(UnitTurnOrder.end(), _team2.begin(), _team2.end());

	sort(UnitTurnOrder.begin(), UnitTurnOrder.end(), CompareAGI);
}

void CheckAlive(vector<Unit*>* _team, vector<Unit*>* unitTurnOrder)
{
	vector<Unit*> deadUnits;
	for (Unit* u : *unitTurnOrder)
	{
		if (!u->CheckAlive())
		{
			deadUnits.push_back(u);
		}


	}

	for (Unit* u : deadUnits)
	{
		cout << u->GetName() << " has died." << endl;
		unitTurnOrder->erase(remove(unitTurnOrder->begin(), unitTurnOrder->end(), u), unitTurnOrder->end());
		_team->erase(remove(_team->begin(), _team->end(), u), _team->end());
		delete(u);
	}
}

void PrintTurnStart(vector<Unit*> _team1, vector<Unit*> _team2)
{
	cout << "==================================" << endl;
	cout << "Team: Warcraft" << endl;
	cout << "==================================" << endl;

	for (Unit* u : _team1)
	{
		cout << u->GetName() << " [HP: " << u->GetHP() << "]" << endl;
	}

	cout << endl;
	cout << "==================================" << endl;
	cout << "Team: Diablo" << endl;
	cout << "==================================" << endl;

	for (Unit* u : _team2)
	{
		cout << u->GetName() << " [HP: " << u->GetHP() << "]" << endl;
	}
}

void PrintTurnOrder(vector<Unit*> _unitTurnOrder)
{
	cout << endl;
	cout << "=========== TURN ORDER ===========" << endl;

	for (int i = 0; i < _unitTurnOrder.size(); i++)
	{
		cout << "#" << i + 1 << " [" << _unitTurnOrder[i]->GetFaction() << "] " << _unitTurnOrder[i]->GetName() << endl;
	}

	cout << "=========== TURN ORDER ===========" << endl;
	cout << endl;
	cout << "Current Turn: [" << _unitTurnOrder[0]->GetFaction() << "] " << _unitTurnOrder[0]->GetName() << endl;
	cout << endl;
}

void PrintPlayerOptions(Unit* _playerUnit)
{
	system("cls");
	cout << "Name: " << _playerUnit->GetName() << endl;
	cout << "HP: " << _playerUnit->GetHP() << "/" << _playerUnit->GetMaxHP() << endl;
	cout << "MP: " << _playerUnit->GetMP() << "/" << _playerUnit->GetMaxMP() << endl;
	cout << "Pow: " << _playerUnit->GetPOW() << endl;
	cout << "Vit: " << _playerUnit->GetVIT() << endl;
	cout << "Dex: " << _playerUnit->GetDEX() << endl;
	cout << "Agi: " << _playerUnit->GetAGI() << endl;
	cout << endl;
	cout << "Choose an action..." << endl;
	cout << "===============================" << endl;
	cout << endl;
	cout << "        [1] " << _playerUnit->GetBasicAction()->GetName() << " (MP Cost: " << _playerUnit->GetBasicAction()->GetManaCost()  <<")" << endl;
	cout << "        [2] " << _playerUnit->GetSpecialAction()->GetName() << " (MP Cost: " << _playerUnit->GetSpecialAction()->GetManaCost() << ")" << endl;
	cout << endl;
}

void PrintOutcome(Unit* _unit, int _choice, vector<Unit*>* _enemyTeam, vector<Unit*> _unitTurnOrder)
{
	switch (_choice)
	{
	default:
		cout << _unit->GetName() << " doesn't have enought MP for " << _unit->GetSpecialAction()->GetName()
			<< ". Choose another action..." << endl;
		break;

	case 1:
		if (_unit->GetBasicAction()->GetLastDamage() == 0)
		{
			cout << _unit->GetName() << " missed!" << endl;
			cout << endl;
			break;
		}

		cout << _unit->GetName() << " used " << _unit->GetBasicAction()->GetName()
			<< " on " << _unit->GetBasicAction()->GetTarget()->GetName() << "." << endl;

		cout << _unit->GetBasicAction()->GetName() << " dealt " << _unit->GetBasicAction()->GetLastDamage()
			<< " damage." << endl << endl;
		break;

	case 2:
		if (typeid(*_unit->GetSpecialAction()) == typeid(SingleTarget))
		{
			cout << _unit->GetName() << " used " << _unit->GetSpecialAction()->GetName()
				<< " on " << _unit->GetSpecialAction()->GetTarget()->GetName() << "." << endl;

			cout << _unit->GetSpecialAction()->GetName() << " dealt " << _unit->GetSpecialAction()->GetLastDamage()
				<< " damage." << endl << endl;
			break;
		}

		if (typeid(*_unit->GetSpecialAction()) == typeid(MultiTarget))
		{
			cout << _unit->GetName() << " used " << _unit->GetSpecialAction()->GetName()
				<< " against all his/her opponents." << endl;

			for (int i = 0; i < _unit->GetSpecialAction()->GetLastDamages().size(); i++)
			{
				cout << _unit->GetSpecialAction()->GetName() << " dealt " << _unit->GetSpecialAction()->GetLastDamages().at(i)
					<< " damage against " << _enemyTeam->at(i)->GetName() << "." << endl;
			}
			cout << endl;
		}

		if (typeid(*_unit->GetSpecialAction()) == typeid(Heal))
		{
			cout << _unit->GetName() << " used " << _unit->GetSpecialAction()->GetName() << " on " 
				<< _unit->GetSpecialAction()->GetTarget()->GetName() << endl;

			cout << _unit->GetSpecialAction()->GetTarget()->GetName() << " was healed for "
				<< _unit->GetSpecialAction()->GetLastDamage() << " HP." << endl;
			cout << endl;
		}
		
	}

	CheckAlive(_enemyTeam,&UnitTurnOrder);
}

bool ChooseEnemyOption(Unit* _enemy, vector<Unit*> _enemyTeam, vector<Unit*>* _playerTeam, vector<Unit*> _unitTurnOrder)
{
	int choice = rand() % 2 + 1;
	bool outPut = true;

	switch (choice)
	{
	case 1:
		_enemy->GetBasicAction()->PlayAction(*_playerTeam);

		system("cls");

		PrintOutcome(_enemy, choice, _playerTeam, _unitTurnOrder);
		break;
	case 2:
		if (_enemy->GetSpecialAction()->GetManaCost() > _enemy->GetMP())
		{
			outPut = false;
			choice = 0;
			break;
		}

		_enemy->GetSpecialAction()->PlayAction(*_playerTeam);

		system("cls");

		PrintOutcome(_enemy, choice, _playerTeam, _unitTurnOrder);
		break;
	}

	return outPut;
}

bool ChoosePlayerOption(Unit* _player, vector<Unit*> _playerTeam, vector<Unit*>* _enemyTeam, vector<Unit*> _UnitTurnOrder)
{
	int choice = 0;
	bool outPut = true;

	do
	{
		try
		{
			cin >> choice;

			if (!cin)
			{
				cin.clear();
				string input;
				getline(cin, input);
				throw 505;
			}

			if (choice < 1 || choice > 3)
			{
				throw 505;
			}
		}
		catch (...)
		{
		}

	} while (choice < 1 || choice > 2);

	switch (choice)
	{
	case 1:
		_player->GetBasicAction()->PlayAction(*_enemyTeam);
		break;

	case 2:
		if (_player->GetSpecialAction()->GetManaCost() > _player->GetMP())
		{
			outPut = false;
			choice = 0;
			break;
		}


		if (typeid(*_player->GetSpecialAction()) == typeid(Heal))
		{
			_player->GetSpecialAction()->PlayAction(_playerTeam);
			break;
		}

		for (Unit* u : *_enemyTeam)
		{
			cout << u->GetName() << endl;
		}
		_player->GetSpecialAction()->PlayAction(*_enemyTeam);
		break;
	}

	system("cls");

	PrintOutcome(_player, choice, _enemyTeam, _UnitTurnOrder);
	return outPut;
}

void CheckWin(vector<Unit*> _teamWarcraft, vector<Unit*> _teamDiablo)
{
	cout << _teamWarcraft.size() << endl;
	cout << _teamDiablo.size() << endl;
	if (_teamDiablo.size() == 0)
	{
		system("cls");
		cout << "You win!" << endl;
		exit(0);
	}

	if (_teamWarcraft.size() == 0)
	{
		system("cls");
		cout << "You Lose!" << endl;
		exit(0);
	}

	
}


void PlayGameLoop(vector<Unit*> _teamWarcraft, vector<Unit*> _teamDiablo)
{
	while(true)
	{
		bool hasMana = true;
		PrintTurnStart(_teamWarcraft, _teamDiablo);
		PrintTurnOrder(UnitTurnOrder);
		system("pause");
		system("cls");


		do 
		{
			if (UnitTurnOrder[0]->GetFaction() == "Diablo")
			{
				ChooseEnemyOption(UnitTurnOrder[0], _teamDiablo, &_teamWarcraft, UnitTurnOrder);
			}

			else
			{
				PrintPlayerOptions(UnitTurnOrder[0]);
				hasMana = ChoosePlayerOption(UnitTurnOrder[0], _teamWarcraft, &_teamDiablo, UnitTurnOrder);
			}
			
			system("pause");
			system("cls");
		} while (!hasMana);
		CheckWin(_teamWarcraft, _teamDiablo);
		ShiftTurnOrder(&UnitTurnOrder);
		cout << TeamDiablo.size() << endl;
		cout << TeamWarcraft.size() << endl;
		PrintTurnStart(_teamWarcraft, _teamDiablo);
		PrintTurnOrder(UnitTurnOrder);
	}
}


void removethings(Unit* il)
{
	UnitTurnOrder.erase(remove(UnitTurnOrder.begin(), UnitTurnOrder.end(), il), UnitTurnOrder.end());
}

int main()
{
	srand(time(0));

	Unit* etc = MakeUnit("E.T.C", new BasicAttack("Axe Smash"), new MultiTarget("Face Melt"));
	Unit* illidan = MakeUnit("Illidan", new BasicAttack("Sweeping Strike"), new SingleTarget("The Hunt"));
	Unit* lili = MakeUnit("Lili", new BasicAttack("Energy Bolt"), new Heal("Jug of Life"));

	TeamWarcraft.push_back(etc);
	TeamWarcraft.push_back(illidan);
	TeamWarcraft.push_back(lili);

	for (Unit* u : TeamWarcraft) { u->SetFaction("Warcraft"); }

	Unit* johanna = MakeUnit("Johanna", new BasicAttack("Punish"), new MultiTarget("Face Melt"));
	Unit* valla = MakeUnit("Valla", new BasicAttack("Sweeping Strike"), new SingleTarget("The Hunt"));
	Unit* kharazim = MakeUnit("Kharazim", new BasicAttack("Energy Bolt"), new Heal("Jug of Life"));

	TeamDiablo.push_back(johanna);
	TeamDiablo.push_back(valla);
	TeamDiablo.push_back(kharazim);

	for (Unit* u : TeamDiablo) { u->SetFaction("Diablo"); }

	SetUpTurnOrder(TeamWarcraft, TeamDiablo);
	//UnitTurnOrder.erase(remove(UnitTurnOrder.begin(), UnitTurnOrder.end(), illidan), UnitTurnOrder.end());
	//PrintTurnOrder(UnitTurnOrder);
	//PrintPlayerOptions(etc);
	//ChoosePlayerOption(etc, teamDiablo);
	PlayGameLoop(TeamWarcraft, TeamDiablo);

}
