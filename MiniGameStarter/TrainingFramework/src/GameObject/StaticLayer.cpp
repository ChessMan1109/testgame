#include "StaticLayer.h"
#include "GameManager/ResourceManagers.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

StaticLayer::StaticLayer() :m_Speed(1000),m_CurrentPos(Vector2(screenWidth / 2, screenHeight / 2)), m_Pos(Vector2(screenWidth / 2, screenHeight / 2))
{
}

StaticLayer::StaticLayer(int speed) : m_Speed(speed), m_CurrentPos(Vector2(screenWidth / 2, screenHeight / 2)), m_Pos(Vector2(screenWidth / 2, screenHeight / 2))
{
}
StaticLayer::StaticLayer(int speed,int x,int y):m_Speed(speed)
{
	m_Pos.x = x;
	m_Pos.y = y;
	m_CurrentPos.x = x;
	m_CurrentPos.y = y;
}
void StaticLayer::SetSpeed(int speed)
{
	m_Speed = speed;
}
StaticLayer::~StaticLayer()
{
}

void StaticLayer::Init(std::string NameFile)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	auto texture = ResourceManagers::GetInstance()->GetTexture(NameFile);
	m_Image1 = std::make_shared<Sprite2D>(model, shader, texture);
	m_Image2 = std::make_shared<Sprite2D>(model, shader, texture);
	this->SetPostion(screenWidth/2, screenHeight/2);
	this->SetSize(screenWidth, screenHeight);
}

void StaticLayer::Draw()
{
	m_Image1->Draw();
	m_Image2->Draw();
}

void StaticLayer::Update(float deltatime)
{
	m_CurrentPos.x -= m_Speed * deltatime;
	if (m_CurrentPos.x <-m_Pos.x)
	{
		m_CurrentPos.x = m_Pos.x;
	}
	this->SetCurrentPostion(m_CurrentPos.x, m_CurrentPos.y);
}
void StaticLayer::SetPostion(int x, int y)
{
	m_Image1->Set2DPosition(x, y);
	m_Image2->Set2DPosition(screenWidth + x, y);
	m_Pos = Vector2(x, y);
	m_CurrentPos = m_Pos;
}

void StaticLayer::SetCurrentPostion(int x, int y)
{
	m_Image1->Set2DPosition(x,y);
	m_Image2->Set2DPosition(screenWidth + x, y);
}

void StaticLayer::SetSize(int width, int height)
{
	m_Image1->SetSize(width, height);
	m_Image2->SetSize(width, height);
}