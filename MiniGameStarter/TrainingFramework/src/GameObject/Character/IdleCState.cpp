#include "IdleCState.h"


IdleCState::IdleCState(ICharacter* character)
{
	m_Character = character;
}

void IdleCState::Init(std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture(nameFile);
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	m_Image = std::make_shared<AnimationSprite>(model, shader, texture, numFrames, frameTime);
	m_Image->Set2DPosition(pos);
	m_Image->SetSize(width, height);
}
void IdleCState::Draw()
{

	m_Image->Draw();
}

void IdleCState::Update(float deltaTime)
{
	m_Image->Set2DPosition(*m_Character->GetPos());
	m_Image->Update(deltaTime);
}
void IdleCState::ResetAnimation()
{
	m_Image->ResetAnimation();
}

void IdleCState::Jump()
{
	m_Character->SetState(m_Character->GetJumpState());
}
void IdleCState::Attack()
{
	m_Character->SetState(m_Character->GetAttackState());
}
void IdleCState::Death()
{
	m_Character->SetState(m_Character->GetDeathState());
}
void IdleCState::Dash()
{
	m_Character->SetState(m_Character->GetDashState());
}
void IdleCState::Idle()
{
	m_Character->SetState(m_Character->GetIdleState());
}
void IdleCState::Run()
{
	m_Character->SetState(m_Character->GetRunState());
}
void IdleCState::Fall()
{
	m_Character->SetState(m_Character->GetFallState());
}