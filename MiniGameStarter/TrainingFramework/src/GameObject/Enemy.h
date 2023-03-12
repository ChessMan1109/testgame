
#pragma once
#include "AnimationSprite.h"
#include "Entity.h"

class Enemy :
	public Entity
{
public:
	enum STATE_Enemy
	{
		STATE_Run = 0,
		STATE_Hit,
	};
public:
	Enemy();
	~Enemy();
	void Init(STATE_Enemy stt, std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos);
	void InitForList(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture,
		STATE_Enemy stt, int numFrames, float frameTime, int width, int height, Vector2 pos);
	void Draw();
	void Update(float deltaTime);
	void ResetEnemy();
	void Switch()
	{
		m_isUsed = !m_isUsed;
		m_Alive = !m_Alive;
	}
	bool CheckUsed();
	void SetResetPos(Vector2 newPos);
private:
	std::vector<std::shared_ptr<AnimationSprite>> m_ListImage;
	STATE_Enemy m_State;
	STATE_Enemy m_ChangeState;
	Vector2 m_ResetPos;
	int m_Speed;
	bool m_isUsed;
};