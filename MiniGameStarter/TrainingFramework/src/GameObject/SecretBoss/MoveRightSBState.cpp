#include "SecretBoss/MoveRightSBState.h"


MoveRightSBState::MoveRightSBState(ISecretBoss* boss)
{
	m_Boss = boss;
	m_CurrentTime = 0.0f;
	m_sound = false;
}
void MoveRightSBState::Init(std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos)
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture(nameFile);
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	m_Image = std::make_shared<AnimationSprite>(model, shader, texture, numFrames, frameTime);
	m_Image->Set2DPosition(pos);
	float scale = *m_Boss->GetNumScale();
	m_Image->SetSize(width * scale, height * scale);
}

void MoveRightSBState::Draw()
{
	m_Image->Draw();
}

void MoveRightSBState::Update(float deltaTime)
{
	if (m_sound == false)
	{
		handle = Application::GetInstance()->gb_soloud.play(ResourceManagers::GetInstance()->GetListSound()->at(ResourceManagers::SE_Alarm));
		Application::GetInstance()->gb_soloud.setLooping(handle, 1);
		m_sound = true;
	}
	m_CurrentTime += deltaTime;
	Vector2* pos = m_Boss->GetPos();
	int speed = 100;
	if (pos->x + speed * deltaTime >= screenWidth / 2)
	{
		pos->x = screenWidth / 2;
		*m_Boss->GetCurrentAction() = ISBState::STATE_Laze_Attack;
		Application::GetInstance()->gb_soloud.stop(handle);
		ResetAnimation();
		m_sound = false;
	}
	else pos->x += speed * deltaTime;
	m_Image->Update(deltaTime);
	m_Image->Set2DPosition(*pos);
}

void MoveRightSBState::ResetAnimation()
{
	m_Image->ResetAnimation();
	m_CurrentTime = 0.0f;
}

