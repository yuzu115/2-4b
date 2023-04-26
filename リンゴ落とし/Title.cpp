#include "Title.h"

void DrawTitle(void) {

	// タイトル画像の読込
	if ((TitleImg = LoadGraph("images/Title.bmp")) == -1) return -1;

	// タイトル画像、メニューカーソル（三角形）の表示
	DrawGraph(0, 0, TitleImg, FALSE);
	posY = menuNo * 45;
	DrawTriangle(140, 210 + posY, 170, 230 + posY, 140, 250 + posY, 0xff0000, TRUE);

}