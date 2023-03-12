#pragma once
#include "SecretBoss/ISBState.h"
#include "SecretBoss/ISecretBoss.h"

class BulletAttackSBState :
	public ISBState
{
public:
	BulletAttackSBState(ISecretBoss* boss);
	void SetState()
	{
		m_Boss->SetState(m_Boss->GetBulletAttackState());
	}

	void Init(std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos);
	void Draw();
	void Update(float deltaTime);
	void ResetAnimation();
private:
	ISecretBoss* m_Boss;
	std::shared_ptr<AnimationSprite> m_Image;
	bool m_isStopAni = false, m_isAllowOverFrameStop = false;
};