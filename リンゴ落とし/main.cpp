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

/******************************************************
*変数宣言
*******************************************************/
XINPUT_STATE input;
int Button_flg = FALSE;
int GameMode = 0;

//ランキングデータの変数宣言
RankingData Ranking[RANK_MAX];

int Time = 0;     //待ち時間
int StartTime;
int NowTime = 0;
int RefreshTime;
double Fps = 0.0;
int counter = 0, FpsTime[2] = { 0, }, FpsTime_i = 0;

// プログラムは WinMain から始まります
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	SetMainWindowText("リンゴ落とし");
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを設定
	SetGraphMode(SCREENSIZE_X,SCREENSIZE_Y,32);

	if (DxLib_Init() == -1) return -1;     //DXライブラリの初期化処理
	SetDrawScreen(DX_SCREEN_BACK);         //描画先画面を裏にする

	//ScreenFlipを実行しても垂直同期信号を待たない
		//SetWaitVSyncFlag(FALSE);

	//ループ前にFPS計測を初期化
	Reset_fps();

	//// プレイヤー初期化
	//PlayerInit();

	//ClearDrawScreen();                 //画面を初期化

	// BACKボタンでプログラム終了
	while (ProcessMessage() == 0 && GameMode != CLOSE && !input.Buttons[XINPUT_BUTTON_BACK])
	{
		RefreshTime = GetNowCount();

		GetJoypadXInputState(DX_INPUT_PAD1, &input);				// ゲームパッド(XInput)

		//入力キー取得
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);		// ゲームパッド&キーボード
		g_KeyFlg = g_NowKey & ~g_OldKey;

		ClearDrawScreen();                 //画面を初期化
		
		InputControl::Update();
		FpsTimeFanction();

		DrawFormatString(50, 60, 0x000000, "FPS %f", Fps); //fpsを表示

		switch (GameMode) {
			case TITLE:
				DrawTitle(input,Button_flg,GameMode);		//ゲームタイトル描画処理
				break;
			case MAIN:
				PlayerInit();								// プレイヤー初期化
				DrawBox(0, 0, 1280, 720, 0xd3d3d3, TRUE);
				DrawApple();
				PlayerControl(GameMode);						// プレイヤー操作
				//PlayerFlashing(Count, on, off);					// プレイヤー点滅
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
		DrawFormatString(0, 16, 0x00000, "ThumbLX:%d ThumbLY:%d",
			input.ThumbLX, input.ThumbLY);
		//DrawBox(0, 0, 1280, 720, 0xd3d3d3, TRUE);
		//DrawApple();
		
		//今出てるFPSの表示
		display_fps();

		//fpsの計測
		Keisoku_fps();
		
		// プレイヤー操作
		//PlayerControl(GameMode);
		
		PlayerFlashing(Count,on,off);

		//PlayerImg();
		//PlayerControl(GameMode);

		if (Count == 121)Count = 0;
		
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


void FpsTimeFanction() {
	if (FpsTime_i == 0)
		FpsTime[0] = GetNowCount();               //1周目の時間取得
	if (FpsTime_i == 49) {
		FpsTime[1] = GetNowCount();               //50周目の時間取得
		Fps = 1000.0f / ((FpsTime[1] - FpsTime[0]) / 50.0f);//測定した値からfpsを計算
		FpsTime_i = 0;//カウントを初期化
				DrawFormatString(50, 60, 0x000000, "FPS %.1f", Fps); //fpsを表示

	}
	else
		FpsTime_i++;//現在何周目かカウント
	if (Fps != 0)
		DrawFormatString(50, 60, 0x000000, "FPS %.1f", Fps); //fpsを表示
	return;
}