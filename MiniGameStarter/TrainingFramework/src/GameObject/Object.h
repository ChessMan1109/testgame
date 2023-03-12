#pragma once
#include "GameManager/ResourceManagers.h"

class Object
{
public:
	Object();
	Object(int hp);
	~Object();

	void Init(std::string nameFile, int numFrames, float frameTime);
	void Draw();
	void Update(float deltaTime);
	void SetSize(int width, int height);
	void SetPostion(Vector2 pos);
	void SetHP(int hp);

	std::shared_ptr<AnimationSprite> m_CurrentAni;
	int m_HP;
	Vector2 m_Pos;
	int m_Width;
	int m_Height;
};