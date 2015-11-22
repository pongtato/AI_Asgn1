#pragma once

#include "AI Parent.h"

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

private:

	float skillCD; // Taunt skill cooldown counter
	float m_ShieldRotateAmount;
	float m_SwordRotateAmount;
};