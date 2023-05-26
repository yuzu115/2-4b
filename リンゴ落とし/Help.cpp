#include "DxLib.h"
#include "Help.h"

/****************************************
*　変数の宣言
*****************************************/
int HelpImg;				// ヘルプ画像

/****************************************
* ヘルプ画面描画
*****************************************/
void DrawHelp(XINPUT_STATE input, int& Button_flg, int& GameMode)
{

	if (input.Buttons[12] == 0) {
		Button_flg = FALSE;
	}

	// Aボタンでタイトルへ
	if (input.Buttons[XINPUT_BUTTON_A] == 1 && Button_flg == FALSE) {
		Button_flg = TRUE;
		GameMode = 0;					// TITLE
	}
	// Bボタンでゲームスタート
	if (input.Buttons[XINPUT_BUTTON_B] == 1 && Button_flg == FALSE) {
		Button_flg = TRUE;
		GameMode = 1;					// INIT
		//GameMode = 9;					// END
	}

	// 画像の表示
	DrawGraph(0, 0, HelpImg, FALSE);

}

/****************************************
* ヘルプ画像読込
*****************************************/
int LoadHelpImages(void)
{
	// ヘルプ画像の読込
	if ((HelpImg = LoadGraph("images/help.png")) == -1) return -1;

	return 0;
}