#include "JumpBiteBState.h"


JumpBiteBState::JumpBiteBState(IBoss* boss)
{
	m_Boss = boss;
	m_sound = false;
	m_sound2 = false;
}

void JumpBiteBState::Init(std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture(nameFile);
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	m_Image = std::make_shared<AnimationSprite>(model, shader, texture, numFrames, frameTime);
	m_Image->Set2DPosition(pos);
	float scale = *m_Boss->GetNumScale();
	m_Image->SetSize(width * scale, height * scale);
}

void JumpBiteBState::Draw()
{
	m_Image->Draw();
}
extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

#define PLANE screenHeight-68
void JumpBiteBState::Update(float deltaTime)
{
	int speed = *m_Boss->GetSpeed();
	Vector2* pos = m_Boss->GetPos();
	int handle;
	m_Image->Set2DPosition(*pos);
	if (m_Image->GetCurrentFrame() > 1 )
	{
		if (m_sound == false)
		{
			handle=Application::GetInstance()->gb_soloud.play(ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SE_MonsterGr));
			Application::GetInstance()->gb_soloud.setPan(handle, -1.0f);
			m_sound = true;
		}
	}
	if (m_Image->GetCurrentFrame() > 13)
	{
		if (m_sound2 == false)
		{
			handle=Application::GetInstance()->gb_soloud.play(ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SE_Explosion));
			Application::GetInstance()->gb_soloud.setPan(handle, -1.0f);
			Application::GetInstance()->gb_soloud.setVolume(handle, 0.5f);
			m_sound2 = true;
		}
	}
	if (m_isAllowOverFrameStop == true)
	{
		m_Image->UpdateType2(deltaTime, m_isAllowOverFrameStop, m_isStopAni, 14);
		if (pos->x - 200 * deltaTime > -50)
		{
			pos->x -= 200 * deltaTime;
		}
		if (m_isStopAni == true)
		{
			if (pos->x>=300)
			{
				*m_Boss->GetCurrentAction() = IBState::STATE_Posion_Attack;
			}
			else
			{
				int x = 3 + rand() % 3;
				switch (x)
				{
				case IBState::STATE_Posion_Attack:
					*m_Boss->GetCurrentAction() = IBState::STATE_Posion_Attack;
					break;
				case IBState::STATE_Jump:
					*m_Boss->GetCurrentAction() = IBState::STATE_Jump;
					break;
				case IBState::STATE_Jump_Bite:
					*m_Boss->GetCurrentAction() = IBState::STATE_Jump_Bite;
					break;
				default:
					break;
				}
			}
			m_Image->ResetAnimation();
			m_isAllowOverFrameStop = false;
			m_isStopAni = false;
			m_sound = false;
			m_sound2 = false;
		}
	}
	else
	{
		m_isAllowOverFrameStop = false;
		m_Image->UpdateType2(deltaTime, m_isAllowOverFrameStop, m_isStopAni, 14);
		if (pos->x + 100 * deltaTime < 300)
		{
			pos->x += 100 * deltaTime;
		}
	}

}

void JumpBiteBState::ResetAnimation()
{
	m_Image->ResetAnimation();
}
