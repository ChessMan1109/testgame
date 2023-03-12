
#pragma once
#include "AnimationSprite.h"
#include "Entity.h"

class Bullet:
	public Entity
{
public:
	enum STATE_Bullet
	{
		STATE_Spit=0,
		STATE_Impact,
	};
public:
	Bullet();
	~Bullet();
	void Init(STATE_Bullet stt,std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos);
	void InitForList(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture,
		STATE_Bullet stt, int numFrames, float frameTime, int width, int height, Vector2 pos);
	void Draw();
	void Update(float deltaTime);
	void ResetBullet();
	void Switch()
	{
		m_isUsed = !m_isUsed;
		m_Alive = !m_Alive;
	}
	bool CheckUsed();
	void SetResetPos(Vector2 newPos);
protected:
	std::vector<std::shared_ptr<AnimationSprite>> m_ListImage;
	STATE_Bullet m_State;
	STATE_Bullet m_ChangeState;
	Vector2 m_ResetPos;
	int m_Speed;
	bool m_isUsed;
};