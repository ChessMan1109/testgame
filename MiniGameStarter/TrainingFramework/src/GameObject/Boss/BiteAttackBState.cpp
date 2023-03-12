#include "BiteAttackBState.h"


BiteAttackBState::BiteAttackBState(IBoss* boss)
{
	m_Boss = boss;
}

void BiteAttackBState::Init(std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture(nameFile);
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	m_Image = std::make_shared<AnimationSprite>(model, shader, texture, numFrames, frameTime);
	m_Image->Set2DPosition(pos);
	float scale = *m_Boss->GetNumScale();
	m_Image->SetSize(width * scale, height * scale);
}

void BiteAttackBState::Draw()
{
	m_Image->Draw();
}

void BiteAttackBState::Update(float deltaTime)
{
	int speed = *m_Boss->GetSpeed();
	Vector2* pos = m_Boss->GetPos();

	if (m_isAllowOverFrameStop == true)
	{
		m_Image->UpdateType2(deltaTime, m_isAllowOverFrameStop, m_isStopAni, 16);
		if (m_isStopAni == true)
		{
			*m_Boss->GetCurrentAction() = IBState::STATE_Jump_Bite;
			m_Image->ResetAnimation();
			m_isAllowOverFrameStop = false;
			m_isStopAni = false;
			return;
		}
	}
	else
	{
		m_isAllowOverFrameStop = false;
		m_Image->UpdateType2(deltaTime, m_isAllowOverFrameStop, m_isStopAni, 16);
	}

	m_Image->Set2DPosition(*pos);
}

void BiteAttackBState::ResetAnimation()
{
	m_Image->ResetAnimation();
}
