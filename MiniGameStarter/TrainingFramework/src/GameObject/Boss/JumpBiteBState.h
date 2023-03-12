#pragma once

#include "IBState.h"
#include "IBoss.h"

class JumpBiteBState :
	public IBState
{
public:
	JumpBiteBState(IBoss* boss);
	void SetState()
	{
		m_Boss->SetState(m_Boss->GetJumpBiteState());
	}

	void Init(std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos);
	void Draw();
	void Update(float deltaTime);
	void ResetAnimation();

private:
	IBoss* m_Boss;
	std::shared_ptr<AnimationSprite> m_Image;
	bool m_isStopAni = false, m_isAllowOverFrameStop = false;
	bool m_sound;
	bool m_sound2;
};