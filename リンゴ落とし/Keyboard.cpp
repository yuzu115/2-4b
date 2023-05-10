#include"DxLib.h"
#include"Keyboard.h"

int gBackImg; // 背景画像
int gKeyImg;  // キーボード画像

int LoadImg(void)
{
	// キーボード画像の読込
	if ((gKeyImg = LoadGraph("images/タイトルなし.png")) == -1) return -1;
	// 背景画像の読込
	if ((gBackImg = LoadGraph("images/背景２.png")) == -1) return -1;

	return 0;
}

void DrawKeyboard(void)
{
	// 画像読み込み関数を呼び出し
	LoadImg();

	

	DrawExtendGraph(0, 0, 1280, 720, gBackImg, TRUE);
	DrawExtendGraph(0, 100, 1280, 620, gKeyImg, TRUE);

	DrawString(200, 240, "名前を入力してください", 0xffffff);
}