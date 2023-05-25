#include "DxLib.h"
#include "Title.h"

/****************************************
*　変数の宣言
*****************************************/
int TitleImg;			// タイトル画像
int AppleCursorImg;		// カーソル（赤リンゴ）画像

int menuNo = 0;			// 0：START　1：RANKING　2：HELP　3：END
int posY;				// カーソルのY座標

/****************************************
* タイトル画面描画
*****************************************/
void DrawTitle(XINPUT_STATE input, int& Button_flg, int& GameMode)
{
	LoadTitleImages();		// タイトル画像読込

	// 左スティックでメニューカーソル移動処理
	if (input.ThumbLY < 128 && Button_flg == FALSE) {
		Button_flg = TRUE;
		if (++menuNo > 3) menuNo = 0;
	}
	if (input.ThumbLY > 128 && Button_flg == FALSE) {
		Button_flg = TRUE;
		if (--menuNo < 0) menuNo = 3;
	}
	if (input.ThumbLY == 128 && input.Buttons[XINPUT_BUTTON_A] == 0) {
		Button_flg = FALSE;
	}

	// Aボタンでメニュー選択
	if (input.Buttons[XINPUT_BUTTON_A] == 1 && Button_flg == FALSE) {
		Button_flg = TRUE;

		switch (menuNo) {
		case 0:
			GameMode = 2;			// MAIN
			//GameMode = 6;			// RESULT
			break;
		case 1:
			GameMode = 3;			// RANKING
			break;
		case 2:
			GameMode = 4;			// HELP
			break;
	 	case 3:
			GameMode = 9;			// END
			break;
		}
	}
	
	// タイトル画像の表示
	DrawGraph(0, 0, TitleImg, FALSE);

	// メニューカーソルの表示
	posY = menuNo * 100;

	// カーソル（赤リンゴ）を縮小描画
	DrawExtendGraph(790, 305 + posY, 880, 395 + posY, AppleCursorImg, TRUE);
}

/****************************************
* タイトル画像読込
*****************************************/
int LoadTitleImages(void)
{
	// タイトル画像の読込
	if ((TitleImg = LoadGraph("images/title.png")) == -1) return -1;
	// カーソル（赤リンゴ）画像
	if ((AppleCursorImg = LoadGraph("images/apple.png")) == -1) return -1;

	return 0;
}