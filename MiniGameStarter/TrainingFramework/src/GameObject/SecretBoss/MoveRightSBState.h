#pragma once
#include "SecretBoss/ISBState.h"
#include "SecretBoss/ISecretBoss.h"

class MoveRightSBState :
	public ISBState
{
public:
	MoveRightSBState(ISecretBoss* boss);
	void SetState()
	{
		m_Boss->SetState(m_Boss->GetMoveRightState());
	}

	void Init(std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos);
	void Draw();
	void Update(float deltaTime);
	void ResetAnimation();
private:
	ISecretBoss* m_Boss;
	std::shared_ptr<AnimationSprite> m_Image;
	float m_CurrentTime;
	bool m_sound;
	int handle;
};