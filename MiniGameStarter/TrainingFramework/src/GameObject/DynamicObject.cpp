#include "DynamicObject.h"


DynamicObject::DynamicObject():m_Speed(120)
{
    m_Trend = STAND;
    m_CurrentState.resize(Defaul);
}

DynamicObject::DynamicObject(int speed) :m_Speed(speed)
{
    m_CurrentState.resize(Defaul);
}
DynamicObject::~DynamicObject()
{

}

void DynamicObject::Move(MOVE stt)
{
    m_Trend = stt;
}

void DynamicObject::Init(MOVE stt, std::string nameFile, int numFrames, float frameTime)
{
    auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
    auto texture = ResourceManagers::GetInstance()->GetTexture(nameFile);
    auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
    m_CurrentState[stt] = std::make_shared<AnimationSprite>(model, shader, texture, numFrames, frameTime);
    m_CurrentState[stt]->Set2DPosition(m_Pos);
    m_CurrentState[stt]->SetSize(m_Width, m_Height);
}

void DynamicObject::Draw()
{
    m_CurrentState[m_Trend]->Draw();
}

void DynamicObject::Update(float deltaTime)
{
    switch (m_Trend)
    {
    case DynamicObject::STAND:
            break;
    case DynamicObject::MOVE_UP:
        Object::m_Pos.y -= m_Speed * deltaTime;
        break;
    case DynamicObject::MOVE_DOWN:
       Object::m_Pos.y += m_Speed * deltaTime;
        break;
    case DynamicObject::MOVE_LEFT:
        Object::m_Pos.x -= m_Speed * deltaTime;
        break;
    case DynamicObject::MOVE_RIGHT:
        Object::m_Pos.x += m_Speed * deltaTime;
        break;
    default:
        break;
    }
    m_CurrentState[m_Trend]->Set2DPosition(m_Pos);
    m_CurrentState[m_Trend]->Update(deltaTime);
}

void DynamicObject::SetSpeed(int speed)
{
    m_Speed = speed;
}
