#include "Skill.h"
#include "Unit.h"

Skill::Skill(int amount)
{
	amountChange = amount;
}

void Skill::applyChange(int* statChange)
{
	*statChange += amountChange;
}
