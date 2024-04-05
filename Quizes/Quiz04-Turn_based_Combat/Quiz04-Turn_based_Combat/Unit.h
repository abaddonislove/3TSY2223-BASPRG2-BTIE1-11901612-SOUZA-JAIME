#pragma once
#include <string>
#include <vector>
#include "Action.h"

using namespace std;

class Action;

class Unit
{
public:
	Unit(string _name, Action* _basicAction, Action* _specialAction, int _HP, int _MP, int _POW, int _VIT, int _AGI, int _DEX);

	string GetFaction();
	string GetName();
	int GetMaxHP();
	int GetHP();
	int GetMaxMP();
	int GetMP();
	int GetPOW();
	int GetVIT();
	int GetAGI();
	int GetDEX();
	Action* GetBasicAction();
	Action* GetSpecialAction();
	bool CheckAlive();

	void SetHP(int _newHP);
	void SetMP(int _newMP);
	void SetFaction(string _faction);

private:
	string m_name;
	string m_faction;
	vector<Action*> m_actions;

	int m_HP;
	int m_MP;
	int m_POW;
	int m_VIT;
	int m_AGI;
	int m_DEX;

	int m_currentMP;
	int m_currentHP;
};

