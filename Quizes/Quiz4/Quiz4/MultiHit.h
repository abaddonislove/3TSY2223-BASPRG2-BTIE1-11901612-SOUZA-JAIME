#pragma once
#include <string>
#include <stdlib.h>
#include <vector>
#include "SpecialAttack.h"
#include "Unit.h"

class MultiHit : public SpecialAttack
{
public:
	MultiHit(Unit* caster);
	int manaCost() override;
	void activate(vector<Unit*> targetUnits) override;
};

