#pragma once
#include <string>
#include <time.h>
#include <iostream>
#include "Heal.h"
#include "Might.h"
#include "IronSkin.h"
#include "Concentration.h"
#include "Haste.h"

using namespace std;

class Unit
{
public:
	Unit(string name, int pow, int vit, int dex, int agi, int HP);

	void healSelf();
	void mightSelf();
	void ironskinSelf();
	void concentrationSelf();
	void hasteSelf();

	void useRandomSkill();

	void checkStats();

	string Name;
	// 0 - Power, 1 - Vitality, 2 - Dexterity, 3 - Agility, 4 - HP
	int mpow, mvit, mdex, magi, mHP;
};

