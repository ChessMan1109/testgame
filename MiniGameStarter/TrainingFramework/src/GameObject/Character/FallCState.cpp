#include "FallCState.h"


FallCState::FallCState(ICharacter* character)
{
	m_Character = character;
	m_isStopAni = false;
	m_isAllowOverFrameStop = false;
	m_currentTime = 0.0f;
	m_soundFall = false;
}

void FallCState::Init(std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture(nameFile);
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	m_Image = std::make_shared<AnimationSprite>(model, shader, texture, numFrames, frameTime);
	m_Image->Set2DPosition(pos);
	m_Image->SetSize(width, height);
}
void FallCState::Draw()
{
	m_Image->Draw();
}



void FallCState::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	int keyPress = *m_Character->GetKeyPress();
	int speed = *m_Character->GetSpeed();
	Vector2* pos = m_Character->GetPos();

	if (m_isAllowOverFrameStop==true)
	{
		/*
		*m_Character->GetCurrentAction() = ICState::STATE_Run;
		return;
		*/
		if (m_soundFall == false)
		{
			Application::GetInstance()->gb_soloud.play(ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SE_Fall));
			m_soundFall = true;
		}
		m_Image->UpdateType2(5*deltaTime, m_isAllowOverFrameStop, m_isStopAni, 2);
		if (m_isStopAni == true)
		{
			*m_Character->GetCurrentAction() = ICState::STATE_Run;

			m_isAllowOverFrameStop = false;
			m_isStopAni = false;
			m_soundFall = false;
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
		if (keyPress & KeyBoard::DKEY_DOWN)
		{
			*m_Character->GetCurrentAction() = ICState::STATE_Dash;
		}
		m_isAllowOverFrameStop = *m_Character->GetisTouch();

		m_Image->UpdateType2(deltaTime, m_isAllowOverFrameStop, m_isStopAni, 2);

		m_isAllowOverFrameStop = *m_Character->GetisTouch();
	}

	float ups = 2.5f;
	float s= ups*(speed+98*ups* (m_currentTime * m_currentTime / 2.0f)) * deltaTime;
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

void FallCState::ResetAnimation()
{
	m_Image->ResetAnimation();
	m_isStopAni = false;
	m_isAllowOverFrameStop = false;
}

void FallCState::Jump()
{
	m_Character->SetState(m_Character->GetJumpState());
}
void FallCState::Attack()
{
	m_Character->SetState(m_Character->GetAttackState());
}
void FallCState::Death()
{
	m_Character->SetState(m_Character->GetDeathState());
}
void FallCState::Dash()
{
	m_Character->SetState(m_Character->GetDashState());
}
void FallCState::Idle()
{
	m_Character->SetState(m_Character->GetIdleState());
}
void FallCState::Run()
{
	m_Character->SetState(m_Character->GetRunState());
}
void FallCState::Fall()
{
	m_Character->SetState(m_Character->GetFallState());
}