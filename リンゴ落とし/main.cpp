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
		GetJoypadXInputState(DX_INPUT_PAD1, &input);				// ゲームパッド(XInput)

		//入力キー取得
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);		// ゲームパッド&キーボード
		g_KeyFlg = g_NowKey & ~g_OldKey;

		ClearDrawScreen();                 //画面を初期化
		
		InputControl::Update();

		//g_OldKey = g_NowKey;
		//g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);    //例のコントローラーの入力も使えます
		//g_KeyFlg = g_NowKey & ~g_OldKey;
		
		switch (GameMode) {
			case TITLE:
				DrawTitle(input,Button_flg,GameMode);		//ゲームタイトル描画処理
				break;
			case MAIN:
				PlayerInit();						// プレイヤー初期化
				DrawBox(0, 0, 1280, 720, 0xd3d3d3, TRUE);
				DrawApple();
				// プレイヤー操作
				PlayerControl(g_OldKey, GameMode);
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
		//ClearDrawScreen();                 //画面を初期化



		//DrawBox(0, 0, 1280, 720, 0xd3d3d3, TRUE);
		//DrawApple();
		
		//今出てるFPSの表示
		display_fps();

		//fpsの計測
		Keisoku_fps();
		
		// プレイヤー操作
		//PlayerControl(GameMode);

		//PlayerFlashing(Count,on,off);

		//PlayerImg();
		PlayerControl(g_OldKey, GameMode);

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
