#include "Title.h"

/****************************************
*　変数の宣言
*****************************************/
int TitleImg;			// タイトル画像
int AppleCursorImg;		// カーソル（赤リンゴ）画像

int menuNo = 0;		// 0：START　1：RANKING　2：HELP　3：END
int posY;					// カーソルのY座標

/****************************************
* タイトル画面描画
*****************************************/
int DrawTitle(int g_KeyFlg,int& GameMode) {

	// タイトル画像の読込
	if ((TitleImg = LoadGraph("images/Title.png")) == -1) return -1;
	// カーソル（赤リンゴ）画像
	if ((AppleCursorImg = LoadGraph("images/RedApple.png")) == -1) return -1;

	// メニューカーソル移動処理
	if (g_KeyFlg & PAD_INPUT_DOWN) {
		if (++menuNo > 3) menuNo = 0;
	}
	if (g_KeyFlg & PAD_INPUT_UP) {
		if (--menuNo < 0) menuNo = 3;
	}

	// Zキーでメニュー選択
	if (g_KeyFlg & PAD_INPUT_A) {
		switch (menuNo) {
		//case 0:
		//	GameMode = 1;			// INIT
		//	break;
		case 1:
			GameMode = 3;			// RANKING
			break;
		case 2:
			GameMode = 4;			// HELP
			break;
	 	case 3:
			GameMode = 7;			// END
			break;

		}
	}
	
	// タイトル画像の表示
	DrawGraph(0, 0, TitleImg, FALSE);

	// メニューカーソルの表示
	posY = menuNo * 100;

	// カーソル（赤リンゴ）を縮小描画
	DrawExtendGraph(790, 305 + posY, 880, 395 + posY, AppleCursorImg, TRUE);
	
	//// メニューカーソル（三角形）の表示
	//posY = menuNo * 100;
	//DrawTriangle(810, 325 + posY, 840, 345 + posY, 810, 365 + posY, 0xff0000, TRUE);

	//DrawFormatString(0, 0, 0xffffff, "menuNo %d", menuNo);

	return 0;

}