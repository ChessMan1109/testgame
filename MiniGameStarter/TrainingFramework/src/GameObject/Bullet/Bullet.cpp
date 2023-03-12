#include "Bullet.h"

Bullet::Bullet()
{
	m_Speed = 250;
	m_isUsed = false;
	m_Alive = false;
	m_State = STATE_Bullet::STATE_Spit;
	m_ChangeState= STATE_Bullet::STATE_Spit;
	m_ListImage.resize(2);
}

Bullet::~Bullet()
{

}
void Bullet::Init(STATE_Bullet stt,std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos)
{

	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture(nameFile);
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	m_ListImage[stt] = std::make_shared<AnimationSprite>(model, shader, texture, numFrames, frameTime);
	m_ListImage[stt]->Set2DPosition(pos);
	m_ListImage[stt]->SetSize(width, height);
	m_ResetPos = pos;
	SetPos(pos);
	SetHeight(height);
	SetWidth(width);
}

void Bullet::InitForList(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture,
	STATE_Bullet stt, int numFrames, float frameTime, int width, int height, Vector2 pos)
{
	m_ListImage[stt] = std::make_shared<AnimationSprite>(model, shader, texture, numFrames, frameTime);
	m_ListImage[stt]->Set2DPosition(pos);
	m_ListImage[stt]->SetSize(width, height);
	m_ResetPos = pos;
	SetPos(pos);
	SetHeight(height);
	SetWidth(width);
}

void Bullet::Draw()
{
	m_ListImage[m_State]->Draw();
}

void Bullet::Update(float deltaTime)
{
	m_State = m_ChangeState;

	if (m_State == STATE_Bullet::STATE_Impact)
	{
		if (m_ListImage[m_State]->GetCurrentFrame()< m_ListImage[m_State]->GetNumFrame()-1)
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
		m_Pos.x+= m_Speed * deltaTime;
		if (m_Pos.x > 800||m_Alive==false)
		{
			m_ChangeState = STATE_Bullet::STATE_Impact;
			if (m_Tag == Tag::Tag_CharacterBullet)
			{
				Application::GetInstance()->gb_soloud.play(ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SE_ArrowHit));
			}
			else if (m_Tag == Tag::Tag_BossBullet)
			{
				Application::GetInstance()->gb_soloud.play(ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SE_PoistionBoom));
			}
		}
		m_ListImage[m_State]->Update(deltaTime);
	}
	m_ListImage[m_State]->Set2DPosition(m_Pos);
	
}

void Bullet::ResetBullet()
{
	m_Pos = m_ResetPos;
	m_ListImage[STATE_Bullet::STATE_Impact]->ResetAnimation();
	m_ListImage[STATE_Bullet::STATE_Spit]->Set2DPosition(m_ResetPos);
	m_isUsed = false;
	m_Alive = false;
	m_isAllowImpact = true;
}

bool Bullet::CheckUsed()
{
	return m_isUsed;
}

void Bullet::SetResetPos(Vector2 newPos)
{
	m_ResetPos = newPos;
	m_Pos = newPos;
}