#include "GSPlay.h"

#include "Shaders.h"
#include "Texture.h"
#include "Models.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "AnimationSprite.h"
#include "Text.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSPlay::GSPlay()
{
	m_keyB = std::make_shared<KeyBoard>();
	m_Character = std::make_shared<Player>();
	m_Boss = std::make_shared<Boss>();
	m_SecretBoss = std::make_shared<SecretBoss>();
	m_CollitionChecker = std::make_shared<CheckCollision>();
	m_BornMonsterManager = std::make_shared<BornMonsterManager>();
	m_CurrentScore = 0;
	m_CurrentTime = 0;
	m_Count = 0;
	m_countTimeIntro = 0.0f;
	m_CheckSound = 0.0f;
}


GSPlay::~GSPlay()
{
	
}


void GSPlay::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");

	//BackGround
	m_BgUnder = std::make_shared<ParallelBackground>();
	m_BgMid = std::make_shared<ParallelBackground>();
	m_BgAbove = std::make_shared<ParallelBackground>();
	//BackGroundUnder
	m_BgUnder->Init("BackGround\\Bg1", 20);
	m_BgUnder->Init("BackGround\\Bg2", 60);
	m_BgUnder->Init("BackGround\\Bg3", 90);
	m_BgUnder->Init("BackGround\\Bg4", 120);
	m_BgUnder->Init("BackGround\\Bg5", 140);
	
	//m_Bg_Mid
	m_BgMid->Init("BackGround\\Bg6", 160);
	m_BgMid->Init("BackGround\\Bg7", 180);
	m_BgMid->Init("BackGround\\Bg8", 180);
	m_BgMid->Init("BackGround\\Bg9", 180);

	//BackGroundAbove
	
	m_BgAbove->Init("BackGround\\Bg10", 200);

	//text score
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Planes_ValMore");
	m_score = std::make_shared< Text>(shader, font, "0", TEXT_COLOR::WHITE, 1.0);
	m_score->Set2DPosition(Vector2(25, 50));

	//character
	m_Character->GetIdleState()->Init("main_char\\Idle_8_w27_h40t", 8, 0.1f, 27, 40, Vector2(100, screenHeight - 68));
	m_Character->GetAttackState()->Init("main_char\\Attack_14_w45_h39", 14, 0.0001f, 45, 39, Vector2(screenWidth / 2, screenHeight / 2));
	m_Character->GetDeathState()->Init("main_char\\Death_21_w62_h39t", 21, 0.1f, 62, 39, Vector2(screenWidth / 2, screenHeight / 2));
	m_Character->GetDashState()->Init("main_char\\Dash_13_w40_h42t", 13, 0.01f, 40, 42, Vector2(screenWidth / 2, screenHeight / 2));
	m_Character->GetRunState()->Init("main_char\\Run_7_w44_h35", 7, 0.05f, 44, 35, Vector2(screenWidth / 2, screenHeight -68));
	m_Character->GetJumpState()->Init("main_char\\Jumb_5_w36_h43", 5, 0.1f, 36, 43, Vector2(screenWidth / 2, screenHeight / 2));
	m_Character->GetFallState()->Init("main_char\\Fall_7_w36_h43", 7, 0.1f, 36, 43, Vector2(screenWidth / 2, screenHeight / 2));

	m_Character->SetAction(ICState::STATE_Fall);
	m_Character->SetPos(Vector2(screenWidth / 2, screenHeight / 2 + 29));
	m_Character->Entity::SetPos(Vector2(screenWidth / 2, screenHeight / 2 + 29));
	m_Character->Entity::SetWidth(36);
	m_Character->Entity::SetHeight(43);
	//Character Bullet
	m_Character->GetBulletManager()->Init(Bullet::STATE_Spit, "main_char\\arrow_spit_1_w23_h13", 1, 0.1f, 23, 13, *m_Character->GetPos());
	m_Character->GetBulletManager()->Init(Bullet::STATE_Impact, "main_char\\arrow_impact_5_w23_h13", 5, 0.1f, 23, 13, *m_Character->GetPos());

	m_CollitionChecker->PushBack(m_Character);
	for (auto it : m_Character->GetBulletManager()->GetlistBullet())
	{
		m_CollitionChecker->PushBack(it);
	}
	
	//boss
	m_Boss->SetNumScale(1.0f);
	m_Boss->GetBiteAttackState()->Init("Boss\\bite_attack_18_w231_h151", 19, 0.1f, 300, 224, Vector2(-150, 0));
	m_Boss->GetDeathState()->Init("Boss\\death_24_w177_h174t", 24, 0.1f, 300, 224, Vector2(-150, 0));
	m_Boss->GetFallState()->Init("Boss\\Jump_17_w296_h215", 17, 0.1f, 300, 224, Vector2(-150, 0));
	m_Boss->GetHurtState()->Init("Boss\\hurt_4_w173_h133", 4, 0.1f,  300, 224, Vector2(-150, 0));
	m_Boss->GetIdleState()->Init("Boss\\Idle_48_w170_h118", 48, 0.1f, 300, 224, Vector2(-150, 0));
	m_Boss->GetJumpBiteState()->Init("Boss\\jump_bite_17_w300_h224t", 17, 0.1f, 300, 224, Vector2(-150, 0));
	m_Boss->GetJumpState()->Init("Boss\\Jump_17_w296_h215", 17, 0.1f, 300, 224, Vector2(-150, 0));
	m_Boss->GetPosionState()->Init("Boss\\poison_attack_17_w180_h132", 17, 0.07f, 300, 224, Vector2(-150, 0));
	m_Boss->SetAction(IBState::STATE_Bite_Attack);
	m_Boss->SetPos(Vector2(-150, screenHeight / 2+90));
	m_Boss->Entity::SetPos(Vector2(-100, screenHeight / 2 + 90));
	m_Boss->Entity::SetWidth(200);
	m_Boss->Entity::SetHeight(150);
	//Boss Bullet
	m_Boss->GetBulletManager()->Init(Bullet::STATE_Impact, "Boss\\poison-impact_12_w47_h75", 12, 0.05f, 47 * 1.0f, 75 * 1.0f, Vector2(-150, screenHeight / 2 + 150));
	m_Boss->GetBulletManager()->Init(Bullet::STATE_Spit, "Boss\\poison-spit-12_w61_h20", 12, 0.05f, 61 * 1.0f, 20 * 1.0f, Vector2(-150, screenHeight / 2 + 150));
	m_CollitionChecker->PushBack(m_Boss);
	for (auto it : m_Boss->GetBulletManager()->GetlistBullet())
	{
		it->SetHeight(15);
		it->SetWidth(25);
		m_CollitionChecker->PushBack(it);
	}
	//secret
	m_SecretBoss->GetMoveLeftState()->Init("SecretBoss\\walk_19_w212_h1464t_2", 19, 0.03f, 212, 400, Vector2(screenWidth / 2, screenHeight / 2));
	m_SecretBoss->GetMoveRightState()->Init("SecretBoss\\walk_19_w212_h1464t_2", 19, 0.03f, 212, 400, Vector2(-200, screenHeight / 2));
	m_SecretBoss->GetLazeAttackState()->Init("SecretBoss\\walk_look_laze_19_w212_h1464t_2", 19, 0.03f, 212, 400, Vector2(screenWidth / 2, screenHeight / 2));
	m_SecretBoss->SetAction(ISBState::STATE_MOVE_Right);
	m_SecretBoss->SetPos(Vector2(-200, screenHeight / 2+20));
	//Secret Boss Bullet
	m_SecretBoss->GetFlameManager()->Init(Bullet::STATE_Impact, "Boss\\explosion-12-w128-h126", 12, 0.1f, 128, 126, Vector2(-50, -50));
	m_SecretBoss->GetFlameManager()->Init(Bullet::STATE_Spit, "Boss\\flame_69_42_64t", 69, 0.001f, 42, 64, Vector2(-50, -50));
	for (auto it : m_SecretBoss->GetFlameManager()->GetlistBullet())
	{
		it->SetHeight(45);
		it->SetWidth(40);
		m_CollitionChecker->PushBack(it);
	}
	//EnemyRino
	m_BornMonsterManager->GetEnemyRino()->Init(Enemy::STATE_Hit,"Enemy\\Rino\\Hit (52x34)-5",5,0.1f,52,34,Vector2(screenWidth , screenHeight -69));
	m_BornMonsterManager->GetEnemyRino()->Init(Enemy::STATE_Run, "Enemy\\Rino\\Run (52x34)-6", 6, 0.1f, 52, 34, Vector2(screenWidth , screenHeight -69));
	m_BornMonsterManager->GetEnemyRino()->SetTag(Entity::Tag_EnemyRino);
	for (auto it : m_BornMonsterManager->GetEnemyRino()->GetlistEnemy())
	{
		it->SetWidth(30);
		it->SetHeight(30);
		m_CollitionChecker->PushBack(it);
	}
	//EnemyBat
	m_BornMonsterManager->GetEnemyBat()->Init(Enemy::STATE_Hit, "Enemy\\Bat\\Hit (46x30)-5", 5, 0.1f, 46, 30, Vector2(screenWidth , screenHeight / 2));
	m_BornMonsterManager->GetEnemyBat()->Init(Enemy::STATE_Run, "Enemy\\Bat\\Flying (46x30)-7", 7, 0.1f, 46, 30, Vector2(screenWidth , screenHeight / 2));
	m_BornMonsterManager->GetEnemyBat()->SetTag(Entity::Tag_EnemyBat);

	for (auto it : m_BornMonsterManager->GetEnemyBat()->GetlistEnemy())
	{
		it->SetWidth(20);
		it->SetHeight(30);
		m_CollitionChecker->PushBack(it);
	}
	//
	Application::GetInstance()->m_LevelGame.SetLevel(0);
	m_Character->GetListSound()->at(ICState::Sound_Shoot).load("../Data/Sounds/Shoot.wav");
	Application::GetInstance()->gb_soloud.play(ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SE_BossGrowlIntroPlay));

}

