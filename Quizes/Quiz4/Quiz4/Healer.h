#pragma once
#include "Unit.h"

class Healer : public Unit
{
public:
	Healer(string name, int hp, int pow, int vit, int agi, int dex, int mp);

	void specialAttack(vector<Unit*> targetUnits) override;
};

