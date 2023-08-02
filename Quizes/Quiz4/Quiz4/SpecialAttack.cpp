#include "SpecialAttack.h"

SpecialAttack::SpecialAttack(string name, Unit* caster)
{
	Name = name;
	Caster = caster;
}

string SpecialAttack::getName()
{
	return Name;
}

void SpecialAttack::activate(vector<Unit*> targetUnits)
{
}

int SpecialAttack::manaCost()
{
	return 0;
}

