#include "GSMenu.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSMenu::GSMenu()
{

}


GSMenu::~GSMenu()
{
}



void GSMenu::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("BackGround\\bg0");

	//BackGround
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




	//play button
	texture = ResourceManagers::GetInstance()->GetTexture("button_play");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth/2,screenHeight / 2+100);
	button->SetSize(100, 100);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Play);
		Application::GetInstance()->gb_soloud.stopAll();
		});
	m_listButton.push_back(button);
	int delta_space_button = 230;

	//Option button
	texture = ResourceManagers::GetInstance()->GetTexture("button_setting");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(delta_space_button, screenHeight - 50);
	delta_space_button += 100;
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Option);
		});
	m_listButton.push_back(button);

	//high score button
	texture = ResourceManagers::GetInstance()->GetTexture("button_prize");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(delta_space_button, screenHeight - 50);
	delta_space_button += 100;
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_HighScore);
		});
	m_listButton.push_back(button);

	//credit button
	texture = ResourceManagers::GetInstance()->GetTexture("button_credit");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(delta_space_button, screenHeight - 50);
	delta_space_button += 100;
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Credit);
		});
	m_listButton.push_back(button);

	//exit button
	texture = ResourceManagers::GetInstance()->GetTexture("button_exit_game");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(delta_space_button, screenHeight - 50);
	delta_space_button += 100;
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		exit(0);
		});
	m_listButton.push_back(button);


	//text game title
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Planes_ValMore");
	m_Text_gameName = std::make_shared< Text>(shader, font, "Game Run Now", TEXT_COLOR::WHITE, 2.0);
	m_Text_gameName->Set2DPosition(Vector2(screenWidth / 2-150 , 120));

	//animation Boss and Playbutton
	shader= ResourceManagers::GetInstance()->GetShader("AnimationShader");
	texture = ResourceManagers::GetInstance()->GetTexture("main_char\\Idle_8_w27_h40t");
	auto AImage = std::make_shared<AnimationSprite>(model, shader, texture, 8, 0.1f);
	AImage->Set2DPosition(screenWidth / 2, screenHeight / 2+29);
	AImage->SetSize(27,40);
	m_listAnimation.push_back(AImage);

	int handle = Application::GetInstance()->gb_soloud.play(ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SE_BosGr));
	Application::GetInstance()->gb_soloud.setLooping(handle, 1);
	Application::GetInstance()->gb_soloud.setVolume(handle, 1.0f);
}

void GSMenu::Exit()
{
}


void GSMenu::Pause()
{

}

void GSMenu::Resume()
{

}


void GSMenu::HandleEvents()
{

}

void GSMenu::HandleKeyEvents(int key, bool bIsPressed)
{

}

void GSMenu::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto it : m_listButton)
	{
		(it)->HandleTouchEvents(x, y, bIsPressed);
		if ((it)->IsHandle())
		{
			Application::GetInstance()->gb_soloud.play(ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SE_Click));
			break;
		}
	}
	
}

void GSMenu::Update(float deltaTime)
{
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
	for (auto it : m_listAnimation)
	{
		it->Update(deltaTime);
	}
}

void GSMenu::Draw()
{
	m_BgUnder->Draw();
	m_BgMid->Draw();
	
	for (auto it : m_listAnimation)
	{
		it->Draw();
	}
	m_BgAbove->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	m_Text_gameName->Draw();
	
}
