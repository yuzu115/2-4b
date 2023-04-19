#include "Help.h"

/****************************************
*　変数の宣言
*****************************************/
int HelpBackImg;		// 背景画像

/****************************************
* ヘルプ画面描画
*****************************************/
int DrawHelp(int g_KeyFlg,int& GameMode) {

	// 背景画像の読込
	if ((HelpBackImg = LoadGraph("images/Back.png")) == -1) return -1;

	// Aボタンでタイトルへ
	if (g_KeyFlg & PAD_INPUT_A) {
		GameMode = 0;					// タイトル画面へ
	}
	// Bボタンでゲームスタート
	if (g_KeyFlg & PAD_INPUT_B) {
		//GameMode = 1;					// ゲームスタートへ
		GameMode = 7;					// エンドへ
	}

	// 画像の表示
	DrawGraph(0, 0, HelpBackImg, FALSE);

	SetFontSize(100);
	DrawFormatString(500, 10, 0x000000, "操作説明");

	SetFontSize(50);
	DrawFormatString(200, 600, 0xffffff, "A：タイトルへ");
	DrawFormatString(700, 600, 0xffffff, "B：エンドへ");

	return 0;
}