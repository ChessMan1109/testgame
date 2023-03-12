#include "GSIntro.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine


GSIntro::GSIntro()
{
	m_time = 0;
}


GSIntro::~GSIntro()
{
}


void GSIntro::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	auto texture = ResourceManagers::GetInstance()->GetTexture("ab");
	//logo
	std::shared_ptr<Sprite2D> Image = std::make_shared<Sprite2D>(model, shader, texture);
	Image->Set2DPosition(screenWidth / 2, screenHeight / 2);
	Image->SetSize(500, 450);
	m_listImage.push_back(Image);

	//text
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("timesbd");
	m_Text = std::make_shared< Text>(shader, font, "Loading ...", TEXT_COLOR::GREEN, 1.0);
	m_Text->Set2DPosition(Vector2(screenWidth / 2-50, screenHeight / 2+200));

	////logo2
	//texture = ResourceManagers::GetInstance()->GetTexture("a");
	//Image = std::make_shared<Sprite2D>(model, shader, texture);
	//Image->Set2DPosition(screenWidth / 2, screenHeight / 2 );
	//Image->SetSize(300, 100);
	//m_listImage.push_back(Image);

	//sound for all
	ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SoundEffect::SE_ArrowHit).load("../Data/Sounds/arrowHit02.wav");
	ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SoundEffect::SE_DeathFlash).load("../Data/Sounds/DeathFlash.wav");
	ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SoundEffect::SE_Fall).load("../Data/Sounds/fall.wav");
	ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SoundEffect::SE_JumpLand).load("../Data/Sounds/Playersounds - Track 10 - Jump2.wav");
	ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SoundEffect::SE_MonsterGr).load("../Data/Sounds/Large Monster Grunt Hit 02.wav");
	ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SoundEffect::SE_PlayerDeath).load("../Data/Sounds/Playersounds - Track 6 - Hurt2.wav");
	ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SoundEffect::SE_Explosion).load("../Data/Sounds/explosion.wav");
	ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SoundEffect::SE_Laser).load("../Data/Sounds/Laser Shot.wav");
	ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SoundEffect::SE_BG).load("../Data/Sounds/Uprising.wav");
	ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SoundEffect::SE_PoistionBoom).load("../Data/Sounds/impactsplat03.wav");
	ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SoundEffect::SE_BossSpit).load("../Data/Sounds/monster-5.wav");
	ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SoundEffect::SE_Click).load("../Data/Sounds/Menu Selection Click.wav");
	ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SoundEffect::SE_BosGr).load("../Data/Sounds/MonsterSoundTutorial.wav");
	ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SoundEffect::SE_BossGrowlIntroPlay).load("../Data/Sounds/Monster Growl-SoundBible.com-344645592.wav");
	ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SoundEffect::SE_Alarm).load("../Data/Sounds/ambient_alarm1.wav");
	ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SoundEffect::SE_MonsterHurt).load("../Data/Sounds/monster-hurt.wav");

	

	
}

void GSIntro::Exit()
{

}


void GSIntro::Pause()
{

}

void GSIntro::Resume()
{

}


void GSIntro::HandleEvents()
{

}

void GSIntro::HandleKeyEvents(int key, bool bIsPressed)
{
	
}

void GSIntro::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	if (bIsPressed) Application::GetInstance()->gb_soloud.play(ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SE_Click));
}

void GSIntro::Update(float deltaTime)
{
	m_time += deltaTime;
	if (m_time > 2)
	{
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Menu);
		m_time = 0;
	}
}

void GSIntro::Draw()
{
	for (auto it : m_listImage)
	{
		it->Draw();
	}
	m_Text->Draw();
}
