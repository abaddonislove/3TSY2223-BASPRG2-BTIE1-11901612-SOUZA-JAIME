#pragma once
#include "Unit.h"

class MultiTarget : public Unit
{
public:
	MultiTarget(string name, int hp, int pow, int vit, int agi, int dex, int mp);

	// Multishot
	void specialAttack(vector<Unit*> targetUnits) override;
};

