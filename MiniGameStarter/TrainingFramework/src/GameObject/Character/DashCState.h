#pragma once
#pragma once
#include "ICState.h"
#include "ICharacter.h"

class DashCState :
	public ICState
{
public:
	DashCState(ICharacter* character);
	void SetState()
	{
		m_Character->SetState(m_Character->GetDashState());
	}

	void Jump();
	void Attack();
	void Death();
	void Dash();
	void Idle();
	void Run();
	void Fall();

	void Init(std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos);
	void Draw();
	void Update(float deltaTime);
	void ResetAnimation();

private:
	ICharacter* m_Character;
	std::shared_ptr<AnimationSprite> m_Image;
	bool m_isStopAni = false, m_isAllowOverFrameStop = false;
	float  m_currentTime;
	bool m_Sound;
};