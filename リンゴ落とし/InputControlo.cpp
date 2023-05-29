#include "InputControl.h"

int InputControl::key_flg;
int InputControl::now_key;
int InputControl::old_key;

int InputControl::Button_flg;

void InputControl::Update()
{
//	old_key = now_key;
////	now_key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
//	now_key = GetJoypadXInputState(DX_INPUT_PAD1, &input);
//	key_flg = now_key & ~old_key;

	GetJoypadXInputState(DX_INPUT_PAD1, &input);
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

int InputControl::GetStick(int key)
{
	if (key > 128 && Button_flg == FALSE)
	{
		Button_flg = TRUE;
		return TRUE;
	}

	return FALSE;
}

void InputControl::Nullify(int key)
{
	if (key == 128)
	{
		Button_flg = FALSE;
	}

}