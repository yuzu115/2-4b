#include "DxLib.h"
#include "Player.h"
#include "DrawApple.h"

//変数宣言
int RC=60;
int gNumImg[10];
int aR,aG,aY;


void DrawUI(int& GameMode,int& FC, int& Pause_flg) {
	
	DrawBox(950+114, 0, 1280, 720, 0xfff8dc, TRUE);


	if (Pause_flg == 0) {

		if (FC == 28) {
		RC -= 1;
		}

		if (RC == 0) {
			//60秒たったらリザルト画面へ移動
		//	GameMode = 6;
		}

	}


	//DrawGraph(posx, 30, gNumberImg[tempScore % 10], TRUE);

	DrawFormatString(1200, 120, 0xffffff, "RC:%d", RC);
	DrawFormatString(130, 140, 0x000000, "FC:%d", FC);

	//Time表示
	SetFontSize(52);
	DrawString(1070, 0, "TIME", 0x000000);
	SetFontSize(32);
	DrawString(1070, 60, "残り", 0x000000);
	//DrawBox(1090, 110, 1280, 240, 0xfff8dc, TRUE);
	DrawExtendGraph(1090, 90, 1190, 220, gNumImg[RC / 10], TRUE);
	DrawExtendGraph(1180, 90, 1280, 220, gNumImg[RC % 10], TRUE);

	//スコア仮表示
	SetFontSize(52);
	DrawString(1070, 240, "Score", 0x000000);
	DrawString(1110, 295, "000000", 0x000000);

	//リンゴ取った個数仮表示
	SetFontSize(42);
	DrawString(1070, 355, "獲得\n   りんご", 0x000000);
	//赤リンゴ
	DrawExtendGraph(1070, 430, 1160, 520, aR, TRUE);
	DrawString(1150, 475, " ×00", 0x000000);

	//緑リンゴ
	DrawExtendGraph(1070, 530, 1160, 620, aG, TRUE);
	DrawString(1150, 575, " ×00", 0x000000);

	//黄リンゴ
	DrawExtendGraph(1070, 630, 1160, 720, aY, TRUE);
	DrawString(1150, 675, " ×00", 0x000000);
}

void GameMain(int& GameMode,XINPUT_STATE input, int& Button_flg,int& Pause_flg){
	//PlayerInit();								// プレイヤー初期化
	DrawBox(0, 0, 1280, 720, 0xd3d3d3, TRUE);
	DrawApple(Pause_flg);
	PlayerControl(GameMode,Pause_flg);					// プレイヤー操作
	//PlayerFlashing(Count, on, off);					// プレイヤー点滅

		
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

int LoadNumImg() {

	if (LoadDivGraph("images/Numbers.png", 10, 10, 1, 104, 152, gNumImg) == -1)return -1;
	aR = LoadGraph("images/RedApple.png");
	aG = LoadGraph("images/GreenApple.png");
	aY = LoadGraph("images/GoldApple.png");
}