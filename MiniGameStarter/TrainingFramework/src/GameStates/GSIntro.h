#pragma once
#include "gamestatebase.h"
#include "DynamicObject.h"

class GSIntro :
	public GameStateBase
{
public:
	GSIntro();
	~GSIntro();

	void Init();
	void Exit();

	void Pause();
	void Resume();

	void HandleEvents();
	void HandleKeyEvents(int key, bool bIsPressed);
	void HandleTouchEvents(int x, int y, bool bIsPressed);
	void Update(float deltaTime);
	void Draw();

private:
	std::list<std::shared_ptr<Sprite2D>> m_listImage;
	std::shared_ptr<Text>  m_Text;
	float m_time;
};

