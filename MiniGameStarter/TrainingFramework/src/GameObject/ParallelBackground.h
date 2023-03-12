#pragma once
#include "StaticLayer.h"

class ParallelBackground
{
public:
	ParallelBackground();
	~ParallelBackground();
	void		Init(std::string NameFile,int speed);
	void		Draw();
	void		Update(float deltatime);
	void Pause();
	void Resume();
private:
	std::list <std::shared_ptr<StaticLayer>> m_BackGround;
	bool m_isPause;
};