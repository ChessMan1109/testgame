#include "Flame.h"

Flame::Flame()
{
	m_Tag = Entity::Tag_BossFlame;
}
Flame::~Flame()
{

}
void Flame::Update(float deltaTime)
{
	m_State = m_ChangeState;

	if (m_State == STATE_Bullet::STATE_Impact)
	{
		if (m_ListImage[m_State]->GetCurrentFrame() < m_ListImage[m_State]->GetNumFrame() - 1)
		{
			m_ListImage[m_State]->Update(deltaTime);
		}
		else
		{
			m_ChangeState = STATE_Bullet::STATE_Spit;
			ResetBullet();
		}
	}
	else
	{
		m_Pos.y += m_Speed * deltaTime;
		if (m_Pos.y > 400 || m_Alive == false)
		{
			m_ChangeState = STATE_Bullet::STATE_Impact;
			int handle=Application::GetInstance()->gb_soloud.play(ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SE_DeathFlash));
			Application::GetInstance()->gb_soloud.setVolume(handle,3.0f);
			m_isAllowImpact = false;
		}
		m_ListImage[m_State]->Update(deltaTime);
	}
	m_ListImage[m_State]->Set2DPosition(m_Pos);
}
