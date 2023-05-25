#include"DxLib.h"
#include"Keyboard.h"

int gBackImg; // 背景画像
int gKeyImg[4];  // キーボード画像

int KeyboardLoadImg(void)
{
	// キーボード画像の読込
	if ((gKeyImg[0] = LoadGraph("images/キーボード.png")) == -1) return -1;
	// 背景画像の読込
	if ((gBackImg = LoadGraph("images/backname.png")) == -1) return -1;

	return 0;
}

void DrawKeyboard(void)
{

	// 背景画像の表示
	DrawExtendGraph(0, 0,1280,720,gBackImg, TRUE);
	// キーボード画像の表示
	DrawExtendGraph(200,230,1090,690 ,gKeyImg[0], TRUE);

	//DrawString(200, 240, "名前を入力してください", 0xffffff);
}