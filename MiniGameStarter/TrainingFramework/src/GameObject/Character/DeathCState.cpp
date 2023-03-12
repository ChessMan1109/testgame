#include "DeathCState.h"
#include "Application.h"

DeathCState::DeathCState(ICharacter* character)
{
	m_Character = character;
	m_currentTime = 0;
	m_sound = false;
}

void DeathCState::Init(std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture(nameFile);
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	m_Image = std::make_shared<AnimationSprite>(model, shader, texture, numFrames, frameTime);
	m_Image->Set2DPosition(pos);
	m_Image->SetSize(width, height);
}
void DeathCState::Draw()
{
	m_Image->Draw();
}

void DeathCState::Update(float deltaTime)
{
	if (m_sound == false)
	{
		Application::GetInstance()->gb_soloud.play(ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SE_PlayerDeath));
		m_sound = true;
	}
	m_currentTime += deltaTime;
	int speed = *m_Character->GetSpeed();
	Vector2* pos = m_Character->GetPos();
	float ups = 2.5f;
	float s = ups * (speed + 98 * ups * (m_currentTime * m_currentTime / 2.0f)) * deltaTime;
	if (pos->y + s >= 480-68)
	{
		pos->y = 480 - 68;
		m_currentTime = 0.0f;
	}
	else
	{
		pos->y += s;
	}
	if (m_Image->GetCurrentFrame() < m_Image->GetNumFrame() - 1)
	{
		m_Image->Update(deltaTime);
	}
	else Application::GetInstance()->isEndGame = true;
	m_Image->Set2DPosition(*pos);
	
}

void DeathCState::ResetAnimation()
{
	m_Image->ResetAnimation();
}

void DeathCState::Jump()
{
	m_Character->SetState(m_Character->GetJumpState());
}
void DeathCState::Attack()
{
	m_Character->SetState(m_Character->GetAttackState());
}
void DeathCState::Death()
{
	m_Character->SetState(m_Character->GetDeathState());
}
void DeathCState::Dash()
{
	m_Character->SetState(m_Character->GetDashState());
}
void DeathCState::Idle()
{
	m_Character->SetState(m_Character->GetIdleState());
}
void DeathCState::Run()
{
	m_Character->SetState(m_Character->GetRunState());
}
void DeathCState::Fall()
{
	m_Character->SetState(m_Character->GetFallState());
}