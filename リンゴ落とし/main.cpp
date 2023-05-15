#include "DxLib.h"
#include "infomation.h"
#include "TITLE.h"
//#include "RANKING.h"
//#include "HELP.h"
//#include "END.h"
//#include "Result.h"
#include "InputControl.h"

/******************************************************
*変数宣言
*******************************************************/
XINPUT_STATE input;
//int Button_flg = FALSE;
int GameMode = 0;

//ランキングデータの変数宣言
//RankingData Ranking[RANK_MAX];

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

	// BACKボタンでプログラム終了
	while (ProcessMessage() == 0 && GameMode != CLOSE && !input.Buttons[XINPUT_BUTTON_BACK])
	{
		//GetJoypadXInputState(DX_INPUT_PAD1, &input);				// ゲームパッド(XInput)

		InputControl::Update();				// 入力キーの取得

		switch (GameMode) {
			case TITLE:
				DrawTitle(GameMode);		//ゲームタイトル描画処理
				break;
			//case RANKING:
			//	DrawRanking(input,Ranking, Button_flg,GameMode);		//ランキング描画処理
			//	break;
			//case HELP:
			//	DrawHelp(input,Button_flg,GameMode);			//ヘルプ画面描画処理
			//	break;
			//case END:
			//	DrawEnd(GameMode);			//エンド画面描画処理
			//	break;
			//case RESULT:
			//	DrawResult(Ranking,GameMode);		//リザルト画面
			//	break;
		}

		ScreenFlip();	//裏画面の内容を表画面に反映

	}
	DxLib_End();	//DXライブラリ使用の終了処理

	return 0;	//ソフトの終了
}