#pragma once

class CArtificialIntellegence
{


public:
	CArtificialIntellegence(void);
	~CArtificialIntellegence(void);

	virtual void Init(void) = 0;
	virtual void RunFSM(void) = 0;


	// States
	void SetState(int);
	int GetState(void);

	// Types
	void SetType(int);
	int GetType(void);
	
private:

	int state; // AI State (Eg. Avoid/Taunt)
	int type; // AI job type (Eg. Boss/Tank)
};