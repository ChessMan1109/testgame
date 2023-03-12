#pragma once
#include "Flame.h"

class FlameManager
{
public:
	FlameManager(int numBullet);
	~FlameManager();
	void Init(Flame::STATE_Bullet stt, std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos);

	void Fire(Vector2 newPos);
	void Fire();
	void Draw();
	void Update(float deltaTime);
	void SetTag(Entity::Tag newTag);
	std::list<std::shared_ptr<Flame> > GetlistBullet();
private:
	std::list<std::shared_ptr<Flame> > m_listBullet;
};