#include "Title.h"

/****************************************
*　変数の宣言
*****************************************/
int TitleImg;			// タイトル画像

static int menuNo = 0;		// 0：START　1：RANKING　2：HELP　3：End
int posY;					// カーソルのY座標

int DrawTitle(int g_KeyFlg) {

	// タイトル画像の読込
	if ((TitleImg = LoadGraph("images/Title.png")) == -1) return -1;

	// メニューカーソル移動処理
	if (g_KeyFlg & PAD_INPUT_DOWN) {
		if (++menuNo > 3) menuNo = 0;
	}
	if (g_KeyFlg & PAD_INPUT_UP) {
		if (--menuNo < 0) menuNo = 3;
	}


	// Zキーでメニュー選択
	//if (g_KeyFlg & PAD_INPUT_A) {
	//	switch (menuNo) {
	//	case 0:
	//		GameMode = INIT;
	//		break;
	//	case 1:
	//		GameMode = RANKING;
	//		break;
	//	case 2:
	//		GameMode = HELP;
	//		break;
 //		case 3:
	//		GameMode = END;
	//		break;

	//	}
	//}


	// 画像の表示
	DrawGraph(0, 0, TitleImg, FALSE);

	// メニューカーソル（三角形）の表示
	posY = menuNo * 100;
	DrawTriangle(810, 310 + posY, 840, 330 + posY, 810, 350 + posY, 0xff0000, TRUE);

	return 0;

}