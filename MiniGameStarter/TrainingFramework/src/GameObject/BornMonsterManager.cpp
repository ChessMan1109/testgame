#include "BornMonsterManager.h"

BornMonsterManager::BornMonsterManager()
{
	m_EnemyRino = std::make_shared<EnemyManager>(20);
	m_EnemyBat = std::make_shared<EnemyManager>(20);
	m_BornTime = 2.0f;
	m_deltaSpeed = 10;
	m_CurrentTime = 0.0f;
	m_NumMonster = 1;
}

BornMonsterManager::~BornMonsterManager()
{

}
void BornMonsterManager::Update(float deltaTime)
{
	m_BornTime = Application::GetInstance()->m_LevelGame.GetBornMonsterTime();
	m_NumMonster = Application::GetInstance()->m_LevelGame.GetNumMonster();
	m_CurrentTime += deltaTime;
	if (m_CurrentTime > m_BornTime)
	{
		for (int i = 0; i < m_NumMonster; i++)
		{
			int x = rand() % 2;
			switch (x)
			{
			case 0:
				m_EnemyRino->Fire();
				break;
			case 1:
				m_EnemyBat->Fire();
				break;
			default:
				break;
			}
		}
		m_CurrentTime = 0.0f;

	}
	m_EnemyBat->Update(deltaTime);
	m_EnemyRino->Update(deltaTime);
	
}

void BornMonsterManager::Draw()
{
	m_EnemyBat->Draw();
	m_EnemyRino->Draw();
}

std::shared_ptr<EnemyManager> BornMonsterManager::GetEnemyRino()
{
	return m_EnemyRino;
}
std::shared_ptr<EnemyManager> BornMonsterManager::GetEnemyBat()
{
	return m_EnemyBat;
}
