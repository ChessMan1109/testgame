#pragma once
#include "gamestatebase.h"
#include "GameButton.h"
#include "AnimationSprite.h"
#include <string.h>
#include "soloud_wav.h"

class GSMenu :
	public GameStateBase
{
public:
	GSMenu();
	~GSMenu();
	
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
	std::shared_ptr<ParallelBackground> m_BgUnder;
	std::shared_ptr<ParallelBackground> m_BgMid;
	std::shared_ptr<ParallelBackground> m_BgAbove;

	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::shared_ptr<Text>  m_Text_gameName;
	std::list<std::shared_ptr<AnimationSprite>> m_listAnimation;
};

