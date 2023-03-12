#pragma once
#include "Object.h"

class DynamicObject
	:public Object
{
public:
	enum MOVE
	{
		STAND = 0,
		MOVE_UP,
		MOVE_DOWN,
		MOVE_LEFT,
		MOVE_RIGHT,

		Defaul,
	};
public:
	DynamicObject();
	DynamicObject(int speed);
	~DynamicObject();

	Vector2 GetPos() { return m_Pos; }
	int GetWidth() { return m_Width; }
	int GetHeight() { return m_Height; }

	void Move(MOVE stt);
	void Init(MOVE stt, std::string nameFile, int numFrames, float frameTime);
	void Draw();

	void Update(float deltaTime);
	void SetSpeed(int speed);
	int m_Speed;
private:
	MOVE m_Trend;
	std::vector<std::shared_ptr<AnimationSprite>> m_CurrentState;
};