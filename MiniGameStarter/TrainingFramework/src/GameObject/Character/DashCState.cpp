#include "DashCState.h"


DashCState::DashCState(ICharacter* character)
{
	m_Character = character;
	m_currentTime = 0.0f;
	m_Sound = false;
}

void DashCState::Init(std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture(nameFile);
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	m_Image = std::make_shared<AnimationSprite>(model, shader, texture, numFrames, frameTime);
	m_Image->Set2DPosition(pos);
	m_Image->SetSize(width, height);
}
void DashCState::Draw()
{
	m_Image->Draw();
}

void DashCState::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	int keyPress = *m_Character->GetKeyPress();
	int speed = *m_Character->GetSpeed();
	Vector2* pos = m_Character->GetPos();

	if (m_isAllowOverFrameStop == true)
	{
		/*
		*m_Character->GetCurrentAction() = ICState::STATE_Run;
		return;
		*/
		if (m_Sound == false)
		{
			Application::GetInstance()->gb_soloud.play(ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SE_Fall));
			m_Sound = true;
		}
		m_Image->UpdateType2(5 * deltaTime, m_isAllowOverFrameStop, m_isStopAni, 2);
		if (m_isStopAni == true)
		{
			*m_Character->GetCurrentAction() = ICState::STATE_Run;
			m_isAllowOverFrameStop = false;
			m_isStopAni = false;
			m_Sound = false;
			m_currentTime = 0.0f;
		}
	}
	else
	{
		if (keyPress & KeyBoard::DKEY_RIGHT)
		{
			pos->x += speed * deltaTime;
		}
		else if (keyPress & KeyBoard::DKEY_LEFT)
		{
			pos->x -= speed * deltaTime;
		}

		m_isAllowOverFrameStop = *m_Character->GetisTouch();

		m_Image->UpdateType2(deltaTime, m_isAllowOverFrameStop, m_isStopAni, 2);

		m_isAllowOverFrameStop = *m_Character->GetisTouch();
	}

	float ups = 4.0f;
	float s = ups * (speed + 98 * ups * (m_currentTime * m_currentTime / 2.0f)) * deltaTime;
	if (pos->y + s >= PLANE)
	{
		pos->y = PLANE;
		m_currentTime = 0.0f;
	}
	else
	{
		pos->y += s;
	}
	m_Image->Set2DPosition(*pos);
}

void DashCState::ResetAnimation()
{
	m_Image->ResetAnimation();
}

void DashCState::Jump()
{
	m_Character->SetState(m_Character->GetJumpState());
}
void DashCState::Attack()
{
	m_Character->SetState(m_Character->GetAttackState());
}
void DashCState::Death()
{
	m_Character->SetState(m_Character->GetDeathState());
}
void DashCState::Dash()
{
	m_Character->SetState(m_Character->GetDashState());
}
void DashCState::Idle()
{
	m_Character->SetState(m_Character->GetIdleState());
}
void DashCState::Run()
{
	m_Character->SetState(m_Character->GetRunState());
}
void DashCState::Fall()
{
	m_Character->SetState(m_Character->GetFallState());
}