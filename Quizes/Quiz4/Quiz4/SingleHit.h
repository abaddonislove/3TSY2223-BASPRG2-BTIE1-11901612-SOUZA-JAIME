#pragma once
#include <string>
#include <stdlib.h>
#include <vector>
#include "SpecialAttack.h"
#include "Unit.h"

class SingleHit : public SpecialAttack
{
public:
	SingleHit(Unit* caster);
	int manaCost() override;
	void activate(vector<Unit*> targetUnits) override;
};

