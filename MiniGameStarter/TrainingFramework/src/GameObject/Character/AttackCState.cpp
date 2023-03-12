#include "AttackCState.h"


AttackCState::AttackCState(ICharacter* character)
{
	m_Character = character;
	LockedFrame = true;
}

void AttackCState::Init(std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture(nameFile);
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	m_Image = std::make_shared<AnimationSprite>(model, shader, texture, numFrames, frameTime);
	m_Image->Set2DPosition(pos);
	m_Image->SetSize(width, height);
}
void AttackCState::Draw()
{
	m_Image->Draw();
}

void AttackCState::Update(float deltaTime)
{
	int speed = *m_Character->GetSpeed();
	Vector2* pos = m_Character->GetPos();

	if (m_isAllowOverFrameStop == true)
	{
		if (m_isFire == false)
		{
			m_Character->GetBulletManager()->Fire(*pos);
			Application::GetInstance()->gb_soloud.play(m_Character->GetListSound()->at(Sound::Sound_Shoot));
			m_isFire = true;
		}
		m_Image->UpdateType2(deltaTime, m_isAllowOverFrameStop, m_isStopAni, 10);
		if (m_isStopAni == true)
		{
			if (*m_Character->GetisTouch()==false) *m_Character->GetCurrentAction() = ICState::STATE_Fall;
			else *m_Character->GetCurrentAction() = ICState::STATE_Run;
			ResetAnimation();
			return;
		}
	}
	else
	{
		m_Image->UpdateType2(deltaTime, m_isAllowOverFrameStop, m_isStopAni, 10);
	}

	m_Image->Set2DPosition(*pos);
}

void AttackCState::ResetAnimation()
{
	m_Image->ResetAnimation();
	m_isAllowOverFrameStop = false;
	m_isStopAni = false;
	m_isFire = false;
}

void AttackCState::Jump()
{
	m_Character->SetState(m_Character->GetJumpState());
}
void AttackCState::Attack()
{
	m_Character->SetState(m_Character->GetAttackState());
}
void AttackCState::Death()
{
	m_Character->SetState(m_Character->GetDeathState());
}
void AttackCState::Dash()
{
	m_Character->SetState(m_Character->GetDashState());
}
void AttackCState::Idle()
{
	m_Character->SetState(m_Character->GetIdleState());
}
void AttackCState::Run()
{
	m_Character->SetState(m_Character->GetRunState());
}
void AttackCState::Fall()
{
	m_Character->SetState(m_Character->GetFallState());
}