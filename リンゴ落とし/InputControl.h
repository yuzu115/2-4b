#pragma once

#include "DxLib.h"

extern XINPUT_STATE input;

class InputControl
{
private:
	static int key_flg;
	static int now_key;
	static int old_key;

	static int Button_flg;

public:
	InputControl()
	{
		key_flg = 0;
		now_key = 0;
		old_key = 0;
	}

	static void Update();
	static int GetKey(int key);
	static int GetKeyDown(int key);

	static int GetStick(int key);			// スティックの入力判定
	static void Nullify(int key);			// パッド入力を無効化
};

