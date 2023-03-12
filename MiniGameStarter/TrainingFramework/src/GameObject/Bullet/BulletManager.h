#pragma once
#include"Bullet/Bullet.h"

class BulletManager
{
public:
	BulletManager(int numBullet);
	~BulletManager();
	void Init(Bullet::STATE_Bullet stt, std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos);

	void Fire(Vector2 newPos);
	void Fire();
	void Draw();
	void Update(float deltaTime);
	void SetTag(Entity::Tag newTag);
	std::list<std::shared_ptr<Bullet> > GetlistBullet();
private:
	std::list<std::shared_ptr<Bullet> > m_listBullet;
};