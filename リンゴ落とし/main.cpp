#include"DxLib.h"
#include"infomation.h"
#include "TITLE.h"
#include "HELP.h"
#include "END.h"

/********************************************************************
*　変数の宣言
********************************************************************/
int g_OldKey;                  //前回の入力キー
int g_NowKey;                  //今回の入力キー
int g_KeyFlg;                  //入力キー情報

int GameMode = 0;

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("リンゴ落とし");
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを設定
	SetGraphMode(SCREENSIZE_X,SCREENSIZE_Y,32);

	if (DxLib_Init() == -1) return -1;     //DXライブラリの初期化処理

	SetDrawScreen(DX_SCREEN_BACK);         //描画先画面を裏にする

	while (ProcessMessage() == 0 && GameMode != CLOSE && !(g_KeyFlg & PAD_INPUT_START))
	{
		//入力キー取得
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);		// ゲームパッドのボタン
		g_KeyFlg = g_NowKey & ~g_OldKey;
		
		switch (GameMode) {
			case TITLE:
				DrawTitle(g_KeyFlg,GameMode);		//ゲームタイトル描画処理
				break;
			case HELP:
				DrawHelp(g_KeyFlg,GameMode);		//ヘルプ画面描画処理
				break;
			case END:
				DrawEnd();							//エンド画面描画処理
				break;
		}

		ScreenFlip();	//裏画面の内容を表画面に反映

	}
	DxLib_End();	//DXライブラリ使用の終了処理

	return 0;	//ソフトの終了
}