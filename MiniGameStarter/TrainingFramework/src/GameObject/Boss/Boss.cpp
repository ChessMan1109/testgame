#include "Boss.h"

#include "Boss/BiteAttackBState.h"
#include "Boss/DeathBState.h"
#include "Boss/FallBState.h"
#include "Boss/HurtBState.h"
#include "Boss/IdleBState.h"
#include "Boss/JumpBiteBState.h"
#include "Boss/JumpBState.h"
#include "Boss/PosionAttackBState.h"


Boss::Boss()
{
	m_IdleState = new IdleBState(this);
	m_BiteAttackState = new BiteAttackBState(this);
	m_DeathState = new DeathBState(this);
	m_PosionAttackState = new PosionAttackBState(this);
	m_FallState = new FallBState(this);
	m_HurtState = new HurtBState(this);
	m_JumpState = new JumpBState(this);
	m_JumpBiteState = new JumpBiteBState(this);
	m_BulletManager = new BulletManager(5);

	m_CurrentState=m_IdleState;
	m_NumScale = 1.0f;
	m_isTouchTheGround = false;
	m_BulletManager->SetTag(Entity::Tag_BossBullet);
	SetTag(Entity::Tag_Boss);
}

Boss::~Boss()
{
	if (m_IdleState != nullptr)
	{
		delete m_IdleState;
		m_IdleState = nullptr;
	}
	if (m_DeathState != nullptr)
	{
		delete m_DeathState;
		m_DeathState = nullptr;
	}
	if (m_JumpState != nullptr)
	{
		delete m_JumpState;
		m_JumpState = nullptr;
	}
	if (m_JumpBiteState != nullptr)
	{
		delete m_JumpBiteState;
		m_JumpBiteState = nullptr;
	}
	if (m_BiteAttackState != nullptr)
	{
		delete m_BiteAttackState;
		m_BiteAttackState = nullptr;
	}
	if (m_PosionAttackState != nullptr)
	{
		delete m_PosionAttackState;
		m_PosionAttackState = nullptr;
	}
	if (m_FallState != nullptr)
	{
		delete m_FallState;
		m_FallState = nullptr;
	}
	if (m_HurtState != nullptr)
	{
		delete m_HurtState;
		m_HurtState = nullptr;
	}
	if (m_BulletManager != nullptr)
	{
		delete m_BulletManager;
		m_BulletManager = nullptr;
	}
	
	m_CurrentState = nullptr;
}

void Boss::SetPos(Vector2 newPos)
{
	m_Pos = newPos;
}

Vector2* Boss::GetPos()
{
	return &m_Pos;
}
bool* Boss::GetisTouch()
{
	return &m_isTouchTheGround;
}
int* Boss::GetSpeed()
{
	return &m_Speed;
}
float* Boss::GetNumScale()
{
	return &m_NumScale;
}
BulletManager* Boss::GetBulletManager()
{
	return m_BulletManager;
}
IBState::STATE_Action* Boss::GetCurrentAction()
{
	return &m_CurrentAction;
}

void Boss::SetAction(IBState::STATE_Action stt)
{
	if (m_Locked == stt) return;
	m_Locked = stt;
	m_CurrentState->ResetAnimation();

	switch (stt)
	{
	case IBState::STATE_Idle:
		m_CurrentState = m_IdleState;
		break;
	case IBState::STATE_Hurt:
		m_CurrentState = m_HurtState;
		break;
	case IBState::STATE_Bite_Attack:
		m_CurrentState = m_BiteAttackState;
		break;
	case IBState::STATE_Posion_Attack:
		m_CurrentState = m_PosionAttackState;
		break;
	case IBState::STATE_Jump:
		m_CurrentState = m_JumpState;
		break;
	case IBState::STATE_Jump_Bite:
		m_CurrentState = m_JumpBiteState;
		break;
	case IBState::STATE_Fall:
		m_CurrentState = m_FallState;
		break;
	case IBState::STATE_Death:
		m_CurrentState = m_DeathState;
		break;
	default:
		break;
	}
}

void Boss::SetState()
{
	m_CurrentState->SetState();
}

void Boss::SetState(IBState* newState)
{
	m_CurrentState = newState;
}

void Boss::SetNumScale(float scale)
{
	m_NumScale = scale;
}
void Boss::Init()
{

}
void Boss::Draw()
{
	m_BulletManager->Draw();
	m_CurrentState->Draw();
}
void Boss::Update(float deltaTime)
{
	SetAction(m_CurrentAction);
	//m_BulletManager->Update(deltaTime);
	m_CurrentState->Update(deltaTime);
	Entity::SetPos(m_Pos);
}

IBState* Boss::GetState()
{
	return m_CurrentState;
}
IBState* Boss::GetIdleState()
{
	return m_IdleState;
}
IBState* Boss::GetBiteAttackState()
{
	return m_BiteAttackState;
}
IBState* Boss::GetDeathState()
{
	return m_DeathState;
}
IBState* Boss::GetPosionState()
{
	return m_PosionAttackState;
}
IBState* Boss::GetFallState()
{
	return m_FallState;
}
IBState* Boss::GetHurtState()
{
	return m_HurtState;
}
IBState* Boss::GetJumpState()
{
	return m_JumpState;
}
IBState* Boss::GetJumpBiteState()
{
	return m_JumpBiteState;
}

