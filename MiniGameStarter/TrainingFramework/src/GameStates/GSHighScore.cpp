#include "GSHighScore.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSHighScore::GSHighScore()
{

}
GSHighScore::~GSHighScore()
{

}

void GSHighScore::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("Background");

	//BackGround
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);

	//back button
	texture = ResourceManagers::GetInstance()->GetTexture("button_back");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth - 50, 50);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);

	//reset button
	texture = ResourceManagers::GetInstance()->GetTexture("button_restart");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth/2, screenHeight-100);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		Score tmp;
		tmp.Reset();
		tmp.WriteFile();
		GameStateMachine::GetInstance()->ReLoadCurrentState(STATE_HighScore);
		});
	m_listButton.push_back(button);

	// Tilte
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Planes_ValMore");
	auto text = std::make_shared< Text>(shader, font, "High Score", TEXT_COLOR::WHITE, 1.0);
	text->Set2DPosition(screenWidth / 2-60, screenHeight / 2-100);
	m_listText.push_back(text);

	// ScoreBoard
	int delta_space = 50;
	ScoreBoard = std::make_shared<Score>(5);
	for (int i = 0; i < ScoreBoard->m_NumScore; i++)
	{
		//ScoreBoard->Update(99);
		text = std::make_shared< Text>(shader, font,ScoreBoard->GetConvertIntToString(i), TEXT_COLOR::WHITE, 1.0);
		text->Set2DPosition(screenWidth / 2 -10, screenHeight / 2 - 100+delta_space);
		delta_space += 30;
		m_listText.push_back(text);
	}

}
void GSHighScore::Exit()
{

}

void GSHighScore::Pause()
{

}
void GSHighScore::Resume()
{

}

void GSHighScore::HandleEvents()
{

}

void GSHighScore::HandleKeyEvents(int key, bool bIsPressed)
{

}
void GSHighScore::HandleTouchEvents(int x, int y, bool bIsPressed)
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

void GSHighScore::Update(float deltaTime)
{
	m_BackGround->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}
void GSHighScore::Draw()
{
	m_BackGround->Draw();
	for (auto it : m_listImage)
	{
		it->Draw();
	}
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	for (auto it : m_listText)
	{
		it->Draw();
	}
}