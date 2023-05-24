#include "DxLib.h"
#include "Result.h"
#include "DrawApple.h"

/****************************************
*　変数の宣言
*****************************************/
int ResultBackImg;					// 背景画像

int ResultWaitTime = 0;					// 待ち時間

int RS;
int BS;
int GS;
int PS;

void GetAppScore(Apple::AppScore* as)
{
	RS = as->r;
	BS = as->b;
	GS = as->g;
	PS = as->p;
}

/****************************************
* リザルト画面描画
*****************************************/
void DrawResult(RankingData Ranking[], int& GameMode)
{
	Apple app;

	LoadResultImages();					// リザルト画像読込

	// ReadRanking(Ranking);			//ランキングデータの読込

	//タイムの加算処理(180f以上経過後)＆画面遷移
	if (++ResultWaitTime > 180) {
		// スコアがランキングの最下位の値以上
		if (Ranking[RANK_MAX - 1].score <= app.GetScore()) {
			GameMode = 5;				// INPUTNAME
		}
		else {
			GameMode = 3;				// RANKING
		}

	}

		
	// リザルト画像の表示
	DrawGraph(0, 0, ResultBackImg, FALSE);

	SetFontSize(50);
	DrawFormatString(410, 180, 0x000000, "赤リンゴ : %3d コ\n",RS);
	DrawFormatString(410, 240, 0x000000, "青リンゴ : %3d コ\n",BS);
	DrawFormatString(410, 300, 0x000000, "金リンゴ : %3d コ\n",GS);
	DrawFormatString(410, 360, 0x000000, "毒リンゴ : %3d コ\n",PS);
	DrawFormatString(410, 500, 0x000000, "スコア   : %5d\n",app.GetScore());

}

/****************************************
* リザルト画像読込
*****************************************/
int LoadResultImages(void)
{
	// 背景画面の読込
	if ((ResultBackImg = LoadGraph("images/result.png")) == -1) return -1;

	return 0;
}