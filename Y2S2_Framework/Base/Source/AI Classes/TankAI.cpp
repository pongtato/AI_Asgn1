#include "TankAI.h"

CTank::CTank(void)
: m_SwordRotateAmount	(0)
, m_ShieldRotateAmount	(0)
, m_SwordDelayTimer		(0)
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
	AtkSpeed = 1.f;
	UpdateRotation(90);
	m_DelayActive = false;
}

void CTank::RunFSM(double dt)
{
	Vector3 newPostion;
	newPostion.SetZero();
	static float TestRotation;

	switch (GetState())
	{
	case MOVE:
		newPostion.Set(GetPosition().x - (moveSpeed * dt), GetPosition().y, GetPosition().z);
		UpdatePosition(newPostion);
		break;
	case ATTACK:
		//stop moving
		newPostion.SetZero();
		UpdatePosition(newPostion);
		//swing sword
		SwordSwing(dt, AtkSpeed, 90.f);
		break;
	case RETREAT:
		//Move in opposite direction from target
		break;
	case TAUNT:
		//Set target priority highest
		break;
	case BLOCK:
		Block(dt, AtkSpeed, -90.f);
		break;
	case EVADE:
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

void CTank::SwordSwing(double dt, float speed, float swingAmount)
{
	static float resetSpeed = speed*0.8f;

	if (!m_DelayActive)
	{
		m_SwordDelayTimer += dt;
	}
	else if (m_DelayActive)
	{
		m_SwordDelayTimer -= dt;
	}

	if (m_SwordDelayTimer > speed)
	{
		m_SwordRotateAmount = swingAmount;
		m_DelayActive = true;
	}

	if (m_DelayActive && m_SwordDelayTimer < resetSpeed)
	{
		m_SwordRotateAmount = -swingAmount;
		m_DelayActive = false;
	}
}

void CTank::Block(double dt, float speed, float swingAmount)
{
		m_ShieldRotateAmount = swingAmount;
}

void CTank::UpdateSwordPrevRotation(float newRotate)
{
	m_SwordInitialRotateAmount = newRotate;
}

float CTank::GetSwordPrevRotation(void)
{
	return m_SwordInitialRotateAmount;
}

void CTank::UpdateShieldPrevRotation(float newRotate)
{
	m_ShieldInitialRotateAmount = newRotate;
}

float CTank::GetShieldPrevRotation(void)
{
	return m_ShieldInitialRotateAmount;
}
