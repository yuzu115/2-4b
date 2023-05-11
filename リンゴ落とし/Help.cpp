#include "DxLib.h"
#include "infomation.h"
#include "Help.h"

/****************************************
*　変数の宣言
*****************************************/
int HelpBackImg;		// 背景画像

/****************************************
* ヘルプ画面描画
*****************************************/
int DrawHelp(int& GameMode)
{
	// 背景画像の読込
	if ((HelpBackImg = LoadGraph("images/Back.png")) == -1) return -1;

	if (input.Buttons[12] == 0) {
		Button_flg = FALSE;
	}

	// Aボタンでタイトルへ
	if (input.Buttons[12] == 1 && Button_flg == FALSE) {
		Button_flg = TRUE;
		GameMode = 0;					// TITLE
	}
	// Bボタンでゲームスタート
	if (input.Buttons[13] == 1 && Button_flg == FALSE) {
		Button_flg = TRUE;
		//GameMode = 1;					// INIT
		GameMode = 7;					// END
	}

	// 画像の表示
	DrawGraph(0, 0, HelpBackImg, FALSE);

	SetFontSize(100);
	DrawFormatString(450, 100, 0x000000, "操作説明");

	SetFontSize(70);
	DrawFormatString(100, 310, 0x000000, "左スティック  左右移動");
	DrawFormatString(100, 410, 0x000000, "STARTボタン　 ポーズ/ポーズ解除");

	SetFontSize(30);
	DrawFormatString(400, 650, 0x000000, "A：タイトル");
	DrawFormatString(800, 650, 0x000000, "B：エンド");

	return 0;
}