#pragma once
#include "Bullet/Bullet.h"

class Flame:
	public Bullet
{
public:
	Flame();
	~Flame();
	void Update(float deltaTime);
private:
	int m_FHeight;
	int m_FWidth;
};