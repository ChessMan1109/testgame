#pragma once
#include "EnemyManager.h"
#include "Application.h"

class BornMonsterManager
{
public:
	BornMonsterManager();
	~BornMonsterManager();
	void Update(float deltaTime);
	void Draw();
	std::shared_ptr<EnemyManager> GetEnemyRino();
	std::shared_ptr<EnemyManager> GetEnemyBat();


private:
	int m_deltaSpeed;
	float m_BornTime;
	float m_CurrentTime;
	int m_NumMonster;
	std::shared_ptr<EnemyManager> m_EnemyRino;
	std::shared_ptr<EnemyManager> m_EnemyBat;
	
};