#include "InputControl.h"

int InputControl::key_flg;
int InputControl::now_key;
int InputControl::old_key;


void InputControl::Update()
{
	old_key = now_key;
	now_key = GetJoypadXInputState(DX_INPUT_PAD1, &input);
	key_flg = now_key & ~old_key;
}

int InputControl::GetKey(int key)
{
	if (now_key & key)
	{
		return TRUE;
	}

	return FALSE;
}

int InputControl::GetKeyDown(int key)
{
	if (key_flg & key)
	{
		return TRUE;
	}

	return FALSE;
}
