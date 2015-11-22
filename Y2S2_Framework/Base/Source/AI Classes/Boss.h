#pragma once

#include "AI Parent.h"

class CBoss : public CArtificialIntellegence
{
	enum FSM_STATES{
		FSM_MOVE,
		FSM_TARGET_TANK,
		FSM_TARGET_DPS,
		FSM_TARGET_HEALER,
		FSM_CAST_SKILL,
		TOTAL_STATES
	};

public:
	CBoss();
	~CBoss();

	void Init(void);
	void RunFSM(double dt);

	// Boss Skills
	void SetSkillCooldown(float);
	float GetSkillCooldown(void);

	// Timer on the current target
	void SetTargetTimer(float);
	float GetTargetTimer(void);

private:
	float skillCD; // AoE skill cooldown counter
	float currentTargetTimer;

};