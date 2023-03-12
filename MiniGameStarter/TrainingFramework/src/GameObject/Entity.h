#pragma once
#include "ResourceManagers.h"
#include "Application.h"

class Entity
{
public:
	enum Tag
	{
		Tag_Character = 0,
		Tag_CharacterBullet,
		Tag_Boss,
		Tag_BossBullet,
		Tag_BossFlame,
		Tag_EnemyRino,
		Tag_EnemyBat,
	};
	Entity();
	~Entity();

	Vector2 GetPos();
	int GetWidth();
	int GetHeight();
	Tag GetTag();

	void SetPos(Vector2 newPos);
	void SetHeight(int height);
	void SetWidth(int width);
	void SetTag(Tag newTag);
	void Death();
	bool isAlive();
	bool isAllowImpact();
	void SetAllowImpact(bool newstate);

protected:
	Vector2 m_Pos;
	int m_Width;
	int m_Height;
	Tag m_Tag;
	bool m_Alive;
	bool m_isAllowImpact;
};