#include "DxLib.h"
#include "Player.h"
#include "DrawApple.h"
#include "Pause.h"

//変数宣言
//int Pause_flg = 0;//flg 0押されてない時 flg 1押されてる時
int RC=60;

void DrawUI(int& FC) {
	
	DrawBox(950+114, 0, 1280, 720, 0x00000, TRUE);

	if (FC == 28) {
		RC -= 1;
	}

	if (RC == 0) {
		RC = 60;
		DrawBox(950 + 114, 0, 1280, 720, 0xffffff, TRUE);
	}


	DrawFormatString(1200, 120, 0xffffff, "RC:%d", RC);
	DrawFormatString(130, 140, 0x000000, "FC:%d", FC);

}

void GameMain(int& GameMode,XINPUT_STATE input, int& Button_flg,int& Pause_flg){
	//PlayerInit();								// プレイヤー初期化
	DrawBox(0, 0, 1280, 720, 0xd3d3d3, TRUE);
	DrawApple(Pause_flg);
	PlayerControl(GameMode,Pause_flg);					// プレイヤー操作
	//PlayerFlashing(Count, on, off);					// プレイヤー点滅

		// STARTボタンでメニュー選択
		/*if (input.Buttons[XINPUT_BUTTON_START] == 1 && Button_flg == TRUE&& Pause_flg == 0)
		{
			Button_flg = FALSE;
			Pause_flg = 1;

		}
		
		if (input.Buttons[XINPUT_BUTTON_START] == 1 && Pause_flg == 1&& Button_flg == TRUE) {
			Pause_flg = 0;
		}*/
		
	//ポーズ処理
		if (input.Buttons[XINPUT_BUTTON_START] == 1&& Button_flg == TRUE) {
			Button_flg = FALSE;

			//Pause_flg=1 :ポーズ中
			//Pause_flg=0 :ポーズ解除中
			if (Pause_flg == 0) {
				Pause_flg = 1;
			}
			else {
				Pause_flg = 0;
			}
		}

		if (input.Buttons[XINPUT_BUTTON_START] == 0&& Button_flg == FALSE) {
			Button_flg = TRUE;
		}


		DrawFormatString(0, 120, 0x000000, "Pause_flg:%d", Pause_flg);
		DrawFormatString(0, 140, 0x000000, "b_flg:%d", Button_flg);
		//DrawUI(int& FC);
}
