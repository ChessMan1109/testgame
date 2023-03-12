#include "FlameManager.h"

FlameManager::FlameManager(int numBullet)
{
	while (numBullet--)
	{
		auto temp = std::make_shared<Flame>();
		m_listBullet.push_back(temp);
	}

}
FlameManager::~FlameManager()
{

}
void FlameManager::Init(Flame::STATE_Bullet stt, std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture(nameFile);
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	for (auto it : m_listBullet)
	{
		it->InitForList(model, shader, texture, stt, numFrames, frameTime, width, height, pos);
	}
}

void FlameManager::SetTag(Entity::Tag newTag)
{
	for (auto it : m_listBullet)
	{
		it->SetTag(newTag);
	}
}

void FlameManager::Fire(Vector2 newPos)
{
	for (auto it : m_listBullet)
	{
		if (it->CheckUsed() == false)
		{
			it->SetResetPos(newPos);
			it->Switch();
			break;
		}
	}
}

void FlameManager::Fire()
{
	for (auto it : m_listBullet)
	{
		if (it->CheckUsed() == false)
		{
			it->Switch();
			it->SetPos(Vector2(200+(rand()%10)*40, 0));
			break;
		}
	}
}

void FlameManager::Draw()
{
	for (auto it : m_listBullet)
	{
		if (it->CheckUsed()) it->Draw();
	}
}

void FlameManager::Update(float deltaTime)
{
	for (auto it : m_listBullet)
	{
		if (it->CheckUsed()) it->Update(deltaTime);
	}
}

std::list<std::shared_ptr<Flame> >FlameManager::GetlistBullet()
{
	return m_listBullet;
}
