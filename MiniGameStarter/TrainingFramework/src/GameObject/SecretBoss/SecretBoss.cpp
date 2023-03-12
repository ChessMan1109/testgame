#include "SecretBoss.h"
#include "SecretBoss/BulletAttackSBState.h"
#include "SecretBoss/LazeAttackSBState.h"
#include "SecretBoss/MoveLeftSBState.h"
#include "SecretBoss/MoveRightSBState.h"

SecretBoss::SecretBoss()
{
	m_MoveLeftSState = new MoveLeftSBState(this);
	m_MoveRightState = new MoveRightSBState(this);
	m_LazeAttackState = new LazeAttackSBState(this);
	m_BulletAttackState = new BulletAttackSBState(this);
	m_FlameManager = new FlameManager(20);

	m_CurrentState = m_MoveRightState;
	m_CurrentAction = ISBState::STATE_MOVE_Right;
	m_Locked = ISBState::STATE_MOVE_Right;
	m_NumScale = 1.0f;
	m_Speed = 100;
}

SecretBoss::~SecretBoss()
{
	if (m_MoveLeftSState != nullptr)
	{
		delete m_MoveLeftSState;
		m_MoveLeftSState = nullptr;
	}
	if (m_MoveRightState != nullptr)
	{
		delete m_MoveRightState;
		m_MoveRightState = nullptr;
	}
	if (m_LazeAttackState != nullptr)
	{
		delete m_LazeAttackState;
		m_LazeAttackState = nullptr;
	}
	if (m_BulletAttackState != nullptr)
	{
		delete m_BulletAttackState;
		m_BulletAttackState = nullptr;
	}
	
	if (m_FlameManager != nullptr)
	{
		delete m_FlameManager;
		m_FlameManager = nullptr;
	}

	m_CurrentState = nullptr;
}

void SecretBoss::SetPos(Vector2 newPos)
{
	m_Pos = newPos;
}

Vector2* SecretBoss::GetPos()
{
	return &m_Pos;
}

int* SecretBoss::GetSpeed()
{
	return &m_Speed;
}
float* SecretBoss::GetNumScale()
{
	return &m_NumScale;
}
FlameManager* SecretBoss::GetFlameManager()
{
	return m_FlameManager;
}
ISBState::STATE_Action* SecretBoss::GetCurrentAction()
{
	return &m_CurrentAction;
}

void SecretBoss::SetAction(ISBState::STATE_Action stt)
{
	if (m_Locked == stt) return;
	m_Locked = stt;

	switch (stt)
	{
	case ISBState::STATE_MOVE_Left:
		m_CurrentState = m_MoveLeftSState;
		break;
	case ISBState::STATE_MOVE_Right:
		m_CurrentState = m_MoveRightState;
		break;
	case ISBState::STATE_Laze_Attack:
		m_CurrentState = m_LazeAttackState;
		break;
	default:
		break;
	}
}

void SecretBoss::SetState()
{
	m_CurrentState->SetState();
}

void SecretBoss::SetState(ISBState* newState)
{
	m_CurrentState = newState;
}

void SecretBoss::SetNumScale(float scale)
{
	m_NumScale = scale;
}
void SecretBoss::Init()
{

}
void SecretBoss::Draw()
{
	m_CurrentState->Draw();
}

void SecretBoss::Update(float deltaTime)
{
	SetAction(m_CurrentAction);
	//m_FlameManager->Update(deltaTime);
	m_CurrentState->Update(deltaTime);
}

ISBState* SecretBoss::GetState()
{
	return m_CurrentState;
}
ISBState* SecretBoss::GetMoveLeftState()
{
	return m_MoveLeftSState;
}
ISBState* SecretBoss::GetMoveRightState()
{
	return m_MoveRightState;
}
ISBState* SecretBoss::GetLazeAttackState()
{
	return m_LazeAttackState;
}
ISBState* SecretBoss::GetBulletAttackState()
{
	return m_BulletAttackState;
}

