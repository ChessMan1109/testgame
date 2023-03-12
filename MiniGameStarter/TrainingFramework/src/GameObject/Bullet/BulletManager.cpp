#include "Bullet/BulletManager.h"

BulletManager::BulletManager(int numBullet)
{
	while(numBullet--)
	{
		auto temp= std::make_shared<Bullet>();
		m_listBullet.push_back(temp);
	}

}
BulletManager::~BulletManager()
{

}
void BulletManager::Init(Bullet::STATE_Bullet stt, std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture(nameFile);
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	for (auto it : m_listBullet)
	{
		it->InitForList(model,shader,texture,stt, numFrames, frameTime, width, height, pos);
	}
}

void BulletManager::SetTag(Entity::Tag newTag)
{
	for (auto it : m_listBullet)
	{
		it->SetTag(newTag);
	}
}

void BulletManager::Fire(Vector2 newPos)
{
	for (auto it : m_listBullet)
	{
		if (it->CheckUsed()==false)
		{
			it->SetResetPos(newPos);
			it->Switch();
			break;
		}
	}
}

void BulletManager::Fire()
{
	for (auto it : m_listBullet)
	{
		if (it->CheckUsed() == false)
		{
			it->Switch();
			break;
		}
	}
}

void BulletManager::Draw()
{
	for (auto it : m_listBullet)
	{
		if (it->CheckUsed()) it->Draw();
	}
}

void BulletManager::Update(float deltaTime)
{
	for (auto it : m_listBullet)
	{
		if (it->CheckUsed()) it->Update(deltaTime);
	}
}

std::list<std::shared_ptr<Bullet> >BulletManager::GetlistBullet()
{
	return m_listBullet;
}
