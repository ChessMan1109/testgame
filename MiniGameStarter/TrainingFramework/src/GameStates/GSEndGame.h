#pragma once
#include "gamestatebase.h"
#include "GameButton.h"
#include "AnimationSprite.h"
#include <string.h>
#include "Score.h"

class GSEndGame :
	public GameStateBase
{
public:
	GSEndGame();
	~GSEndGame();

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

	std::shared_ptr<Sprite2D> m_BackGround;
	std::shared_ptr<Score> m_ScoreBoard;
	std::list<std::shared_ptr<Sprite2D>>	m_listImage;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::list<std::shared_ptr<Text>>	m_listText;


};

