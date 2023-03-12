#include "GSEndGame.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSEndGame::GSEndGame()
{
	m_ScoreBoard = std::make_shared<Score>();
}


GSEndGame::~GSEndGame()
{
}

std::string ConvertIntToString(long long x)
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

void GSEndGame::Init()
{

	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("Background");

	//BackGround
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);

	//back button
	texture = ResourceManagers::GetInstance()->GetTexture("button_menu");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth/2+50, screenHeight - 70);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		int handle = Application::GetInstance()->gb_soloud.play(ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SE_BosGr));
		Application::GetInstance()->gb_soloud.setLooping(handle, 1);
		Application::GetInstance()->gb_soloud.setVolume(handle, 1.0f);
		});
	m_listButton.push_back(button);

	//play button
	texture = ResourceManagers::GetInstance()->GetTexture("button_restart");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth / 2-50, screenHeight - 70);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Play);
		});
	m_listButton.push_back(button);

	// Tilte
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Planes_ValMore");

	auto text = std::make_shared< Text>(shader, font, "Your Score", TEXT_COLOR::WHITE, 1.0);
	text->Set2DPosition(screenWidth / 2 - 100, screenHeight / 2 - 100);
	m_listText.push_back(text);

	text = std::make_shared< Text>(shader, font, "Best Score", TEXT_COLOR::WHITE, 1.0);
	text->Set2DPosition(screenWidth / 2 - 100, screenHeight / 2);
	m_listText.push_back(text);

	text = std::make_shared< Text>(shader, font, ConvertIntToString(Application::GetInstance()->m_CurrentScore), TEXT_COLOR::WHITE, 1.0);
	text->Set2DPosition(screenWidth / 2 + 100, screenHeight / 2 - 100);
	m_listText.push_back(text);

	text = std::make_shared< Text>(shader, font,ConvertIntToString(m_ScoreBoard->GetHighScore()), TEXT_COLOR::WHITE, 1.0);
	text->Set2DPosition(screenWidth / 2 + 100, screenHeight / 2);
	m_listText.push_back(text);
	m_ScoreBoard->Update(Application::GetInstance()->m_CurrentScore);
	Application::GetInstance()->m_CurrentScore = 0;
}

void GSEndGame::Exit()
{
}


void GSEndGame::Pause()
{

}

void GSEndGame::Resume()
{

}


void GSEndGame::HandleEvents()
{

}

void GSEndGame::HandleKeyEvents(int key, bool bIsPressed)
{

}

void GSEndGame::HandleTouchEvents(int x, int y, bool bIsPressed)
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

void GSEndGame::Update(float deltaTime)
{
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}

	
}

void GSEndGame::Draw()
{
	m_BackGround->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	
	for (auto it : m_listText)
	{
		it->Draw();
	}
}
