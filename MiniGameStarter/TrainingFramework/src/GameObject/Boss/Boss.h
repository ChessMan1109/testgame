#pragma once
#include "IBoss.h"
#include "Entity.h"

class Boss :
	public IBoss,public Entity
{
public:
	Boss();
	~Boss();
	void SetAction(IBState::STATE_Action);
	void SetState();
	void SetState(IBState* newState);
	void SetPos(Vector2 newPos);
	void SetNumScale(float);

	void Init();
	void Draw();
	void Update(float deltaTime);

	IBState* GetState();
	IBState* GetIdleState();
	IBState* GetBiteAttackState();
	IBState* GetDeathState();
	IBState* GetPosionState();
	IBState* GetFallState();
	IBState* GetHurtState();
	IBState* GetJumpState();
	IBState* GetJumpBiteState();

	Vector2* GetPos();
	bool* GetisTouch();
	int* GetSpeed();
	float* GetNumScale();
	IBState::STATE_Action* GetCurrentAction();
	BulletManager* GetBulletManager();

protected:
	bool m_isTouchTheGround;
	int m_Speed;
	float m_NumScale;
	IBState::STATE_Action m_Locked;
	IBState::STATE_Action m_CurrentAction;

private:
	IBState* m_CurrentState;
	IBState* m_IdleState;
	IBState* m_BiteAttackState;
	IBState* m_DeathState;
	IBState* m_PosionAttackState;
	IBState* m_FallState;
	IBState* m_HurtState;
	IBState* m_JumpState;
	IBState* m_JumpBiteState;
	BulletManager* m_BulletManager;
};