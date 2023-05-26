#include "DxLib.h"
#include "Player.h"
#include "DrawApple.h"
#include "Pause.h"
#include"Keyboard.h"


//変数宣言
int RoopC = 60;
int FC = 0;
int gNumImg[10];
int aR, aG, aY;
int rc;			// 赤リンゴの獲得数
int bc;			// 青リンゴの獲得数
int gc;			// 金リンゴの獲得数
int Mainbgmflg=1;
int MainBGM;
int MainImg;
int TF;			//0 FALSE: 1 TRUE

Apple apgetscore;

Apple AInit;
Player PInit;

void GetAppCount(Apple::AppScore* as)
{
	rc = as->r;
	bc = as->b;
	gc = as->g;
}

void DrawUI(int& GameMode, int& FC, int& Pause_flg) {


	// 背景画像の表示
	DrawGraph(0, 0, MainImg, FALSE);

	DrawBox(950 + 114, 0, 1280, 720, 0xfff8dc, TRUE);

	if (Pause_flg == 0) {

		if (FC == 28) {
			RoopC -= 1;
		}

		if (RoopC == 0) {
			//60秒たったらリザルト画面へ移動

			Mainbgmflg = 1;
			StopSoundMem(MainBGM);
			RoopC = 60;
			GameMode = 6; 
			TF = 1;
		}

	}

	ChangeVolumeSoundMem(200, MainBGM);
	if (Pause_flg == 1 && Mainbgmflg==0) {
		Mainbgmflg = 1;
		StopSoundMem(MainBGM);
		TF = 0;
	}
	
		if (Mainbgmflg == 1 && GameMode==2 && Pause_flg==0)
		{
			PlaySoundMem(MainBGM, DX_PLAYTYPE_LOOP,TF);
			Mainbgmflg = 0;

		}
	




	//Time表示
	SetFontSize(52);
	DrawString(1070, 0, "TIME", 0x000000);
	SetFontSize(32);
	DrawString(1070, 60, "残り", 0x000000);
	DrawExtendGraph(1090, 90, 1190, 220, gNumImg[RoopC / 10], TRUE);
	DrawExtendGraph(1180, 90, 1280, 220, gNumImg[RoopC % 10], TRUE);

	//スコア仮表示
	SetFontSize(52);
	DrawString(1070, 240, "Score", 0x000000);
	DrawFormatString(1110, 295, 0x000000, "%5d", apgetscore.GetScore());

	//リンゴ取った個数仮表示
	SetFontSize(42);
	DrawString(1070, 355, "獲得\n   りんご", 0x000000);
	//赤リンゴ
	DrawExtendGraph(1070, 430, 1160, 520, aR, TRUE);
	DrawFormatString(1150, 475, 0x000000, "x%d", rc);

	//緑リンゴ
	DrawExtendGraph(1070, 530, 1160, 620, aG, TRUE);
	DrawFormatString(1150, 575, 0x000000, "x%d", bc);

	//黄リンゴ
	DrawExtendGraph(1070, 630, 1160, 720, aY, TRUE);
	DrawFormatString(1150, 675, 0x000000, "x%d", gc);
}

void GameMain(int& GameMode, XINPUT_STATE input, int& Button_flg, int& Pause_flg)
{

	DrawBox(0, 0, 1280, 720, 0xd3d3d3, TRUE);
	DrawUI(GameMode, FC, Pause_flg);

	if (FC == 28) {

		FC = 0;
	}

	AInit.DrawApple(Pause_flg);
	PInit.PlayerXControl(input, Pause_flg);					// プレイヤー操作


	//ポーズ処理
	if (input.Buttons[XINPUT_BUTTON_START] == 1 && Button_flg == TRUE) {
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

	if (input.Buttons[XINPUT_BUTTON_START] == 0 && Button_flg == FALSE) {
		Button_flg = TRUE;
	}


	//DrawUI(int& FC);
	FC += 1;
}


int LoadNumImg() {

	// 背景画像の読込
	if ((MainImg = LoadGraph("images/back.png")) == -1) return -1;

	if (LoadDivGraph("images/Numbers.png", 10, 10, 1, 104, 152, gNumImg) == -1)return -1;
	aR = LoadGraph("images/Apple_Red.png");
	aG = LoadGraph("images/Apple_Blue.png");
	aY = LoadGraph("images/Apple_Gold.png");

	if ((MainBGM = LoadSoundMem("AppleSound/AppleBGM/今日も元気にオモテナシ.wav")) == -1)return -1;
}

void GameInit(int& GameMode)
{
	//キーボード初期化
	KeyBoardInit();
	GameMode = 2;
}