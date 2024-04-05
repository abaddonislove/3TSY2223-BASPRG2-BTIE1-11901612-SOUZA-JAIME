#include "Action.h"

Action::Action(string _name, float _damageCoefficient)
{
	m_name = _name;
	m_damageCoefficient = _damageCoefficient;
}

string Action::GetName()
{
	return m_name;
}

Unit* Action::GetTarget()
{
	return m_target;
}

Unit* Action::GetSelfUnit()
{
	return m_Unit;
}

int Action::GetManaCost()
{
	return m_manaCost;
}

vector<int> Action::GetLastDamages()
{
	return m_lastDamages;
}

int Action::GetLastDamage()
{
	return m_lastDamage;
}

void Action::SetUnit(Unit* _selfUnit)
{
	m_Unit = _selfUnit;
}

void Action::SetTarget(Unit* _target)
{
	m_target = _target;
}

void Action::SetManaCost(int _manaCost)
{
	m_manaCost = _manaCost;
}

void Action::SetLastDamages(int _lastDamage, int _unitIndex)
{
	m_lastDamages.push_back(_lastDamage);
}

void Action::SetLastDamage(int _lastDamage)
{
	m_lastDamage = _lastDamage;
}

void Action::ResetLastDamages()
{
	m_lastDamages.clear();
}

void Action::PlayAction(Unit* _target)
{
	int damage = CalculateDamage(_target);
	
	if (damage < 1) { damage = 1; }
	SetLastDamage(damage);
	SetTarget(_target);
	_target->SetHP(_target->GetHP() - damage);
}

void Action::PlayAction(vector<Unit*> _targets)
{
}

int Action::CalculateDamage(Unit* _target)
{
	int baseDamage = (this->GetSelfUnit()->GetPOW() + (this->GetSelfUnit()->GetPOW() * ((rand() % 20) / 100))) * this->m_damageCoefficient;
	int damage = baseDamage - _target->GetVIT();
	return damage;
}

