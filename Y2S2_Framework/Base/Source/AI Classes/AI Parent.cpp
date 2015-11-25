#include "AI Parent.h"

CArtificialIntellegence::CArtificialIntellegence(void)
	: state(-1)
	, type(-1)
	, Position(0,0,0)
	, m_RotateAmount(0)
	, m_PrevRotation(0)
	, PrevPosition(0,0,0)
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
	this->Position = newPosition;
}

void CArtificialIntellegence::UpdateRotation(float newRotate)
{
	this->m_RotateAmount = newRotate;
}

float CArtificialIntellegence::GetRotation(void)
{
	return this->m_RotateAmount;
}

Vector3 CArtificialIntellegence::GetPrevPosition(void)
{
	return this->PrevPosition;
}

void CArtificialIntellegence::UpdatePrevPosition(Vector3 newPosition)
{
	this->PrevPosition = newPosition;
}

void CArtificialIntellegence::UpdatePrevRotation(float newRotate)
{
	this->m_PrevRotation = newRotate;
}

float CArtificialIntellegence::GetPrevRotation(void)
{
	return this->m_PrevRotation;
}

Vector3 CArtificialIntellegence::GetDirection(void)
{
	Vector3 Direction;
	Direction.SetZero();
	Direction = (this->Position - this->PrevPosition);
	UpdatePrevPosition(GetPosition());
	return Direction;
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