void GSPlay::Exit()
{
}


void GSPlay::Pause()
{

}

void GSPlay::Resume()
{

}


void GSPlay::HandleEvents()
{

}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	m_keyB->HandleKeyEvents(key, bIsPressed);
	m_Character->ReciveKeyEvents(m_keyB->GetKey());
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	
}

std::string sConvertIntToString(long long x)
{
	if (x == 0) return "0";
	std::string tmp = "";
	while (x)
	{
		char k = x % 10 + '0';
		tmp = k + tmp;
		x /= 10;
	}
	return tmp;
}

void GSPlay::Update(float deltaTime)
{
	//m_Character->SetAllowImpact(0);
	m_Character->Update(deltaTime);
	if (m_countTimeIntro < 3.0f)
	{
		m_BgAbove->Update(deltaTime);
		m_BgUnder->Update(deltaTime);
		m_BgMid->Update(deltaTime);
		m_countTimeIntro += deltaTime;
		return;
	}
	else if (m_CheckSound == false)
	{
		int handle=Application::GetInstance()->gb_soloud.play(ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SE_BG));
		Application::GetInstance()->gb_soloud.setVolume(handle,Application::GetInstance()->m_onMusic);
		m_CheckSound = true;
	}
	m_Boss->GetBulletManager()->Update(deltaTime);
	m_SecretBoss->GetFlameManager()->Update(deltaTime);
	if (m_Character->isAlive())
	{
		m_CurrentTime += deltaTime;
		m_BgAbove->Update(deltaTime);

		m_BgUnder->Update(deltaTime);
		m_BgMid->Update(deltaTime);
		m_score->setText(sConvertIntToString(m_CurrentScore));
		if (m_CurrentTime > 0.3)
		{
			m_CurrentScore += 1;
			m_Count += 1;
			m_CurrentTime -= 0.3;
		}
		m_BornMonsterManager->Update(deltaTime);
		if (m_CurrentScore > 100)
		{
			m_SecretBoss->Update(deltaTime);
			if (m_Count > 100)
			{
				m_Count -= 100;
				Application::GetInstance()->m_LevelGame.LevelUp();
			}
		}

		m_Boss->Update(deltaTime);
		
		m_CollitionChecker->Detect();
	}
	else
	{
		Application::GetInstance()->m_CurrentScore = m_CurrentScore;
		Application::GetInstance()->m_LevelGame.ReLevel();
	}
}

void GSPlay::Draw()
{

	m_BgUnder->Draw();

	m_SecretBoss->Draw();

	m_BgMid->Draw();

	m_score->Draw();
	
	m_Character->Draw();

	m_Boss->Draw();

	m_BornMonsterManager->Draw();

	m_SecretBoss->GetFlameManager()->Draw();

	m_BgAbove->Draw();
	
}

void GSPlay::SetNewPostionForBullet()
{
}