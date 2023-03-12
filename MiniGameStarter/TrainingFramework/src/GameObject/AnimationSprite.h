#pragma once
#include "Sprite2D.h"

class AnimationSprite :
	public Sprite2D
{
public:
	AnimationSprite(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture,
		int numFrames, float frameTime);
	~AnimationSprite();

	void		Init() override;
	void		Draw() override;
	void		Update(GLfloat deltatime) override;

	void		UpdateType2(GLfloat deltatime, bool &isOnFrameStop,bool &isStopAni, int sttFrameStop);
	void		ResetAnimation();

	GLint		GetWidth();
	GLint		GetHeight();
	Vector2*	GetPosPtr();
	int			GetCurrentFrame();
	int			GetNumFrame();
	void		SetFrameTime(float newFrameTime);

protected:
	int m_numFrames;
	float m_frameTime;
	int m_currentFrame;
	float m_currentTime;
};