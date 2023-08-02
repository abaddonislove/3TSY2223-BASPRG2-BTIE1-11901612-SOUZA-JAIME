#pragma once
#include <string>
#include <stdlib.h>
#include <vector>
#include "SpecialAttack.h"

using namespace std;

class Unit
{
public:

	Unit(string name, int hp, int pow, int vit, int agi, int dex, int MP);

	string getName();

	int getHP();

	void setFaction(string faction);

	string getFaction();

	int getPOW();

	int getAGI();

	int getVit();

	int getDEX();

	int getMP();

	int getMaxHP();

	int getManaCost();

	bool isAlive();

	void setHP(int hpChange);

	void setMP(int mpChange);

	void attack(Unit* targetUnit);

	virtual void specialAttack(vector<Unit*> targetUnits);

	bool checkHit(int targetAGI);

protected:

	SpecialAttack* special;

private:

	string Name;

	string Faction;

	int HP, POW, VIT, AGI, DEX, MP, maxHP;
};

