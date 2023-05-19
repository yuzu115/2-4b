#include "InputControl.h"

int InputControl::key_flg;
int InputControl::now_key;
int InputControl::old_key;

int InputControl::Button_flg;

void InputControl::Update()
{
	old_key = now_key;
	now_key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	key_flg = now_key & ~old_key;

	//GetJoypadXInputState(DX_INPUT_PAD1, &input);			// XInput
	Button_flg = FALSE;
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
