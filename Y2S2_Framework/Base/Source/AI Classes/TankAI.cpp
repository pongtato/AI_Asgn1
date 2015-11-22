#include "TankAI.h"

CTank::CTank(void)
: m_SwordRotateAmount	(0)
, m_ShieldRotateAmount	(0)
{

}

CTank::~CTank(void)
{

}


void CTank::Init(void)
{
	SetHealth(200); // Health of Tank
	SetDefencePower(100); // Defence stat
	SetAttackDamage(100); // Attack stat
	SetAttackSpeed(1.5f); // Attack Speed stat
	SetAttackRange(1.0f); // Attack Range
	SetType(TYPE_TANK);
	SetState(MOVE);
	moveSpeed = 5.f;
	UpdateRotation(90);
}

void CTank::RunFSM(double dt)
{
	Vector3 newPostion;
	newPostion.SetZero();
	static float TestRotation;

	switch (GetState())
	{
	case MOVE:
		//TestRotation += (moveSpeed * dt);
		//UpdateRotation(TestRotation);
		newPostion.Set(GetPosition().x - (moveSpeed * dt), GetPosition().y, GetPosition().z);
		UpdatePosition(newPostion);
		break;
	default:
		break;
	}
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

void CTank::UpdateShieldRotation(float newRotate)
{
	m_ShieldRotateAmount = newRotate;
}

float CTank::GetShieldRotation()
{
	return m_ShieldRotateAmount;
}

void CTank::UpdateSwordRotation(float newRotate)
{
	m_SwordRotateAmount = newRotate;
}

float CTank::GetSwordRotation()
{
	return m_SwordRotateAmount;
}