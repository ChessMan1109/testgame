#include "EnemyManager.h"

extern int screenHeight;
extern int screenWidth;

EnemyManager::EnemyManager(int numBullet)
{
	while (numBullet--)
	{
		auto temp = std::make_shared<Enemy>();
		m_listEnemy.push_back(temp);
	}

}
EnemyManager::~EnemyManager()
{

}
void EnemyManager::Init(Enemy::STATE_Enemy stt, std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture(nameFile);
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	for (auto it : m_listEnemy)
	{
		it->InitForList(model, shader, texture, stt, numFrames, frameTime, width, height, pos);
	}
}

void EnemyManager::SetTag(Entity::Tag newTag)
{
	for (auto it : m_listEnemy)
	{
		it->SetTag(newTag);
	}
}

void EnemyManager::Fire()
{
	for (auto it : m_listEnemy)
	{
		if (it->CheckUsed() == false)
		{
			it->Switch();
			if (it->GetTag() == Entity::Tag_EnemyBat) it->SetPos(Vector2(750, 100 + (rand()%5)*60));
			else
			{
				it->SetPos(Vector2(screenWidth+(rand()%4)*(100), screenHeight - 69));
			}
			break;
		}
	}
}

void EnemyManager::Draw()
{
	for (auto it : m_listEnemy)
	{
		if (it->CheckUsed()) it->Draw();
	}
}

void EnemyManager::Update(float deltaTime)
{
	for (auto it : m_listEnemy)
	{
		if (it->CheckUsed()) it->Update(deltaTime);
	}
}

std::list<std::shared_ptr<Enemy> >EnemyManager::GetlistEnemy()
{
	return m_listEnemy;
}
