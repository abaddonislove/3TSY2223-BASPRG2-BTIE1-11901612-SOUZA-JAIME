#pragma once
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

class Unit;

class SpecialAttack
{
public:
	SpecialAttack(string name, Unit* caster);

	string getName();

	virtual void activate(vector<Unit*> targetUnits);

	virtual int manaCost();

protected:

	Unit* Caster;

private:
	string Name;
};

