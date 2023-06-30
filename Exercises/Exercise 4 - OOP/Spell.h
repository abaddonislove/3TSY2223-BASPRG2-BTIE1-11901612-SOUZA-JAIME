#pragma once
#include <string>
#include <time.h>

using namespace std;

class wizard;

class Spell
{
public:
	string Name;
	int MPcost, MinDamage, MaxDamage;
};