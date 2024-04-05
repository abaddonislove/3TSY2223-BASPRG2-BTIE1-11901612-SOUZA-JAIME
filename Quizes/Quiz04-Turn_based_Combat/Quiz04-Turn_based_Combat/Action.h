#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Unit.h"

using namespace std;

class Unit;

class Action
{
public:
	Action(string _name, float _damageCoefficient);

	string GetName();
	Unit* GetTarget();
	Unit* GetSelfUnit();
	int GetManaCost();
	vector<int> GetLastDamages();
	int GetLastDamage();
	
	void SetUnit(Unit* _selfUnit);
	void SetTarget(Unit* _target);
	void SetManaCost(int _manaCost);
	void SetLastDamages(int _lastDamage, int _unitIndex);
	void SetLastDamage(int _lastDamage);
	void ResetLastDamages();
	virtual void PlayAction(Unit* _target);
	virtual void PlayAction(vector<Unit*> _targets);
	virtual int CalculateDamage(Unit* _target);

private:
	string m_name;
	Unit* m_target;
	Unit* m_Unit;
	int m_manaCost;
	vector<int> m_lastDamages = { 0,0,0 };
	int m_lastDamage;
	float m_damageCoefficient;
};

