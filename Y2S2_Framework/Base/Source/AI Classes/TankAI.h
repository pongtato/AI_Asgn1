#pragma once

#include "AI Parent.h"

using namespace std;

class CTank : public CArtificialIntellegence
{

	enum FSM_STATES{
		MOVE,
		ATTACK,
		RETREAT,
		TAUNT,
		BLOCK,
		EVADE,
		TOTAL_STATES
	};

public:
	CTank();
	~CTank();

	void Init(void);
	void RunFSM(double dt);

	// Tank Skills
	void SetSkillCooldown(float);
	float GetSkillCooldown(void);

	void UpdateShieldRotation(float newRotate);
	float GetShieldRotation();

	void UpdateSwordRotation(float newRotate);
	float GetSwordRotation();

	void SwordSwing(double dt, float speed, float swingAmount);
	void Block(double dt, float speed, float swingAmount);

	void UpdateSwordPrevRotation(float newRotate);
	float GetSwordPrevRotation(void);

	void UpdateShieldPrevRotation(float newRotate);
	float GetShieldPrevRotation(void);

private:

	float skillCD; // Taunt skill cooldown counter
	float m_ShieldRotateAmount;
	float m_ShieldInitialRotateAmount;

	float m_SwordRotateAmount;
	float m_SwordInitialRotateAmount;
	//float m_SwordMaxRotateAmount;

	float m_SwordDelayTimer;
	float m_ShieldDelayTimer;
	bool m_DelayActive;
	bool m_DelayShield;

};