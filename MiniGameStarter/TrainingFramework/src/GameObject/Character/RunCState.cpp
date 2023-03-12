#include "RunCState.h"


RunCState::RunCState(ICharacter* character)
{
	m_Character = character;
}

void RunCState::Init(std::string nameFile, int numFrames, float frameTime, int width, int height,Vector2 pos)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture(nameFile);
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	m_Image = std::make_shared<AnimationSprite>(model, shader, texture, numFrames, frameTime);
	m_Image->Set2DPosition(pos);
	m_Image->SetSize(width, height);
}
void RunCState::Draw()
{
	m_Image->Draw();
}

void RunCState::Update(float deltaTime)
{
	
	int keyPress = *m_Character->GetKeyPress();
	int speed = *m_Character->GetSpeed();
	Vector2 *pos = m_Character->GetPos();
	
	if (keyPress & KeyBoard::DKEY_RIGHT)
	{
		pos->x += speed * deltaTime;
	}
	else if (keyPress & KeyBoard::DKEY_LEFT)
	{
		pos->x -= speed * deltaTime;
	}

	m_Image->Set2DPosition(*pos);

	if (keyPress & KeyBoard::DKEY_UP)
	{
		*m_Character->GetCurrentAction() = ICState::STATE_Jump;
		Application::GetInstance()->gb_soloud.play(ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SE_JumpLand));
	}
	else if (keyPress & KeyBoard::DKEY_FIRE)
	{
		*m_Character->GetCurrentAction() = ICState::STATE_Attack;
	}
	m_Image->Update(deltaTime);
}

void RunCState::ResetAnimation()
{
	m_Image->ResetAnimation();
}

void RunCState::Jump()
{
	m_Character->SetState(m_Character->GetJumpState());
}
void RunCState::Attack()
{
	m_Character->SetState(m_Character->GetAttackState());
}
void RunCState::Death()
{
	m_Character->SetState(m_Character->GetDeathState());
}
void RunCState::Dash()
{
	m_Character->SetState(m_Character->GetDashState());
}
void RunCState::Idle()
{
	m_Character->SetState(m_Character->GetIdleState());
}
void RunCState::Run()
{
	m_Character->SetState(m_Character->GetRunState());
}
void RunCState::Fall()
{
	m_Character->SetState(m_Character->GetFallState());
}