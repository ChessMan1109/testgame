#include "keyBoard.h"

KeyBoard::KeyBoard()
{
	KeyPress = 0;
}
KeyBoard::~KeyBoard()
{
}
void KeyBoard::HandleKeyEvents(int key, bool bIsPressed)
{
	if (bIsPressed==true)
	{
		switch (key)
		{
		case 'W':
			KeyPress |= DKEY_UP;
			break;
		case 'A':
			KeyPress |= DKEY_LEFT;
			break;
		case 'S':
			KeyPress |= DKEY_DOWN;
			break;
		case'D':
			KeyPress |= DKEY_RIGHT;
			break;
		case ' ':
			KeyPress |= DKEY_FIRE;
			break;
		default:
			break;
		}
	}
	else
	{
		switch (key)
		{
		case 'W':
			KeyPress ^= DKEY_UP;
			break;
		case 'A':
			KeyPress ^= DKEY_LEFT;
			break;
		case 'S':
			KeyPress ^= DKEY_DOWN;
			break;
		case'D':
			KeyPress ^= DKEY_RIGHT;
			break;
		case ' ':
			KeyPress ^= DKEY_FIRE;
			break;
		default:
			break;
		}
	}
}
int KeyBoard::GetKey()
{
	return KeyPress;
}