#pragma once
class KeyBoard
{
public:
	enum DKEY
	{
		DKEY_NULL = 0,
		DKEY_UP = 1,
		DKEY_DOWN = 2,
		DKEY_LEFT = 4,
		DKEY_RIGHT = 8,
		DKEY_FIRE=16,
	};

	KeyBoard();
	~KeyBoard();
	void HandleKeyEvents(int key, bool bIsPressed);
	int GetKey();
protected:
	int KeyPress;
};