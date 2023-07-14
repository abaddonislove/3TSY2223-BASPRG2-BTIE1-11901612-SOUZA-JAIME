#pragma once
#include <string>
using namespace std;

class Unit;

class Skill
{
public:
	Skill(int amount);
	
	void applyChange(int* statChange);

private:
	int amountChange;
};

