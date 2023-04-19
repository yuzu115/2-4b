#include "End.h"

/****************************************
*　変数の宣言
*****************************************/
int EndBackImg;			// 背景画像

/****************************************
* エンド画面描画（エンドロール）
*****************************************/
int DrawEnd(void) {

	// 背景画像の読込
	if ((EndBackImg = LoadGraph("images/Back.png")) == -1) return -1;

	// 画像の表示
	DrawGraph(0, 0, EndBackImg, FALSE);

	SetFontSize(100);
	DrawFormatString(30, 20, 0x000000, "Thank you for playing!!!");
	
	SetFontSize(40);
	DrawString(100, 310 , "素材利用", 0x000000);
	DrawString(100, 370 , "　BGM　　　 　ＸＸＸＸ", 0x000000);
	DrawString(100, 410 , "　SE　　　　　ＸＸＸＸＸＸＸＸ", 0x000000);

}