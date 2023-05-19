#include "DxLib.h"
#include "Player.h"
#include "DrawApple.h"
#include "Pause.h"

//変数宣言
//int Pause_flg = 0;//flg 0押されてない時 flg 1押されてる時


void GameMain(int& GameMode,XINPUT_STATE input, int& Button_flg,int& Pause_flg) {
	//PlayerInit();								// プレイヤー初期化
	DrawBox(0, 0, 1280, 720, 0xd3d3d3, TRUE);
	DrawApple(Pause_flg);
	PlayerControl(GameMode);					// プレイヤー操作
	//PlayerFlashing(Count, on, off);					// プレイヤー点滅

		// STARTボタンでメニュー選択
		if (input.Buttons[XINPUT_BUTTON_START] == 1 && Button_flg == TRUE)
		{
		//いんぷっとボタンを入力一回だけ受け取ってフラグを切り替える
			
		}


		DrawFormatString(0, 120, 0x000000, "Pause_flg:%d", Pause_flg);

}