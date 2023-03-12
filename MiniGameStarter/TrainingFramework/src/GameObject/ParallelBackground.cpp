#include "ParallelBackground.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

ParallelBackground::ParallelBackground()
{
	m_isPause = false;
}
ParallelBackground::~ParallelBackground()
{
}
void ParallelBackground::Init(std::string NameFile, int speed)
{
	auto layer = std::make_shared<StaticLayer>(speed);
	layer->Init(NameFile);
	layer->SetPostion(screenWidth / 2, screenHeight / 2 - screenHeight * 0.2);
	layer->SetSize(screenWidth, screenHeight * 1.4);
	m_BackGround.push_back(layer);
}

void ParallelBackground::Draw()
{
	for (auto it: m_BackGround)
	{
		(it)->Draw();
	}
}
void ParallelBackground::Update(float deltatime)
{
	if (m_isPause) return;
	for (auto it : m_BackGround)
	{
		(it)->Update(deltatime);
	}
}

void ParallelBackground::Pause()
{
	m_isPause = true;
}
void ParallelBackground::Resume()
{
	m_isPause = false;
}