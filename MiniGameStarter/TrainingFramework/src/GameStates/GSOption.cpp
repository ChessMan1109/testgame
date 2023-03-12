#include "GSOption.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSOption::GSOption()
{

}
GSOption::~GSOption()
{

}

void GSOption::Init()
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

	//misic button
	texture = ResourceManagers::GetInstance()->GetTexture("misic");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth/2-50, screenHeight/2);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		Application::GetInstance()->m_onMusic = 0.5f;
		});
	m_listButton.push_back(button);

	// misic button
		texture = ResourceManagers::GetInstance()->GetTexture("music_off");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth / 2+50, screenHeight / 2);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		Application::GetInstance()->m_onMusic = 0;
		});
	m_listButton.push_back(button);

	// Tilte
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Planes_ValMore");
	auto text = std::make_shared< Text>(shader, font, "Option", TEXT_COLOR::WHITE, 1.0);
	text->Set2DPosition(screenWidth / 2 - 40, screenHeight / 2 - 100);
	m_listText.push_back(text);

}
void GSOption::Exit()
{

}

void GSOption::Pause()
{

}
void GSOption::Resume()
{

}

void GSOption::HandleEvents()
{

}
void GSOption::HandleKeyEvents(int key, bool bIsPressed)
{

}
void GSOption::HandleTouchEvents(int x, int y, bool bIsPressed)
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

void GSOption::Update(float deltaTime)
{
	m_BackGround->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}
void GSOption::Draw()
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