#include "PosionAttackBState.h"

extern int screenHeight;

PosionAttackBState::PosionAttackBState(IBoss* boss)
{
	m_Boss = boss;
}
void PosionAttackBState::Init(std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture(nameFile);
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	m_Image = std::make_shared<AnimationSprite>(model, shader, texture, numFrames, frameTime);
	m_Image->Set2DPosition(pos);
	float scale = *m_Boss->GetNumScale();
	m_Image->SetSize(width*scale, height*scale);
}

void PosionAttackBState::Draw()
{
	m_Image->Draw();
}

void PosionAttackBState::Update(float deltaTime)
{
	int speed = *m_Boss->GetSpeed();
	Vector2* pos = m_Boss->GetPos();
	if (pos->x - 200 * deltaTime > -100)
	{
		pos->x -= 200 * deltaTime;
	}
	if (m_isAllowOverFrameStop == true)
	{
		if (m_isFire == false)
		{
			m_Boss->GetBulletManager()->Fire(Vector2(pos->x+100, screenHeight / 2 + 150));
			Application::GetInstance()->gb_soloud.play(ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SE_BossSpit));
			m_isFire = true;
		}
		m_Image->UpdateType2(deltaTime, m_isAllowOverFrameStop, m_isStopAni, 14);
		if (m_isStopAni == true)
		{	
			if (pos->x<200)
			{
				*m_Boss->GetCurrentAction() = IBState::STATE_Jump_Bite;
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
					*m_Boss->GetCurrentAction() = IBState::STATE_Jump;
					break;
				}
			}
			ResetAnimation();
			return;
		}
	}
	else
	{
		m_Image->UpdateType2(deltaTime, m_isAllowOverFrameStop, m_isStopAni, 14);
	}
	
	m_Image->Set2DPosition(*pos);
}

void PosionAttackBState::ResetAnimation()
{
	m_Image->ResetAnimation();
	m_isAllowOverFrameStop = false;
	m_isStopAni = false;
	m_isFire = false;
}
