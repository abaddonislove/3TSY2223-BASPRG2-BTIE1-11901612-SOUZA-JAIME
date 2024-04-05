#include "Unit.h"

Unit::Unit(string _name, Action* _basicAction, Action* _specialAction, int _HP, int _MP, int _POW, int _VIT, int _AGI, int _DEX)
{
	m_name = _name;
	m_actions.push_back(_basicAction);
	m_actions.push_back(_specialAction);

	m_HP = _HP;
	m_MP = _MP;
	m_POW = _POW;
	m_VIT = _VIT;
	m_AGI = _AGI;
	m_DEX = _DEX;

	m_currentMP = m_MP;
	m_currentHP = m_HP;

	for (Action* a : m_actions) { a->SetUnit(this); }
}

string Unit::GetFaction()
{
	return m_faction;
}

string Unit::GetName()
{
	return m_name;
}

int Unit::GetMaxHP()
{
	return m_HP;
}

int Unit::GetHP()
{
	return m_currentHP;
}

int Unit::GetMaxMP()
{
	return m_MP;
}

int Unit::GetMP()
{
	return m_currentMP;
}

int Unit::GetPOW()
{
	return m_POW;
}

int Unit::GetVIT()
{
	return m_VIT;
}

int Unit::GetAGI()
{
	return m_AGI;
}

int Unit::GetDEX()
{
	return m_DEX;
}

Action* Unit::GetBasicAction()
{
	return m_actions[0];
}

Action* Unit::GetSpecialAction()
{
	return m_actions[1];
}

bool Unit::CheckAlive()
{
	if (m_currentHP <= 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Unit::SetHP(int _newHP)
{
	m_currentHP = _newHP;
}

void Unit::SetMP(int _newMP)
{
	m_currentMP = _newMP;
}

void Unit::SetFaction(string _faction)
{
	m_faction = _faction;
}
