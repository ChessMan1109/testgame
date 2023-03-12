#pragma once
#pragma once
#include "AnimationSprite.h"
#include "ResourceManagers.h"
#include "Bullet/BulletManager.h"

class IBState
{
public:
	enum STATE_Action
	{
		STATE_Idle = 0,
		STATE_Hurt,
		STATE_Bite_Attack,
		STATE_Jump_Bite,
		STATE_Jump,
		STATE_Posion_Attack,
		STATE_Fall,
		STATE_Death,
	};
	virtual void SetState() = 0;

	virtual void Init(std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos) = 0;
	virtual void Draw() = 0;
	virtual void Update(float deltaTime) = 0;

	virtual void ResetAnimation() = 0;
};