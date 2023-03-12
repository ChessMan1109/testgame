#include "Character.h"
extern int screenWidth;
extern int screenHeight;
Character::Character()
{
	m_JumpState = new JumpCState(this);
	m_AttackState = new AttackCState(this);
	m_DeathState = new DeathCState(this);
	m_IdleState = new IdleCState(this);
	m_RunState = new RunCState(this);
	m_DashState = new DashCState(this);
	m_FallState = new FallCState(this);
	m_BulletManager = new BulletManager(20);
	m_CurrentState = m_IdleState;

	m_isTouchTheGround = false;
	m_listSound.resize(ICState::Sound_Nums);
	m_Pos = Vector2(100, 100);
	m_BulletManager->SetTag(Entity::Tag_CharacterBullet);
	SetTag(Entity::Tag_Character);
}

Character::~Character()
{
	if (m_IdleState != nullptr)
	{
		delete m_IdleState;
		m_IdleState = nullptr;
	}
	if (m_DashState != nullptr)
	{
		delete m_DashState;
		m_DashState = nullptr;
	}
	if (m_RunState != nullptr)
	{
		delete m_RunState;
		m_RunState = nullptr;
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

	if (m_AttackState != nullptr)
	{
		delete m_AttackState;
		m_AttackState = nullptr;
	}
	if (m_FallState != nullptr)
	{
		delete m_FallState;
		m_FallState = nullptr;
	}
	if (m_BulletManager != nullptr)
	{
		delete m_BulletManager;
		m_BulletManager = nullptr;
	}
	m_CurrentState = nullptr;
}

std::vector<SoLoud::Wav>* Character::GetListSound()
{
	return &m_listSound;
}
void Character::SetPos(Vector2 newPos)
{
	m_Pos = newPos;
}

Vector2* Character::GetPos()
{
	return &m_Pos;
}
bool* Character::GetisTouch()
{
	return &m_isTouchTheGround;
}
int* Character::GetSpeed()
{
	return &m_Speed;
}
int* Character::GetKeyPress()
{
	return &m_KeyPress;
}
BulletManager* Character::GetBulletManager()
{
	return m_BulletManager;
}
ICState::STATE_Action* Character::GetCurrentAction()
{
	return &m_CurrentAction;
}

void Character::SetAction(ICState::STATE_Action stt)
{
	if (m_Locked == stt) return;
	m_Locked = stt;
	m_CurrentState->ResetAnimation();

	switch (stt)
	{
	case ICState::STATE_Idle:
		m_CurrentState->Idle();
		break;
	case ICState::STATE_Run:
		m_CurrentState->Run();
		break;
	case ICState::STATE_Death:
		m_CurrentState->Death();
		break;
	case ICState::STATE_Jump:
		m_CurrentState->Jump();
		break;
	case ICState::STATE_Dash:
		m_CurrentState->Dash();
		break;
	case ICState::STATE_Attack:
		m_CurrentState->Attack();
		break;
	case ICState::STATE_Fall:
		m_CurrentState->Fall();
		break;
	default:
		break;
	}
}

void Character::SetState()
{
	m_CurrentState->SetState();
}

void Character::SetState(ICState* newState)
{
	m_CurrentState = newState;
}

void Character::Init()
{

}
void Character::Draw()
{
	m_BulletManager->Draw();
	m_CurrentState->Draw();
}
void Character::Update(float deltaTime)
{
	if (m_Alive) SetAction(m_CurrentAction);
	else
	{
		SetAction(ICState::STATE_Death);
	}
	m_BulletManager->Update(deltaTime);
	m_CurrentState->Update(deltaTime);
	Entity::SetPos(m_Pos);
}

ICState* Character::GetState() 
{
	return m_CurrentState;
}
ICState* Character::GetJumpState()
{
	return m_JumpState;
}
ICState* Character::GetAttackState()
{
	return m_AttackState;
}
ICState* Character::GetDeathState()
{
	return m_DeathState;
}
ICState* Character::GetDashState()
{
	return m_DashState;
}
ICState* Character::GetIdleState()
{
	return m_IdleState;
}
ICState* Character::GetRunState()
{
	return m_RunState;
}
ICState* Character::GetFallState()
{
	return m_FallState;
}

