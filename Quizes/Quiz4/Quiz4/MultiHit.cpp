#include "MultiHit.h"

MultiHit::MultiHit(Unit* caster) : SpecialAttack("MultiHit", caster)
{
}

int MultiHit::manaCost()
{
	return 5;
}

// needs to add random damage
void MultiHit::activate(vector<Unit*> targetUnits)
{
	for (int i = 0; i < targetUnits.size(); i++)
	{
		if (targetUnits[i]->getFaction() != Caster->getFaction())
		{
			targetUnits[i]->setHP((int)(-this->Caster->getPOW() * .9) + rand() % 10 - 5);
		}
	}
}
