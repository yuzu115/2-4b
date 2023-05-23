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

/******************************************************
*変数宣言
*******************************************************/
XINPUT_STATE input;
int Button_flg = FALSE;
int GameMode = 0;

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

	Player p;
	Apple app;

	app.AppleSet();
	p.LoadPlayerImg();

	//ScreenFlipを実行しても垂直同期信号を待たない
		//SetWaitVSyncFlag(FALSE);

	//ループ前にFPS計測を初期化
	Reset_fps();

	//// プレイヤー初期化
	//PlayerInit();

	// BACKボタンでプログラム終了
	while (ProcessMessage() == 0 && GameMode != CLOSE && !input.Buttons[XINPUT_BUTTON_BACK])
	{
		ClearDrawScreen();                 //画面を初期化

		GetJoypadXInputState(DX_INPUT_PAD1, &input);				// ゲームパッド(XInput)

		InputControl::Update();

		switch (GameMode) {
			case TITLE:
				DrawTitle(input,Button_flg,GameMode);		//ゲームタイトル描画処理
				break;
			//case INIT:
			//	GameInit(GameMode);							// ゲーム初期化
			//	break;
			case MAIN:
				DrawBox(0, 0, 1280, 720, 0xd3d3d3, TRUE);
				app.DrawApple();
				p.PlayerControl(g_OldKey, GameMode);

				//DrawApple();
				//PlayerControl(GameMode);						// プレイヤー操作(joypad)
				//PlayerXControl(input, Button_flg);						// プレイヤー操作(XInput)
				//PlayerXIControl(input);						// プレイヤー操作(XInput)
				//PlayerFlashing(Count, on, off);					// プレイヤー点滅
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
		DrawFormatString(0, 16, 0x00000, "ThumbLX:%d ThumbLY:%d",input.ThumbLX, input.ThumbLY);


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

		//if (Count > 120)Count = 0;
		
		//裏画面の内容を表画面に反映する
		ScreenFlip();

		//fps固定処理
		wait_fanc();

			//Count++;
			//off++;
			//on ++;
		
	}
	DxLib_End();

	return 0;
}

