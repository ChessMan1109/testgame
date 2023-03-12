#include "SecretBoss/LazeAttackSBState.h"


LazeAttackSBState::LazeAttackSBState(ISecretBoss* boss)
{
	m_Boss = boss;
	m_isFire = false;
	m_isAllowOverFrameStop = false;
	m_isStopAni = false;
	m_sound = false;
}

void LazeAttackSBState::Init(std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture(nameFile);
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	m_Image = std::make_shared<AnimationSprite>(model, shader, texture, numFrames, frameTime);
	m_Image->Set2DPosition(pos);
	float scale = *m_Boss->GetNumScale();
	m_Image->SetSize(width * scale, height * scale);
}

void LazeAttackSBState::Draw()
{
	m_Image->Draw();
}

void LazeAttackSBState::Update(float deltaTime)
{
	
	m_Image->SetFrameTime(Application::GetInstance()->m_LevelGame.GetTimeSpitFlame());
	if (m_isAllowOverFrameStop == true)
	{
		if (m_sound == false)
		{
			int handle = Application::GetInstance()->gb_soloud.play(ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SE_Laser));
			Application::GetInstance()->gb_soloud.setVolume(handle, 1.0f);
			//Application::GetInstance()->gb_soloud.play(ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SE_Laser));
			m_sound = true;
		}
	
		m_Image->UpdateType2(deltaTime, m_isAllowOverFrameStop, m_isStopAni, 1);
		if (m_isStopAni == true)
		{
			*m_Boss->GetCurrentAction() = ISBState::STATE_MOVE_Left;
			m_Boss->GetFlameManager()->Fire();
			ResetAnimation();
			m_sound = false;
			return;
		}
	}
	else
	{
		m_Image->UpdateType2(deltaTime, m_isAllowOverFrameStop, m_isStopAni, 1);
	}
	m_Image->Set2DPosition(*m_Boss->GetPos());
}
	
void LazeAttackSBState::ResetAnimation()
{
	m_Image->ResetAnimation();
	m_isAllowOverFrameStop = false;
	m_isStopAni = false;
}

