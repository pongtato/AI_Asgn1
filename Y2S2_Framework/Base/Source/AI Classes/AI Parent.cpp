#include "AI Parent.h"

CArtificialIntellegence::CArtificialIntellegence(void)
	: state(-1)
	, type(-1)
	, Position(0,0,0)
	, m_RotateAmount(0)
{

}

CArtificialIntellegence::~CArtificialIntellegence(void)
{

}


// States
void CArtificialIntellegence::SetState(int state)
{
	this->state = state;
}
int CArtificialIntellegence::GetState(void)
{
	return this->state;
}

// Types
void CArtificialIntellegence::SetType(int type)
{
	this->type = type;
}
int CArtificialIntellegence::GetType(void)
{
	return type;
}

Vector3 CArtificialIntellegence::GetPosition(void)
{
	return this->Position;
}

void CArtificialIntellegence::UpdatePosition(Vector3 newPosition)
{
	//get diference in position change
	this->Position = (newPosition - GetPosition());
}

void CArtificialIntellegence::UpdateRotation(float newRotate)
{
	//get diference rotation position change
	this->m_RotateAmount = (newRotate - GetRotation());
}

float CArtificialIntellegence::GetRotation(void)
{
	return this->m_RotateAmount;
}

// Health
void CArtificialIntellegence::SetHealth(int health)
{
	this->health = health;
}
int CArtificialIntellegence::Gethealth(void)
{
	return health;
}

// Attack power 
void CArtificialIntellegence::SetAttackDamage(int attackPower)
{
	this->attackPower = attackPower;
}
int CArtificialIntellegence::GetAttackDamage(void)
{
	return attackPower;
}

// Defence Power
void CArtificialIntellegence::SetDefencePower(int defencePower)
{
	this->defencePower = defencePower;
}
int CArtificialIntellegence::GetDefencePower(void)
{
	return defencePower;
}

// Attack speed
void CArtificialIntellegence::SetAttackSpeed(float attackSpeed)
{
	this->attackSpeed = attackSpeed;
}
float CArtificialIntellegence::GetAttackSpeed(void)
{
	return attackSpeed;
}

// Attack Range
void CArtificialIntellegence::SetAttackRange(float attackRange)
{
	this->attackRange = attackRange;
}
float CArtificialIntellegence::GetAttackRange(void)
{
	return attackRange;
}