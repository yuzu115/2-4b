#include "Title.h"

/****************************************
*　変数の宣言
*****************************************/
int TitleImg;			// タイトル画像

static int menuNo = 0;		// 0：START　1：RANKING　2：HELP　3：End
int posY;					// カーソルのY座標

int DrawTitle(void) {

	// タイトル画像の読込
	if ((TitleImg = LoadGraph("images/Title.png")) == -1) return -1;

	// 画像の表示
	DrawGraph(0, 0, TitleImg, FALSE);

	// メニューカーソル（三角形）の表示
	posY = menuNo * 100;
	DrawTriangle(810, 310 + posY, 840, 330 + posY, 810, 350 + posY, 0xff0000, TRUE);

	return 0;

}