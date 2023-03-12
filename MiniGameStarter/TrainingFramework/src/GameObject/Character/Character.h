#pragma once
#include "ICharacter.h"

#include "IdleCState.h"
#include "AttackCState.h"
#include "DashCState.h"
#include "RunCState.h"
#include "JumpCState.h"
#include "DeathCState.h"
#include "FallCState.h"
#include "Entity.h"

class Character:
	public ICharacter,public Entity
{
public:
	
	Character();
	~Character();
	void SetAction(ICState::STATE_Action);
	void SetState();
	void SetState(ICState* newState);
	void SetPos(Vector2 newPos);

	void Init();
	void Draw();
	void Update(float deltaTime);

	ICState* GetState();
	ICState* GetJumpState();
	ICState* GetAttackState();
	ICState* GetDeathState();
	ICState* GetDashState();
	ICState* GetIdleState();
	ICState* GetRunState();
	ICState* GetFallState();

	Vector2* GetPos();
	bool* GetisTouch();
	int* GetSpeed();
	int* GetKeyPress();
	ICState::STATE_Action* GetCurrentAction();
	BulletManager* GetBulletManager();
	std::vector<SoLoud::Wav> *GetListSound();
protected:
	bool m_isTouchTheGround;
	int m_Speed;
	int m_KeyPress;
	ICState::STATE_Action m_Locked;
	ICState::STATE_Action m_CurrentAction;
	std::vector<SoLoud::Wav> m_listSound;

private:
	ICState* m_CurrentState;
	ICState* m_JumpState;
	ICState* m_AttackState;
	ICState* m_DeathState;
	ICState* m_IdleState;
	ICState* m_RunState;
	ICState* m_DashState;
	ICState* m_FallState;
	BulletManager* m_BulletManager;
};