#include "Enemy.h"

Enemy::Enemy()
{
	m_Speed = 250;
	m_Alive = false;
	m_isUsed = false;
	m_State = STATE_Enemy::STATE_Run;
	m_ChangeState = STATE_Enemy::STATE_Run;
	m_ListImage.resize(2);
}

Enemy::~Enemy()
{

}
void Enemy::Init(STATE_Enemy stt, std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos)
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

void Enemy::InitForList(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture,
	STATE_Enemy stt, int numFrames, float frameTime, int width, int height, Vector2 pos)
{
	m_ListImage[stt] = std::make_shared<AnimationSprite>(model, shader, texture, numFrames, frameTime);
	m_ListImage[stt]->Set2DPosition(pos);
	m_ListImage[stt]->SetSize(width, height);
	m_ResetPos = pos;
	SetPos(pos);
	SetHeight(height);
	SetWidth(width);
}

void Enemy::Draw()
{
	m_ListImage[m_State]->Draw();
}

void Enemy::Update(float deltaTime)
{
	m_State = m_ChangeState;

	if (m_State == STATE_Enemy::STATE_Hit)
	{
		if (m_ListImage[m_State]->GetCurrentFrame() < m_ListImage[m_State]->GetNumFrame() - 1)
		{
			m_ListImage[m_State]->Update(deltaTime);
		}
		else
		{
			m_ChangeState = STATE_Enemy::STATE_Run;
			ResetEnemy();
		}
	}
	else
	{
		m_Pos.x -= m_Speed * deltaTime;
		if (m_Pos.x < -50 || m_Alive == false)
		{
			m_ChangeState = STATE_Enemy::STATE_Hit;
			if (m_Alive == false) {
				int handle = Application::GetInstance()->gb_soloud.play(ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SE_MonsterHurt));
				Application::GetInstance()->gb_soloud.setVolume(handle, 0.5f);
			}
			
		}
		m_ListImage[m_State]->Update(deltaTime);
	}
	m_ListImage[m_State]->Set2DPosition(m_Pos);

}

void Enemy::ResetEnemy()
{
	m_Pos = m_ResetPos;
	m_ListImage[STATE_Enemy::STATE_Hit]->ResetAnimation();
	m_ListImage[STATE_Enemy::STATE_Run]->Set2DPosition(m_ResetPos);
	m_Alive = false;
	m_isUsed = false;
}

bool Enemy::CheckUsed()
{
	return m_isUsed;
}

void Enemy::SetResetPos(Vector2 newPos)
{
	m_ResetPos = newPos;
	m_Pos = newPos;
}