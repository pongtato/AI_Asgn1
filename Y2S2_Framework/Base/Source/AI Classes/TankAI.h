#pragma once

#include "AI Parent.h"

class CTank
{

public:
	CTank();
	~CTank();

	void Init(void);
	void RunFSM(void);

	// Tank Skills
	void SetSkillCooldown(float);
	float GetSkillCooldown(void);

private:

	float skillCD; // Taunt skill cooldown counter


};