#include "AI Parent.h"

CArtificialIntellegence::CArtificialIntellegence(void)
	: state(-1)
	, type(-1)
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
	return state;
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