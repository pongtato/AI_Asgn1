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

Vector3 CArtificialIntellegence::GetPosition()
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

float CArtificialIntellegence::GetRotation()
{
	return this->m_RotateAmount;
}