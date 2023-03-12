#pragma once
#include "gamestatebase.h"
#include "Character/Character.h"
#include "Player.h"
#include "Boss/Boss.h"
#include "SecretBoss/SecretBoss.h"
#include "keyBoard.h"
#include "Bullet/BulletManager.h"
#include "CheckCollision.h"
#include "BornMonsterManager.h"
#include "soloud_wav.h"
#include "Application.h"
#include "GameButton.h"

class GSPlay :
	public GameStateBase
{
public:
	GSPlay();
	~GSPlay();

	void Init();
	void Exit();

	void Pause();
	void Resume();

	void HandleEvents();
	void HandleKeyEvents(int key, bool bIsPressed);

	void HandleTouchEvents(int x, int y, bool bIsPressed);
	void Update(float deltaTime);
	void Draw();


	void SetNewPostionForBullet();

private:
	std::shared_ptr<Player> m_Character;
	std::shared_ptr<SecretBoss> m_SecretBoss;
	std::shared_ptr<Boss> m_Boss;
	std::shared_ptr<Text>  m_score;
	std::shared_ptr<ParallelBackground> m_BgUnder;
	std::shared_ptr<ParallelBackground> m_BgMid;
	std::shared_ptr<ParallelBackground> m_BgAbove;
	std::shared_ptr<KeyBoard> m_keyB;
	std::shared_ptr<CheckCollision> m_CollitionChecker;
	std::shared_ptr<BornMonsterManager> m_BornMonsterManager;

	long long m_CurrentScore;
	long long m_Count;
	float m_CurrentTime;
	float m_countTimeIntro;
	bool m_CheckSound;
};