#pragma once
#include "Entity.h"

class CheckCollision
{
public:
	void PushBack(std::shared_ptr<Entity> newObj);
	bool Collising(std::shared_ptr<Entity> obj1, std::shared_ptr<Entity> obj2);
	void Detect();
private:
	std::list<std::shared_ptr<Entity> > m_listObj;
};