#pragma once
#pragma once
#include "AnimationSprite.h"
#include "ResourceManagers.h"
#include "keyBoard.h"
#include "Bullet/BulletManager.h"
#include "Application.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic enginead
#define PLANE screenHeight-68

class ICState
{
public:
	enum STATE_Action
	{
		STATE_Idle=0,
		STATE_Run,
		STATE_Death,
		STATE_Dash,
		STATE_Attack,
		STATE_Jump,
		STATE_Fall,
	};
	enum Sound
	{
		Sound_Shoot=0,
		Sound_Nums,
	};
	virtual void SetState() = 0;

	virtual void Jump() = 0;
	virtual void Attack() = 0;
	virtual void Death() = 0;
	virtual void Dash() = 0;
	virtual void Idle() = 0;
	virtual void Run() = 0;
	virtual void Fall() = 0;

	virtual void Init(std::string nameFile,int numFrames, float frameTime, int width, int height,Vector2 pos) = 0;
	virtual void Draw()=0;
	virtual void Update(float deltaTime)=0;

	virtual void ResetAnimation() = 0;
	
};