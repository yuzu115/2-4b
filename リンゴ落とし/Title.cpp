#include "Title.h"


int DrawTitle(void) {

	// タイトル画像の読込
	if ((titleImg = LoadGraph("images/Title.png")) == -1) return -1;

	// タイトル画像、メニューカーソル（三角形）の表示
	DrawGraph(0, 0, titleImg, FALSE);
	posY = menuNo * 45;
	DrawTriangle(140, 210 + posY, 170, 230 + posY, 140, 250 + posY, 0xff0000, TRUE);

	//DrawFormatString(400, 220, 0xffffff, "タイトル");
}