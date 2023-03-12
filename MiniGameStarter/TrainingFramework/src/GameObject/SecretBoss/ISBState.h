#pragma once
#pragma once
#include "AnimationSprite.h"
#include "ResourceManagers.h"
#include "FlameManager.h"
#include "Application.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

class ISBState
{
public:
	enum STATE_Action
	{
		STATE_MOVE_Left,
		STATE_MOVE_Right,
		STATE_Laze_Attack,
		STATE_Bullet_Attack,
	};
	virtual void SetState() = 0;

	virtual void Init(std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos) = 0;
	virtual void Draw() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void ResetAnimation() = 0;
};