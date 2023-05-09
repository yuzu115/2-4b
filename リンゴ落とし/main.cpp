#include"DxLib.h"
#include"infomation.h"
#include "TITLE.h"
#include "RANKING.h"
#include "HELP.h"
#include "END.h"

/******************************************************
*変数宣言
*******************************************************/
XINPUT_STATE input;
int Button_flg = FALSE;
int GameMode = 0;

/****************************************************
*プログラムの開始
******************************************************/
// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("リンゴ落とし");
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを設定
	SetGraphMode(SCREENSIZE_X,SCREENSIZE_Y,32);

	if (DxLib_Init() == -1) return -1;     //DXライブラリの初期化処理

	SetDrawScreen(DX_SCREEN_BACK);         //描画先画面を裏にする

	while (ProcessMessage() == 0 && GameMode != CLOSE && !input.Buttons[XINPUT_BUTTON_BACK])
	{
		GetJoypadXInputState(DX_INPUT_PAD1, &input);				// ゲームパッド

		////入力キー取得
		//g_OldKey = g_NowKey;
		//g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);		// ゲームパッド&キーボード
		//g_KeyFlg = g_NowKey & ~g_OldKey;
		
		switch (GameMode) {
			case TITLE:
				DrawTitle();		//ゲームタイトル描画処理
				break;
			case RANKING:
				DrawRanking();		//ゲームタイトル描画処理
				break;
			case HELP:
				DrawHelp();		//ヘルプ画面描画処理
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