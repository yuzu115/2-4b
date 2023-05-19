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

	//画像読込
	/*各関数で読み込むと時間が掛かってFPSが大幅に遅れる為、
	ゲームループが始まる前にあらかじめ画像、サウンドなどを読み込む関数を作り
	先に読み込んでおく*/
	if (LoadImages() == -1)return -1;

	//ループ前にFPS計測を初期化
	Reset_fps();

	//// プレイヤー初期化
	PlayerInit();


	// BACKボタンでプログラム終了
	while (ProcessMessage() == 0 && GameMode != CLOSE && !input.Buttons[XINPUT_BUTTON_BACK])
	{
	
		GetJoypadXInputState(DX_INPUT_PAD1, &input);				// ゲームパッド(XInput)

		//入力キー取得
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);		// ゲームパッド&キーボード
		g_KeyFlg = g_NowKey & ~g_OldKey;

		ClearDrawScreen();                 //画面を初期化
		
		InputControl::Update();


		switch (GameMode) {
			case TITLE:
				DrawTitle(input,Button_flg,GameMode);		//ゲームタイトル描画処理
				//GameMain(GameMode);
				break;
			case MAIN:
				GameMain(GameMode,input,Button_flg,Pause_flg);

				break;
			case RANKING:
				DrawRanking(input,Ranking, Button_flg,GameMode);		//ランキング描画処理
				break;
			case HELP:
				DrawHelp(input,Button_flg,GameMode);			//ヘルプ画面描画処理
				break;
			case END:
				DrawEnd(GameMode, Count);			//エンド画面描画処理
				break;
			case RESULT:
				DrawResult(Ranking,GameMode);		//リザルト画面
				break;
		}


		DrawFormatString(50, 60, 0xffffff, "GameMode %d", GameMode);
		//DrawBox(0, 0, 1280, 720, 0xd3d3d3, TRUE);
		//DrawApple();


		// プレイヤー操作
		//PlayerControl(GameMode);
		
		//PlayerFlashing(Count,on,off);

		//PlayerImg();
		//PlayerControl(GameMode);

		if (Count == 121)Count = 0;
		

		//fpsの計測
		Keisoku_fps();
		//今出てるFPSの表示
		display_fps();

		//裏画面の内容を表画面に反映する
		ScreenFlip();

		//fps固定処理
		wait_fanc();

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
	//LoadImg();
	return 0;
}