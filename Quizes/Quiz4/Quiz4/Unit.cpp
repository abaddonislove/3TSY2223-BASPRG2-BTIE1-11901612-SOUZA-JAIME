#include "Unit.h"
#include <algorithm>

Unit::Unit(string name, int hp, int pow, int vit, int agi, int dex, int mp)
{
	Name = name;
	HP = hp;
	maxHP = hp;
	POW = pow;
	VIT = vit;
	AGI = agi;
	DEX = dex;
	MP = mp;
}

string Unit::getName()
{
	return Name;
}

int Unit::getHP()
{
	return HP;
}

void Unit::setFaction(string faction)
{
	Faction = faction;
}

string Unit::getFaction()
{
	return Faction;
}

int Unit::getPOW()
{
	return POW;
}

int Unit::getAGI()
{
	return AGI;
}

int Unit::getVit()
{
	return VIT;
}

int Unit::getDEX()
{
	return DEX;
}

int Unit::getMP()
{
	return MP;
}

int Unit::getMaxHP()
{
	return maxHP;
}

int Unit::getManaCost()
{
	return special->manaCost();
}

bool Unit::isAlive()
{
	if (HP > 0)
	{
		return true;
	}
	return false;
}

void Unit::setHP(int hpChange)
{
	HP += hpChange;
}

void Unit::setMP(int mpChange)
{
	MP += mpChange;
}

void Unit::attack(Unit* targetUnit)
{
	if (checkHit(targetUnit->AGI) == true)
	{
		int critRoll = (rand() % 5 + 1);

		int damage = (POW - targetUnit->getVit());

		if (critRoll == 5)
		{
			damage = (int)(damage * 1.2f);
		}

		targetUnit->HP -= damage;
	}
}

bool Unit::checkHit(int targetAGI)
{
	int hitRate = std::clamp((DEX / targetAGI) * 100, 20, 80);
	int hitRoll = rand() % 100 + 1;

	if (hitRoll <= hitRate)
	{
		return true;
	}

	return false;
}

void Unit::specialAttack(vector<Unit*> targetUnits)
{
}