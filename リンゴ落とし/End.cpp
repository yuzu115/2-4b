#include "DxLib.h"
#include "End.h"

/****************************************
*　変数の宣言
*****************************************/
//int EndImg;					// エンド画像
//
//int EndWaitTime = 0;			// 待ち時間
//int PosY;					// スクロール時のＹ座標

End::End()
{
	EndImg = 0;
	EndWaitTime = 0;
	PosY = 0;
}

End::~End()
{

}

/****************************************
* エンド画面描画（エンドロール）
*****************************************/
void End::DrawEnd(int& gameMode)
{
	// エンド画像の表示
	DrawGraph(0, 0, EndImg, FALSE);

	//エンディング表示(仮)
	if (++EndWaitTime < 250) PosY = 250 - EndWaitTime;

	SetFontSize(50);
	DrawFormatString(10, 150, 0x000000, "WaitTime%4d", EndWaitTime);

	SetFontSize(40);
	DrawFormatString(100, 310 + PosY, 0x000000, "素材利用");
	DrawFormatString(100, 370 + PosY, 0x000000, "　BGM　　　 　ＸＸＸＸ");
	DrawFormatString(100, 410 + PosY, 0x000000, "　SE　　　　　ＸＸＸＸＸＸＸＸ");

	//タイムの加算処理＆300f経過後終了(仮)
	if (EndWaitTime >= 300)
	{
		gameMode = 8;				// CLOSE
	}

}

/****************************************
* エンド画像読込
*****************************************/
int End::LoadEndImages(void)
{
	// エンド画像の読込
	if ((EndImg = LoadGraph("images/end.png")) == -1) return -1;

	return 0;
}

/****************************************
* エンド画面描画（エンドロール）
*****************************************/
//void DrawEnd(int& GameMode)
//{
//	// エンド画像の表示
//	DrawGraph(0, 0, EndImg, FALSE);
//
//	//エンディング表示(仮)
//	if (++EndWaitTime < 250) PosY = 250 - EndWaitTime;
//
//	SetFontSize(50);
//	DrawFormatString(10, 150, 0x000000, "WaitTime%4d", EndWaitTime);
//		
//	SetFontSize(40);
//	DrawFormatString(100, 310 + PosY, 0x000000, "素材利用");
//	DrawFormatString(100, 370 + PosY, 0x000000, "　BGM　　　 　ＸＸＸＸ");
//	DrawFormatString(100, 410 + PosY, 0x000000, "　SE　　　　　ＸＸＸＸＸＸＸＸ");
//	
//	//タイムの加算処理＆300f経過後終了(仮)
//	if (EndWaitTime >= 300)
//	{
//		GameMode = 10;				// CLOSE
//	}
//}

/****************************************
* エンド画像読込
*****************************************/
//int LoadEndImages(void)
//{
//	// エンド画像の読込
//	if ((EndImg = LoadGraph("images/end.png")) == -1) return -1;
//
//	return 0;
//}