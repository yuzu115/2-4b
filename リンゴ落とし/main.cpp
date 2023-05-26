#include"DxLib.h"
#include"math.h"
#include"infomation.h"
#include "TITLE.h"
#include "RANKING.h"
#include "HELP.h"
#include "END.h"
#include "Result.h"
#include"DrawApple.h"
#include"FPS.h"
#include"Player.h"
#include"InputControl.h"
#include"Keyboard.h"
#include "GameMain.h"
#include "GameInit.h"

/******************************************************
*変数宣言
*******************************************************/
XINPUT_STATE input;
int Button_flg = FALSE;
int GameMode = 0;
int Pause_flg=0;
int UsuallyBGM;
int BGMflg=1;
int on2f = 20;
int off2f = 20;
int FlCount = 0;

//ランキングデータの変数宣言
RankingData Ranking[RANK_MAX];


// プログラムは WinMain から始まります
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	SetMainWindowText("リンゴ落とし");
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを設定
	SetGraphMode(SCREENSIZE_X,SCREENSIZE_Y,32);

	if (DxLib_Init() == -1) return -1;     //DXライブラリの初期化処理
	SetDrawScreen(DX_SCREEN_BACK);         //描画先画面を裏にする

	//画像、効果音読込
	LoadImSE();

	ReadRanking(Ranking);		//ランキングデータの読込

	Player p;
	Apple app;

	//ScreenFlipを実行しても垂直同期信号を待たない
		//SetWaitVSyncFlag(FALSE);

	//ループ前にFPS計測を初期化
	Reset_fps();

	// BACKボタンでプログラム終了
	while (ProcessMessage() == 0 && GameMode != CLOSE && !input.Buttons[XINPUT_BUTTON_BACK])
	{
		ClearDrawScreen();                 //画面を初期化

		GetJoypadXInputState(DX_INPUT_PAD1, &input);				// ゲームパッド(XInput)

		ChangeVolumeSoundMem(170, UsuallyBGM);

		if (GameMode == 2) {
			if (BGMflg == 0) {
				StopSoundMem(UsuallyBGM);
			}
			BGMflg = 1;
		}
		else {
			if (BGMflg == 1) {
				PlaySoundMem(UsuallyBGM, DX_PLAYTYPE_LOOP);
			}
			BGMflg = 0;
		}

		switch (GameMode) {
			case TITLE:
				DrawTitle(input,Button_flg,GameMode);		//ゲームタイトル描画処理
				break;
			case INIT:
				GameInit(GameMode);
			case MAIN:
				GameMain(GameMode,input,Button_flg,Pause_flg);
				if (app.PoHit() == 1)p.PlayerFlashing();
				break;
			case INPUTNAME:
				InputName(Ranking,input,GameMode, Button_flg);   //　名前入力画面描画処理
				break;
			case RANKING:
				DrawRanking(input,Ranking, Button_flg,GameMode);		//ランキング描画処理
				break;
			case HELP:
				DrawHelp(input,Button_flg,GameMode);			//ヘルプ画面描画処理
				break;
			case END:
				DrawEnd(GameMode);			//エンド画面描画処理
				break;
			case RESULT:
				DrawResult(Ranking,GameMode);		//リザルト画面
				break;
		}


		////今出てるFPSの表示
		//display_fps();

		//fpsの計測
		Keisoku_fps();



		//if (GameMode == INPUTNAME)
		//{
		//	DrawKeyboard();
		//}

		
		//裏画面の内容を表画面に反映する
		ScreenFlip();

		//fps固定処理
		wait_fanc();		

	


	}
	DxLib_End();

	return 0;
}


int LoadImSE(void) {
	Player p;
	Apple app;
	if ((UsuallyBGM = LoadSoundMem("AppleSound/AppleBGM/スーパーでお買い物.wav")) == -1)return -1;
	LoadTitle();			//タイトル画像読込
	app.AppleSet();						//リンゴ読込
	p.LoadPlayerImg();					//プレイヤー画像読込
	LoadNumImg();
	LoadResultImages();					// リザルト画像読込
	LoadHelpImages();					// ヘルプ画像読込
	LoadEndImages();				// エンド画像読込
	LoadRankingImages();		// ランキング画像読込

	LoadInpNameImg();       // 名前入力画面画像読込
	LoadKeyBoardSounds();  // 名前入力画面SE読込

	return 0;
}
