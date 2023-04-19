#include"DxLib.h"
#include"infomation.h"
#include"Player.h"

/********************************************************************
*　変数の宣言
********************************************************************/
int g_OldKey;                  //前回の入力キー
int g_NowKey;                  //今回の入力キー
int g_KeyFlg;                  //入力キー情報

int GameMode;     //モード

int g_Score;      //スコア


// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("リンゴ落とし");
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを設定
	SetGraphMode(SCREENSIZE_X,SCREENSIZE_Y,32);

	if (DxLib_Init() == -1) return -1;     //DXライブラリの初期化処理
	SetDrawScreen(DX_SCREEN_BACK);         //描画先画面を裏にする

	GameMode = MAIN2;

	PlayerInit();

	while (ProcessMessage() == 0 && GameMode != CLOSE && !(g_KeyFlg & PAD_INPUT_START))
	{
		//キー入力取得 
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);    //例のコントローラーの入力も使えます
		g_KeyFlg = g_NowKey & ~g_OldKey;

		ClearDrawScreen();                 //画面を初期化

		//DrawBox(0, 0, 1280, 720, 0xd3d3d3, TRUE);

		if (GameMode == MAIN2)
		{
			PlayerControl(g_OldKey,GameMode);
			HitBoxPlayer();
		}

		ScreenFlip();

	}

	DxLib_End();				           // ＤＸライブラリ使用の終了処理

	return 0;				               // ソフトの終了 
}

