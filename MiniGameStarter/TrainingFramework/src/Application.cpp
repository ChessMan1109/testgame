#include "Application.h"
#include "GameStates/GameStateMachine.h"
#include "GameStates/GameStatebase.h"
#include "soloud_wav.h"

extern GLint screenWidth;
extern GLint screenHeight;


Application::Application()
{
	isEndGame = false;
	m_CurrentScore = 0;
	m_onMusic = 0.5f;
}


Application::~Application()
{
}


void Application::Init()
{
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	gb_soloud.init();
	GameStateMachine::GetInstance()->PushState(StateTypes::STATE_Intro);
}

void Application::Update(GLfloat deltaTime)
{
	if (isEndGame)
	{
		GameStateMachine::GetInstance()->PopState();
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_EndGame);
		Application::GetInstance()->gb_soloud.stopAll();
		isEndGame = false;
	}
	GameStateMachine::GetInstance()->PerformStateChange();
	if (GameStateMachine::GetInstance()->HasState())
		GameStateMachine::GetInstance()->CurrentState()->Update(deltaTime);

}
void Application::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (GameStateMachine::GetInstance()->HasState())
		GameStateMachine::GetInstance()->CurrentState()->Draw();
}

void Application::HandleKeyEvent(unsigned char key, bool bIsPresseded)
{
	if (GameStateMachine::GetInstance()->HasState())
		GameStateMachine::GetInstance()->CurrentState()->HandleKeyEvents(key, bIsPresseded);

}

void Application::HandleTouchEvent(GLint x, GLint y, bool bIsPresseded)
{

	if (GameStateMachine::GetInstance()->HasState())
		GameStateMachine::GetInstance()->CurrentState()->HandleTouchEvents(x, y, bIsPresseded);
}

void Application::Exit()
{
	exit(0);
}
