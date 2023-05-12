#include "DxLib.h"
#include "End.h"

/****************************************
*　変数の宣言
*****************************************/
int EndBackImg;				// 背景画像

int WaitTime = 0;			// 待ち時間
int PosY;					// スクロール時のＹ座標

/****************************************
* エンド画面描画（エンドロール）
*****************************************/
void DrawEnd(int& GameMode)
{
	LoadEndImages();				// エンド画像読込

	// エンド画像の表示
	DrawGraph(0, 0, EndBackImg, FALSE);

	//エンディング表示(仮)
	if (++WaitTime < 600) PosY = 300 - WaitTime / 2;

	SetFontSize(30);
	DrawFormatString(0, 0, 0x000000, "WaitTime%4d", WaitTime);

	SetFontSize(100);
	DrawFormatString(30, 20, 0x000000, "Thank you for playing!!!");
		
	SetFontSize(40);
	DrawFormatString(100, 310 + PosY, 0x000000, "素材利用");
	DrawFormatString(100, 370 + PosY, 0x000000, "　BGM　　　 　ＸＸＸＸ");
	DrawFormatString(100, 410 + PosY, 0x000000, "　SE　　　　　ＸＸＸＸＸＸＸＸ");

	//タイムの加算処理＆300f経過後終了(仮)
	if (++WaitTime > 900)
	{
		GameMode = 8;				// CLOSE
	}

}

/****************************************
* エンド画像読込
*****************************************/
int LoadEndImages(void)
{
	// 背景画像の読込
	if ((EndBackImg = LoadGraph("images/Back.png")) == -1) return -1;

	return 0;
}