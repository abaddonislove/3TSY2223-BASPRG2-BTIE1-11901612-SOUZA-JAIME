#pragma once
#include <string>
#include <time.h>
#include <iostream>

using namespace std;

class Spell;

class wizard
{
public:
	string Name;
	int HP, MP, MinDamage, MaxDamage;

	Spell* spell;

	void attack(wizard* targetWizard);

	void activate(wizard* targetWizard);

	void checkAlive();

	~wizard() { cout << Name << " has fallen." << "\n"; }
};



