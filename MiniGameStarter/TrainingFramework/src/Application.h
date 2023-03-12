#pragma once
#include "Singleton.h"
#include "GameConfig.h"
#include "soloud_wav.h"
#include "LevelGame.h"

class Application : public CSingleton<Application>
{
public:
	Application();
	~Application();
	void		Init();
	void		Update( GLfloat deltaTime);
	void		Render();
	void		HandleKeyEvent(unsigned char key, bool bIsPresseded);
	void		HandleTouchEvent(GLint x, GLint y, bool bIsPresseded);
	void		Exit();

	SoLoud::Soloud gb_soloud;
	bool isEndGame;
	long long m_CurrentScore;
	LevelGame m_LevelGame;
	float m_onMusic;
private:
};

