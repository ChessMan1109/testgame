#include "SecretBoss/MoveLeftSBState.h"


MoveLeftSBState::MoveLeftSBState(ISecretBoss* boss)
{
	m_Boss = boss;
	m_CurrentTime = 0.0f;
}
void MoveLeftSBState::Init(std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture(nameFile);
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	m_Image = std::make_shared<AnimationSprite>(model, shader, texture, numFrames, frameTime);
	m_Image->Set2DPosition(pos);
	float scale = *m_Boss->GetNumScale();
	m_Image->SetSize(width * scale, height * scale);
}

void MoveLeftSBState::Draw()
{
	m_Image->Draw();
}

void MoveLeftSBState::Update(float deltaTime)
{
	Vector2* pos = m_Boss->GetPos();
	m_CurrentTime += deltaTime;
	if (m_CurrentTime > Application::GetInstance()->m_LevelGame.GetSBossTime())
	{
		*m_Boss->GetCurrentAction() = ISBState::STATE_Laze_Attack;
		ResetAnimation();
	}
	m_Image->Update(deltaTime);
	m_Image->Set2DPosition(*pos);
}

void MoveLeftSBState::ResetAnimation()
{
	m_Image->ResetAnimation();
	m_CurrentTime = 0.0f;
}
