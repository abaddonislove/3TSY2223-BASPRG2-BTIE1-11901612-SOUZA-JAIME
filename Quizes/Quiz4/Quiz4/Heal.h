#pragma once
#include <string>
#include <stdlib.h>
#include <vector>
#include "SpecialAttack.h"
#include "Unit.h"

class Heal : public SpecialAttack
{
public:
	Heal(Unit* caster);
	int manaCost() override;
	void activate(vector<Unit*> targetUnits) override;
};

