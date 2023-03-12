#include "HurtBState.h"


HurtBState::HurtBState(IBoss* boss)
{
	m_Boss = boss;
	m_currentTime = 0.0f;
}

void HurtBState::Init(std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture(nameFile);
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	m_Image = std::make_shared<AnimationSprite>(model, shader, texture, numFrames, frameTime);
	m_Image->Set2DPosition(pos);
	float scale = *m_Boss->GetNumScale();
	m_Image->SetSize(width * scale, height * scale);
}

void HurtBState::Draw()
{
	m_Image->Draw();
}

void HurtBState::Update(float deltaTime)
{
	Vector2* pos = m_Boss->GetPos();
	m_Image->Update(deltaTime);
	m_Image->Set2DPosition(*pos); m_Image->Update(deltaTime);
}

void HurtBState::ResetAnimation()
{
	m_Image->ResetAnimation();
}
