#include "GSHelp.h"
#include "Camera.h"
GSHelp::GSHelp() : GameStateBase(StateType::STATE_HELP),
m_background(nullptr), m_listButton(std::list<std::shared_ptr<GameButton>>{}), m_textGameName(nullptr), m_textthoat(nullptr)
{
}


GSHelp::~GSHelp()
{
}



void GSHelp::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("Backgroudhelp.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// play button
	texture = ResourceManagers::GetInstance()->GetTexture("btn_play.tga");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 1.5);
	button->SetSize(100, 100);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY);
		});
	m_listButton.push_back(button);

	// exit setting button
	texture = ResourceManagers::GetInstance()->GetTexture("btn_close.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 50, 50);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_MENU);
		});
	m_listButton.push_back(button);

	// game title
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
	m_textGameName = std::make_shared< Text>(shader, font, "Players will press the W, S, A and D keys to go up, down, left and right. Space key to shoot bullets and use Ctrl to launch spells", Vector4(0.0f, 0.1f, 1.0f, 1.0f), 1.0f);
	m_textGameName->Set2DPosition(Vector2(60, 200));
	
	std::string name = "Alarm01.wav";
	ResourceManagers::GetInstance()->PlaySound(name);
}

void GSHelp::Exit()
{
	ResourceManagers::FreeInstance();
}


void GSHelp::Pause()
{
}

void GSHelp::Resume()
{
}


void GSHelp::HandleEvents()
{
}

void GSHelp::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSHelp::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSHelp::HandleMouseMoveEvents(int x, int y)
{
}

void GSHelp::Update(float deltaTime)
{
	m_background->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSHelp::Draw()
{
	m_background->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	m_textGameName->Draw();
}
