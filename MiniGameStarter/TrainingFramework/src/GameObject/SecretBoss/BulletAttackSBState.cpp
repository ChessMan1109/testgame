#include "SecretBoss/BulletAttackSBState.h"


BulletAttackSBState::BulletAttackSBState(ISecretBoss* boss)
{
	m_Boss = boss;
}
void BulletAttackSBState::Init(std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture(nameFile);
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	m_Image = std::make_shared<AnimationSprite>(model, shader, texture, numFrames, frameTime);
	m_Image->Set2DPosition(pos);
	float scale = *m_Boss->GetNumScale();
	m_Image->SetSize(width * scale, height * scale);
}

void BulletAttackSBState::Draw()
{
	m_Image->Draw();
}

void BulletAttackSBState::Update(float deltaTime)
{
	if (m_isAllowOverFrameStop == true)
	{
		m_Image->UpdateType2(deltaTime, m_isAllowOverFrameStop, m_isStopAni, 1);
		if (m_isStopAni == true)
		{
			*m_Boss->GetCurrentAction() = ISBState::STATE_MOVE_Right;
			ResetAnimation();
			return;
		}
	}
	else
	{
		m_Image->UpdateType2(deltaTime, m_isAllowOverFrameStop, m_isStopAni, 1);
	}
	m_Image->Set2DPosition(*m_Boss->GetPos());
}
void BulletAttackSBState::ResetAnimation()
{
	m_Image->ResetAnimation();
	m_isAllowOverFrameStop = false;
	m_isStopAni = false;
}

