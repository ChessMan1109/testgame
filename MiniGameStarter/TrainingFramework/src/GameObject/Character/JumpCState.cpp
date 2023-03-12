#include "JumpCState.h"


JumpCState::JumpCState(ICharacter* character)
{
	m_Character = character;
	m_currentTime = 0.0f;
}

void JumpCState::Init(std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture(nameFile);
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	m_Image = std::make_shared<AnimationSprite>(model, shader, texture, numFrames, frameTime);
	m_Image->Set2DPosition(pos);
	m_Image->SetSize(width, height);
}

void JumpCState::Draw()
{
	m_Image->Draw();
}

void JumpCState::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	int keyPress = *m_Character->GetKeyPress();
	int speed = 100;
	Vector2* pos = m_Character->GetPos();
	//Drop
	float ups = 3.0f;
	float s =ups*(speed-98*ups * (m_currentTime * m_currentTime / 2.0f)) * deltaTime;

	if (s>=0)
	{
		pos->y -= s;
		bool isFall = false;
		m_Image->UpdateType2(deltaTime, isFall, isFall, 0);
	}
	else
	{
		m_currentTime = 0.0f;
		*m_Character->GetCurrentAction() = ICState::STATE_Fall;
	}

	if (keyPress & KeyBoard::DKEY_RIGHT)
	{
		pos->x += speed * deltaTime;
	}
	else if (keyPress & KeyBoard::DKEY_LEFT)
	{
		pos->x -= speed * deltaTime;
	}
	if (keyPress & KeyBoard::DKEY_FIRE)
	{
		*m_Character->GetCurrentAction() = ICState::STATE_Attack;
		m_currentTime = 0.0f;
	}else if (keyPress & KeyBoard::DKEY_DOWN)
	{
		*m_Character->GetCurrentAction() = ICState::STATE_Dash;
		m_currentTime = 0.0f;
	}
	m_Image->Set2DPosition(*pos);

}

void JumpCState::ResetAnimation()
{
	m_Image->ResetAnimation();
}

void JumpCState::Jump()
{
	m_Character->SetState(m_Character->GetJumpState());
}
void JumpCState::Attack()
{
	m_Character->SetState(m_Character->GetAttackState());
}
void JumpCState::Death()
{
	m_Character->SetState(m_Character->GetDeathState());
}
void JumpCState::Dash()
{
	m_Character->SetState(m_Character->GetDashState());
}
void JumpCState::Idle()
{
	m_Character->SetState(m_Character->GetIdleState());
}
void JumpCState::Run()
{
	m_Character->SetState(m_Character->GetRunState());
}
void JumpCState::Fall()
{
	m_Character->SetState(m_Character->GetFallState());
}