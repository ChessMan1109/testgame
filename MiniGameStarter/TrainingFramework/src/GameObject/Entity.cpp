#include "Entity.h"

Entity::Entity()
{
	m_Alive = true;
	m_isAllowImpact = true;
}
Entity::~Entity()
{

}
void Entity::Death()
{
	m_Alive = false;
}
Vector2 Entity::GetPos()
{
	return m_Pos;
}
int Entity::GetWidth()
{
	return m_Width;
}
int Entity::GetHeight()
{
	return m_Height;
}

Entity::Tag Entity::GetTag()
{
	return m_Tag;
}

void Entity::SetPos(Vector2 newPos)
{
	m_Pos = newPos;
}
void Entity::SetHeight(int height)
{
	m_Height = height;
}
void Entity::SetWidth(int width)
{
	m_Width = width;
}
void Entity::SetTag(Entity::Tag newTag)
{
	m_Tag = newTag;
}
bool Entity::isAlive()
{
	return m_Alive;
}
bool Entity::isAllowImpact()
{
	return m_isAllowImpact;
}
void Entity::SetAllowImpact(bool newstate)
{
	m_isAllowImpact = newstate;
}