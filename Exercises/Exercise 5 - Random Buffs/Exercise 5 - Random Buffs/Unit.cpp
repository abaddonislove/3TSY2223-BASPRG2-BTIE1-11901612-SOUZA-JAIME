#include "Unit.h"
#include "Heal.h"
#include "Might.h"
#include "IronSkin.h"
#include "Concentration.h"
#include "Haste.h"

Unit::Unit(string name, int pow, int vit, int dex, int agi, int HP)
{
	mHP = HP;
	mpow = pow;
	mvit = vit;
	mdex = dex;
	magi = agi;
	Name = name;
}

void Unit::healSelf()
{
	Heal().applyChange(&mHP);
}

void Unit::mightSelf()
{
	Might().applyChange(&mpow);
}

void Unit::ironskinSelf()
{
	IronSkin().applyChange(&mvit);
}

void Unit::concentrationSelf()
{
	Concentration().applyChange(&mdex);
}

void Unit::hasteSelf()
{
	Haste().applyChange(&mdex);
}

void Unit::useRandomSkill()
{
	int choice = rand() % 5 + 1;

	switch (choice)
	{
	case 1:
		healSelf();
		break;
	case 2:
		mightSelf();
		break;
	case 3:
		ironskinSelf();
		break;
	case 4:
		concentrationSelf();
		break;
	case 5:
		hasteSelf();
		break;
	}

}


void Unit::checkStats()
{
	cout << "Name: " << Name << "\n";
	cout << "Hp: " << mHP << "\n";

	cout << "POW: " << mpow << "\n";
	cout << "VIT: " << mvit << "\n";
	cout << "DEX: " << mdex << "\n";
	cout << "AGI: " << magi << "\n\n";
}
