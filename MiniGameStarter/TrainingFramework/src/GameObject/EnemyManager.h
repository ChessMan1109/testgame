#pragma once
#include "Enemy.h"

class EnemyManager
{
public:
	EnemyManager(int numBullet);
	~EnemyManager();
	void Init(Enemy::STATE_Enemy stt, std::string nameFile, int numFrames, float frameTime, int width, int height, Vector2 pos);

	void Fire();
	void Draw();
	void Update(float deltaTime);
	void SetTag(Entity::Tag newTag);
	std::list<std::shared_ptr<Enemy> > GetlistEnemy();
private:
	std::list<std::shared_ptr<Enemy> > m_listEnemy;
};