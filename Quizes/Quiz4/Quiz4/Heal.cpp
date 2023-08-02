#include "Heal.h"
#include "SpecialAttack.h"

Heal::Heal(Unit* caster) : SpecialAttack("Heal", caster)
{
}

int Heal::manaCost()
{
	return 3;
}

void Heal::activate(vector<Unit*> targetUnits)
{
	Unit* healTarget = targetUnits[0];
	for (int i = 1; i < targetUnits.size(); i++)
	{
		if (targetUnits[i]->getHP() < healTarget->getHP() && targetUnits[i]->getFaction() == Caster->getFaction())
		{
			healTarget = targetUnits[i];
		}
	}

	healTarget->setHP((int)(healTarget->getMaxHP() * .3f));
}
