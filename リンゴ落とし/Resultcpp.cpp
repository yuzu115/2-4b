#include "DxLib.h"
#include "Result.h"
//#include "Ranking.h"

/****************************************
*　変数の宣言
*****************************************/
int ResultImg;			// リザルト画像

///****************************************
//* 画像読込
//*****************************************/
//int LoadImages(void)
//{
//	// リザルト画像の読込
//	if ((ResultImg = LoadGraph("images/Back.png")) == -1) return -1;
//
//	return 0;
//
//}

/****************************************
* リザルト画面描画処理
*****************************************/
void DrawResult(int& GameMode)
{
	// LoadImages();

	////タイムの加算処理(180f以上経過後)＆画面遷移
	//if (++g_WaitTime > 900)
		//// スコアがランキングの最下位の値以上
		//if (Ranking[RANK_MAX - 1].score >= g_Score){
		//	GameMode = 5;			// 名前入力へ
		//}
		//else {
		//	GameMode = 3;		// ランキング画面へ
		//}
	//}

	SetFontSize(30);
	DrawFormatString(300, 300, 0x000000, "赤リンゴ：%3d0\n");
	DrawFormatString(300, 340, 0x000000, "青リンゴ：%3d0\n");
	DrawFormatString(300, 380, 0x000000, "金リンゴ：%3d0\n");
	DrawFormatString(300, 420, 0x000000, "毒リンゴ：%3d0\n");
	DrawFormatString(300, 460, 0x000000, "スコア：%3d0\n");

}