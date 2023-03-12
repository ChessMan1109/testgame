#pragma once
#include "ISecretBoss.h"

class SecretBoss :
	public ISecretBoss
{
public:
	SecretBoss();
	~SecretBoss();
	void SetAction(ISBState::STATE_Action);
	void SetState();
	void SetState(ISBState* newState);
	void SetPos(Vector2 newPos);
	void SetNumScale(float);

	void Init();
	void Draw();
	void Update(float deltaTime);

	ISBState* GetState();
	ISBState* GetMoveLeftState();
	ISBState* GetMoveRightState();
	ISBState* GetLazeAttackState();
	ISBState* GetBulletAttackState();

	Vector2* GetPos();
	int* GetSpeed();
	float* GetNumScale();
	ISBState::STATE_Action* GetCurrentAction();
	FlameManager* GetFlameManager();

protected:
	Vector2 m_Pos;
	int m_Speed;
	float m_NumScale;
	ISBState::STATE_Action m_Locked;
	ISBState::STATE_Action m_CurrentAction;
private:
	ISBState* m_CurrentState;
	ISBState* m_MoveLeftSState;
	ISBState* m_MoveRightState;
	ISBState* m_LazeAttackState;
	ISBState* m_BulletAttackState;
	FlameManager* m_FlameManager;
};