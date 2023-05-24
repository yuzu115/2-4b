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
#include "GameMain.h"
#include "Pause.h"
#include"Keyboard.h"

/******************************************************
*変数宣言
*******************************************************/
XINPUT_STATE input;
int Button_flg = FALSE;
int Pause_flg = FALSE;
int GameMode = 0;

//ランキングデータの変数宣言
RankingData Ranking[RANK_MAX];

int LoadImages();

//Count変数宣言
int RoopCount = 0;
int Count = 0;
int on = 0;
int off = 0;

// プログラムは WinMain から始まります
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	SetMainWindowText("リンゴ落とし");
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを設定
	SetGraphMode(SCREENSIZE_X,SCREENSIZE_Y,32);

	//ScreenFlipを実行しても垂直同期信号を待たない
	//SetWaitVSyncFlag(0);

	if (DxLib_Init() == -1) return -1;     //DXライブラリの初期化処理
	SetDrawScreen(DX_SCREEN_BACK);         //描画先画面を裏にする

	Player p;
	Apple app;

	app.AppleSet();
	p.LoadPlayerImg();

	//ScreenFlipを実行しても垂直同期信号を待たない
		//SetWaitVSyncFlag(FALSE);
	//画像読込
	/*各関数で読み込むと時間が掛かってFPSが大幅に遅れる為、
	ゲームループが始まる前にあらかじめ画像、サウンドなどを読み込む関数を作り
	先に読み込んでおく*/
	if (LoadImages() == -1)return -1;

	//ループ前にFPS計測を初期化
	Reset_fps();


	// BACKボタンでプログラム終了
	while (ProcessMessage() == 0 && GameMode != CLOSE && !input.Buttons[XINPUT_BUTTON_BACK])
	{
		ClearDrawScreen();                 //画面を初期化

		GetJoypadXInputState(DX_INPUT_PAD1, &input);				// ゲームパッド(XInput)

		//入力キー取得
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);		// ゲームパッド&キーボード
		g_KeyFlg = g_NowKey & ~g_OldKey;

		InputControl::Update();

		switch (GameMode) {
			case TITLE:
				DrawTitle(input,Button_flg,GameMode);		//ゲームタイトル描画処理

				break;
			//case INIT:
			//	GameInit(GameMode);							// ゲーム初期化
			//	break;
			case MAIN:

				GameMain(GameMode, input, Button_flg, Pause_flg);
				DrawUI(GameMode, RoopCount, Pause_flg);
				//DrawBox(0, 0, 1280, 720, 0xd3d3d3, TRUE);
			
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
		DrawFormatString(0, 16, 0xff0000, "ThumbLX:%d ThumbLY:%d",input.ThumbLX, input.ThumbLY);
		DrawFormatString(100, 100, 0x00ffff, "GameMode = %d",GameMode);

		if (input.Buttons[XINPUT_BUTTON_B] == 1)
		{
			GameMode = 6;
		}
		//app.DrawApple();
	
		//今出てるFPSの表示
		display_fps();

		//fpsの計測
		Keisoku_fps();

		//プレイヤー操作
		//p.PlayerControl(g_OldKey, GameMode);
		
		//PlayerFlashing(Count,on,off);

		if (GameMode == INPUTNAME)
		{
			DrawKeyboard();
		}

		if (Count == 121)Count = 0;
		if (RoopCount == 28)RoopCount = 0;
		

		//fpsの計測
		Keisoku_fps();
		//今出てるFPSの表示
		display_fps();

		//裏画面の内容を表画面に反映する
		ScreenFlip();

		//fps固定処理
		wait_fanc();

		RoopCount++;

			Count++;
			off++;
			on ++;
		
		
	}
	DxLib_End();

	return 0;
}


int LoadImages() {
	if(LoadTitleImages()==-1) return -1;
	if (LoadImg() == -1)return -1;
	if (LoadNumImg() == -1)return -1;
	//LoadImg();
	return 0;
}