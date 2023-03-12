#pragma once
#include "Character/Character.h"

class Player :
	public Character
{
public:
	Player();
	~Player();
	
	void Init(int width, int height, Vector2 pos);
	void ReciveKeyEvents(int key);
	
	void Update(float deltaTime);
};