
#include "IBState.h"
#include "IBoss.h"

class DeathBState :
	public IBState
{
public:
	DeathBState(IBoss* boss);
	void SetState()
	{
		m_Boss->SetState(m_Boss->GetDeathState());
	}

	void Init(std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos);
	void Draw();
	void Update(float deltaTime);
	void ResetAnimation();

private:
	IBoss* m_Boss;
	std::shared_ptr<AnimationSprite> m_Image;
	float m_currentTime;
};