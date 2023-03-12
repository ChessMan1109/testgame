
#include "IBState.h"
#include "IBoss.h"

class FallBState :
	public IBState
{
public:
	FallBState(IBoss* boss);
	void SetState()
	{
		m_Boss->SetState(m_Boss->GetFallState());
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