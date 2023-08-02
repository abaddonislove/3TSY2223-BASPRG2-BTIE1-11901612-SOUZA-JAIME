#pragma once
#include "Unit.h"

class SingleTarget : public Unit
{
public:
	SingleTarget(string name, int hp, int pow, int vit, int agi, int dex, int mp);
	// SingleShot
	void specialAttack(vector<Unit*> targetUnits) override;
};
