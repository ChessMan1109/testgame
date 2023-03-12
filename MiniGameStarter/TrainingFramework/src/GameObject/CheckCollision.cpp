#include "CheckCollision.h"

void CheckCollision::PushBack(std::shared_ptr<Entity> newObj)
{
	m_listObj.push_back(newObj);
}
bool CheckCollision::Collising(std::shared_ptr<Entity> obj1, std::shared_ptr<Entity> obj2)
{
	float obj1_up = obj1->GetPos().y - obj1->GetHeight() / 2;
	float obj1_down = obj1->GetPos().y + obj1->GetHeight() / 2;
	float obj1_left = obj1->GetPos().x - obj1->GetWidth() / 2;
	float obj1_right = obj1->GetPos().x + obj1->GetWidth() / 2;

	float obj2_up = obj2->GetPos().y - obj2->GetHeight() / 2;
	float obj2_down = obj2->GetPos().y + obj2->GetHeight() / 2;
	float obj2_left = obj2->GetPos().x - obj2->GetWidth() / 2;
	float obj2_right = obj2->GetPos().x + obj2->GetWidth() / 2;

	if (obj1_up > obj2_down) return false;
	if (obj1_left > obj2_right) return false;
	if (obj1_down< obj2_up) return false;
	if (obj1_right < obj2_left) return false;
	return true;

}

void CheckCollision::Detect()
{
	for (auto obj1 : m_listObj)
	{
		if (!obj1->isAlive() || !obj1->isAllowImpact()) continue;
		for (auto obj2 : m_listObj)
		{
			if (!obj2->isAlive() || !obj2->isAllowImpact()) continue;
			if (Collising(obj1, obj2) == false) continue;

			Entity::Tag tag_obj1 = obj1->GetTag();
			Entity::Tag tag_obj2 = obj2->GetTag();
			if (tag_obj1 == Entity::Tag_Character)
			{
				switch (tag_obj2)
				{
				case Entity::Tag_Boss:
					obj1->Death();
					break;
				case Entity::Tag_BossBullet:
					obj1->Death();
					obj2->Death();
					break;
				case Entity::Tag_BossFlame:
					obj1->Death();
					obj2->Death();
					
					break;
				case Entity::Tag_EnemyBat:
					obj1->Death();
					break;
				case Entity::Tag_EnemyRino:
					obj1->Death();
					break;
				case Entity::Tag_Character:
					break;
				case Entity::Tag_CharacterBullet:
					break;
				default:
					break;
				}
			}
			else if (tag_obj1 == Entity::Tag_Boss)
			{
				switch (tag_obj2)
				{
				case Entity::Tag_Boss:
					break;
				case Entity::Tag_BossBullet:
					break;
				case Entity::Tag_BossFlame:
					break;
				case Entity::Tag_EnemyBat:
					obj2->Death();
					break;
				case Entity::Tag_EnemyRino:
					obj2->Death();
					break;
				case Entity::Tag_Character:
					obj2->Death();
					break;
				case Entity::Tag_CharacterBullet:
					break;
				default:
					break;
				}
			}
			else if (tag_obj1 == Entity::Tag_BossBullet)
			{
				switch (tag_obj2)
				{
				case Entity::Tag_Boss:
					break;
				case Entity::Tag_BossBullet:
					break;
				case Entity::Tag_BossFlame:
					break;
				case Entity::Tag_EnemyBat:
					obj1->Death();
					obj2->Death();
					break;
				case Entity::Tag_EnemyRino:
					obj1->Death();
					obj2->Death();
					break;
				case Entity::Tag_Character:
					obj1->Death();
					obj2->Death();
					break;
				case Entity::Tag_CharacterBullet:
					break;
				default:
					break;
				}
			}
			else if (tag_obj1 == Entity::Tag_BossFlame)
			{
				switch (tag_obj2)
				{
				case Entity::Tag_Boss:
					break;
				case Entity::Tag_BossBullet:
					break;
				case Entity::Tag_BossFlame:
					break;
				case Entity::Tag_EnemyBat:
					obj2->Death();
					obj1->Death();
					
					break;
				case Entity::Tag_EnemyRino:
					obj2->Death();
					obj1->Death();
					
					break;
				case Entity::Tag_Character:
					obj1->Death();
					obj2->Death();
					
					break;
				case Entity::Tag_CharacterBullet:
					break;
				default:
					break;
				}
			}
			else if (tag_obj1 == Entity::Tag_EnemyRino)
			{
				switch (tag_obj2)
				{
				case Entity::Tag_Boss:
					obj1->Death();
					break;
				case Entity::Tag_BossBullet:
					obj1->Death();
					obj2->Death();
					break;
				case Entity::Tag_BossFlame:
					obj1->Death();
					obj2->Death();
					break;
				case Entity::Tag_EnemyBat:
					break;
				case Entity::Tag_EnemyRino:
					break;
				case Entity::Tag_Character:
					obj2->Death();
					break;
				case Entity::Tag_CharacterBullet:
					obj1->Death();
					obj2->Death();
					break;
				default:
					break;
				}
			}
			else if (tag_obj1 == Entity::Tag_EnemyBat)
			{
				switch (tag_obj2)
				{
				case Entity::Tag_Boss:
					obj1->Death();
					break;
				case Entity::Tag_BossBullet:
					obj1->Death();
					obj2->Death();
					break;
				case Entity::Tag_BossFlame:
					obj1->Death();
					obj2->Death();
					break;
				case Entity::Tag_EnemyBat:
					break;
				case Entity::Tag_EnemyRino:
					break;
				case Entity::Tag_Character:
					obj2->Death();
					break;
				case Entity::Tag_CharacterBullet:
					obj1->Death();
					obj2->Death();
					break;
				default:
					break;
				}
			}
			else if (tag_obj1 == Entity::Tag_CharacterBullet)
			{
				switch (tag_obj2)
				{
				case Entity::Tag_Boss:
					
					break;
				case Entity::Tag_BossBullet:
					
					break;
				case Entity::Tag_BossFlame:
					
					break;
				case Entity::Tag_EnemyBat:
					obj1->Death();
					obj2->Death();
					break;
				case Entity::Tag_EnemyRino:
					obj1->Death();
					obj2->Death();
					break;
				case Entity::Tag_Character:
					break;
				case Entity::Tag_CharacterBullet:
					break;
				default:
					break;
				}
			}
		}
	}
}