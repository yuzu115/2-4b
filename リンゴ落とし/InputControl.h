#pragma once

#include "DxLib.h"
//XINPUT_STATE input;

class InputControl
{
private:
	static int key_flg;
	static int now_key;
	static int old_key;

	static int Button_flg;				// 入力があるか
	static XINPUT_STATE input;

public:
	InputControl()
	{
		key_flg = 0;
		now_key = 0;
		old_key = 0;
		Button_flg = FALSE;
	}

	static void Update();
	static int GetKey(int key);
	static int GetKeyDown(int key);


	static int GetUpStick();				// 左スティック（上）
	static int GetDownStick();				// 左スティック（下）
	static int GetButton();				// ボタン
	static void ChangeFlg();
	static void DrawFlg();
};