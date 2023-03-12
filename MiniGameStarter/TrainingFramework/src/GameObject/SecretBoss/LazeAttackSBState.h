#pragma once
#include "SecretBoss/ISBState.h"
#include "SecretBoss/ISecretBoss.h"

class LazeAttackSBState :
	public ISBState
{
public:
	LazeAttackSBState(ISecretBoss* boss);
	void SetState()
	{
		m_Boss->SetState(m_Boss->GetLazeAttackState());
	}

	void Init(std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos);
	void Draw();
	void Update(float deltaTime);
	void ResetAnimation();

private:
	ISecretBoss* m_Boss;
	std::shared_ptr<AnimationSprite> m_Image;
	bool m_isStopAni, m_isAllowOverFrameStop;
	bool m_isFire;
	bool m_sound;
};