#include "Object.h"

Object::Object()
{
}
Object::Object(int hp) :m_HP(hp)
{
}
Object::~Object()
{
}
void Object::Init(std::string nameFile, int numFrames, float frameTime)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture(nameFile);
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	m_CurrentAni->Set2DPosition(m_Pos);
	m_CurrentAni->SetSize(m_Width, m_Height);
}

void Object::SetSize(int width, int height)
{
	m_Width = width;
	m_Height = height;
}

void Object::SetPostion(Vector2 pos)
{
	m_Pos = pos;
}

void Object::SetHP(int hp)
{
	m_HP = hp;
}

void Object::Draw()
{
	m_CurrentAni->Draw();
}
void Object::Update(float deltaTime)
{
	m_CurrentAni->Update(deltaTime);
}