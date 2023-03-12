#include "LevelGame.h"

LevelGame::LevelGame()
{
	m_LevelGame.resize(5);
	m_currentLevel = 0;
	m_LevelGame[0].m_BornMonsterTime = 3.0f;
	m_LevelGame[0].m_SecretBossTime = 3.0f;
	m_LevelGame[0].m_numMonster = 1;
	m_LevelGame[0].m_TimeSpitFlame = 0.03f;

	m_LevelGame[1].m_BornMonsterTime = 3.0f;
	m_LevelGame[1].m_SecretBossTime = 2.0f;
	m_LevelGame[1].m_numMonster = 1;
	m_LevelGame[1].m_TimeSpitFlame = 0.03f;

	m_LevelGame[2].m_BornMonsterTime = 2.0f;
	m_LevelGame[2].m_SecretBossTime = 1.0f;
	m_LevelGame[2].m_numMonster = 1;
	m_LevelGame[2].m_TimeSpitFlame = 0.01f;

	m_LevelGame[3].m_BornMonsterTime = 1.0f;
	m_LevelGame[3].m_SecretBossTime = 0.5f;
	m_LevelGame[3].m_numMonster = 2;
	m_LevelGame[3].m_TimeSpitFlame = 0.001f;

	m_LevelGame[4].m_BornMonsterTime = 0.5f;
	m_LevelGame[4].m_SecretBossTime = 0.1f;
	m_LevelGame[4].m_numMonster = 2;
	m_LevelGame[4].m_TimeSpitFlame = 0.00001f;
}

LevelGame::~LevelGame()
{

}

void LevelGame::LevelUp()
{
	if (m_currentLevel <4)
	{
		m_currentLevel++;
	}
}

float LevelGame::GetBornMonsterTime()
{
	return m_LevelGame[m_currentLevel].m_BornMonsterTime;
}
float LevelGame::GetSBossTime()
{
	return m_LevelGame[m_currentLevel].m_SecretBossTime;
}
int LevelGame::GetNumMonster()
{
	return m_LevelGame[m_currentLevel].m_numMonster;
}
void LevelGame::ReLevel()
{
	m_currentLevel = 0;
}
void LevelGame::SetLevel(int x)
{
	m_currentLevel = x;
}
float LevelGame::GetTimeSpitFlame()
{
	return  m_LevelGame[m_currentLevel].m_TimeSpitFlame;
}
