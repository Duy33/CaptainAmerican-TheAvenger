#pragma once
#include <d3dx9.h>

class ShieldState
{
public:
	enum NameState
	{
		Nomal,
		OnAir,
		ShieldUp, 
		ShieldAttack,
		ShieldDown,
		ShieldKick
	};
	ShieldState();
	ShieldState(NameState State);

	virtual void Update(float dt) {};
	virtual void Draw() {};
	int GetFrameLock();

	void SetCurrentState(NameState State);
	NameState GetCurrentState();
protected:
	NameState CurrentState;
	int FrameLock;
	D3DXVECTOR2 VirtualPoint;
	D3DXVECTOR2 WorldPoint;
};