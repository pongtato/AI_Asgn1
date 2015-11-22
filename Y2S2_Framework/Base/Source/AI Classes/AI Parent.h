#pragma once
#include "Vector3.h"

class CArtificialIntellegence
{


public:
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

	virtual Vector3 GetPosition();
	virtual void UpdatePosition(Vector3 newPosition);

	virtual void UpdateRotation(float newRotate);
	virtual float GetRotation();

protected:

	int state; // AI State (Eg. Avoid/Taunt)
	int type; // AI job type (Eg. Boss/Tank)
	Vector3 Position;
	float m_RotateAmount;
	int moveSpeed;
	
};