#include "Player.h"
#include "keyBoard.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

Player::Player()
{
	m_KeyPress = 0;
	m_Speed = 150;
}
Player::~Player()
{

}
void Player::Init(int width, int height, Vector2 pos)
{
	m_Pos = pos;
}

void Player::ReciveKeyEvents(int key)
{
	m_KeyPress =key;
}
#define PLANE screenHeight-68

void Player::Update(float deltaTime)
{
	if (m_Pos.y >= PLANE)
	{
		m_isTouchTheGround = true;
	}else m_isTouchTheGround = false;
	if ( m_Pos.x > screenWidth)
	{
		m_Pos.x = screenWidth;
	}else if (m_Pos.x< 0)
	{
		m_Pos.x = 0;
	}
	Character::Update(deltaTime);
}