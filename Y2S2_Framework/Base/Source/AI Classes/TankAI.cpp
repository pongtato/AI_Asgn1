#include "TankAI.h"

CTank::CTank(void)
{

}

CTank::~CTank(void)
{

}


void CTank::Init(void)
{

}
void CTank::RunFSM(void)
{

}

// Tank Skills
void CTank::SetSkillCooldown(float skillCD)
{
	this->skillCD = skillCD;
}
float CTank::GetSkillCooldown(void)
{
	return skillCD;
}