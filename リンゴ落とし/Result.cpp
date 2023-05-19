#include "DxLib.h"
#include "Result.h"

/****************************************
*　変数の宣言
*****************************************/
int ResultBackImg;					// 背景画像
int g_Score = 0;						// 現在のスコア

int ResultWaitTime = 0;					// 待ち時間

RESULT::RESULT()
{
	ResultBackImg = 0;					// 背景画像
	g_Score = 0;						// 現在のスコア
	ResultWaitTime = 0;					// 待ち時間
}

RESULT::~RESULT()
{

}

void RESULT::DrawResult(RankingData Ranking[], int& GameMode)
{
	LoadResultImages();					// リザルト画像読込

	// ReadRanking(Ranking);			//ランキングデータの読込

	//タイムの加算処理(180f以上経過後)＆画面遷移
	if (++ResultWaitTime > 180) {
		// スコアがランキングの最下位の値以上
		if (Ranking[RANK_MAX - 1].score >= g_Score) {
			GameMode = 5;				// INPUTNAME
		}
		else {
			GameMode = 3;				// RANKING
		}

	}


	// リザルト画像の表示
	DrawGraph(0, 0, ResultBackImg, FALSE);

	SetFontSize(30);
	DrawFormatString(400, 300, 0x000000, "赤リンゴ：%3d\n");
	DrawFormatString(400, 340, 0x000000, "青リンゴ：%3d\n");
	DrawFormatString(400, 380, 0x000000, "金リンゴ：%3d\n");
	DrawFormatString(400, 420, 0x000000, "毒リンゴ：%3d\n");
	DrawFormatString(400, 460, 0x000000, "スコア　：%3d\n");

}



/****************************************
* リザルト画面描画
*****************************************/
void DrawResult(RankingData Ranking[], int& GameMode)
{
	LoadResultImages();					// リザルト画像読込

	// ReadRanking(Ranking);			//ランキングデータの読込

	//タイムの加算処理(180f以上経過後)＆画面遷移
	if (++ResultWaitTime > 180) {
		// スコアがランキングの最下位の値以上
		if (Ranking[RANK_MAX - 1].score >= g_Score) {
			GameMode = 5;				// INPUTNAME
		}
		else {
			GameMode = 3;				// RANKING
		}

	}

		
	// リザルト画像の表示
	DrawGraph(0, 0, ResultBackImg, FALSE);

	SetFontSize(30);
	DrawFormatString(400, 300, 0x000000, "赤リンゴ：%3d\n");
	DrawFormatString(400, 340, 0x000000, "青リンゴ：%3d\n");
	DrawFormatString(400, 380, 0x000000, "金リンゴ：%3d\n");
	DrawFormatString(400, 420, 0x000000, "毒リンゴ：%3d\n");
	DrawFormatString(400, 460, 0x000000, "スコア　：%3d\n");

}

/****************************************
* フレームの経過
*****************************************/
//int Progress(int& Count,int& on,int& off) {
//
//	if (Count <= 120) {
//
//		//120秒たつまで、20f感覚で点滅
//		if (on == 20) {
//			off = 0;
//
//			DrawBox(0, 0, 40, 40, 0x000000, TRUE);
//			// プレイヤー仮表示(赤)
//			//DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0xff0000, TRUE);
//
//			return off;
//
//		}
//
//		if (off == 20) {
//			on = 0;
//			DrawBox(0, 0, 40, 40, 0xff0000, FALSE);
//
//			//DrawBox(gPlayer.x, gPlayer.y, gPlayer.x + gPlayer.w, SCREEN_HEIGHT, 0x000000, TRUE);
//
//			return on;
//		}
//
//	}
//	
//}


/****************************************
* リザルト画像読込
*****************************************/
int LoadResultImages(void)
{
	// 背景画面の読込
	if ((ResultBackImg = LoadGraph("images/Back.png")) == -1) return -1;

	return 0;
}