#include "Boss.h"

CBoss::CBoss()
{

}
CBoss::~CBoss()
{

}

void CBoss::Init(void)
{
	SetHealth(5000);		//HP
	SetDefencePower(50);	//DEF
	SetAttackDamage(30);	//ATK
	SetAttackSpeed(3.0f);	//Attack Speed stat
	SetAttackRange(1.0f);	//Attack Range
	SetState(FSM_MOVE);
	SetType(TYPE_BOSS);
	SetSkillCooldown(30);

}
void CBoss::RunFSM(double dt)
{
	// Reduce skill cooldown
	if (GetSkillCooldown() > 0)
		SetSkillCooldown( (float)(GetSkillCooldown() - dt));
}

// Boss Skills
void CBoss::SetSkillCooldown(float skillCD)
{
	this->skillCD = skillCD;
}
float CBoss::GetSkillCooldown(void)
{
	return skillCD;
}

// Timer on the current target
void CBoss::SetTargetTimer(float timer)
{
	currentTargetTimer = timer;
}
float CBoss::GetTargetTimer(void)
{
	return currentTargetTimer;
}