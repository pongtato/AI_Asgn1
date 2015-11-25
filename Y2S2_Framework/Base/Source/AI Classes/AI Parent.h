#pragma once
#include "Vector3.h"

class CArtificialIntellegence
{
	

public:
	enum AI_TYPE
	{
		TYPE_BOSS,
		TYPE_TANK,
		TYPE_HEALER,
		TYPE_DPS,
		NUM_TYPE
	};

	CArtificialIntellegence(void);
	~CArtificialIntellegence(void);

	virtual void Init(void) = 0;
	virtual void RunFSM(double dt) = 0;


	// States
	void SetState(int);
	int GetState(void);

	// Types
	void SetType(int);
	int GetType(void);

	// Health
	void SetHealth(int);
	int Gethealth(void);
	
	// Attack power 
	void SetAttackDamage(int);
	int GetAttackDamage(void);

	// Defence Power
	void SetDefencePower(int);
	int GetDefencePower(void);

	// Attack speed
	void SetAttackSpeed(float);
	float GetAttackSpeed(void);

	// Attack Range
	void SetAttackRange(float);
	float GetAttackRange(void);

	virtual Vector3 GetPosition();
	virtual void UpdatePosition(Vector3 newPosition);

	virtual void UpdateRotation(float newRotate);
	virtual float GetRotation();

	virtual void UpdatePrevRotation(float newRotate);
	virtual float GetPrevRotation();

	virtual Vector3 GetPrevPosition();
	virtual void UpdatePrevPosition(Vector3 newPosition);

	virtual Vector3 GetDirection(void);

protected:
	int health;			// HP of this AI
	int defencePower;	// DEF of this AI
	float attackSpeed;	// A-SPD of this AI
	int attackPower;	// ATK of this AI
	float attackRange;	// ATK Range of this AI
	int state; // AI State (Eg. Avoid/Taunt)
	int type; // AI job type (Eg. Boss/Tank)
	Vector3 Position;
	Vector3 PrevPosition;
	float m_PrevRotation;
	float m_RotateAmount;
	
	float moveSpeed;
	float AtkSpeed;
	
	
};