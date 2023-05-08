#include "DxLib.h"
#include "End.h"

/****************************************
*　変数の宣言
*****************************************/
int EndImg;				// エンド画像

//int	g_WaitTime = 0;			// 待ち時間
//int g_PosY;					// スクロール時のＹ座標

/****************************************
* エンド画面描画（エンドロール）
*****************************************/
int DrawEnd(int& GameMode) {

	// エンド画像の読込
	if ((EndImg = LoadGraph("images/Back.png")) == -1) return -1;

	// エンド画像の表示
	DrawGraph(0, 0, EndImg, FALSE);

	//エンディング表示
	//if (++g_WaitTime < 600) g_PosY = 300 - g_WaitTime / 2;

	SetFontSize(100);
	DrawFormatString(30, 20, 0x000000, "Thank you for playing!!!");
	
	SetFontSize(40);
	DrawString(100, 310 , "素材利用", 0x000000);
	DrawString(100, 370 , "　BGM　　　 　ＸＸＸＸ", 0x000000);
	DrawString(100, 410 , "　SE　　　　　ＸＸＸＸＸＸＸＸ", 0x000000);

	////タイムの加算処理＆終了
	//if (++g_WaitTime > 900)
	//{
	//	GameMode = 8;
	//}
	return 0;
}