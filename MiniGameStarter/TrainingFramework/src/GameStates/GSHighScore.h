#pragma once
#include "gamestatebase.h"
#include "GameButton.h"
#include "Score.h"

class GSHighScore :
	public GameStateBase
{
public:
	GSHighScore();
	~GSHighScore();

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
	std::list<std::shared_ptr<Sprite2D>>	m_listImage;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	//std::shared_ptr<GameButton> button_reset;
	std::list<std::shared_ptr<Text>>	m_listText;
	std::shared_ptr<Score> ScoreBoard;

};

