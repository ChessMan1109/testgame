#pragma once
#include "ResourceManagers.h"
class LevelGame
{
public:
	typedef struct {
		float m_SecretBossTime;
		float m_BornMonsterTime;
		int m_numMonster;
		float m_TimeSpitFlame;
	} DataLevel;
	
	LevelGame();
	~LevelGame();

	void LevelUp();
	void ReLevel();
	void SetLevel(int x);
	float GetBornMonsterTime();
	float GetSBossTime();
	int GetNumMonster();
	float GetTimeSpitFlame();
private:
	std::vector<DataLevel> m_LevelGame;
	int m_currentLevel;
	DataLevel m_Level;
};