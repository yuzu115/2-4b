#include "DxLib.h"
#include "Result.h"

Result::Result()
{
	ResultBackImg = 0;					// 背景画像
	ResultWaitTime = 0;					// 待ち時間
	RC = 0;			// 赤リンゴの獲得数
	BC = 0;			// 青リンゴの獲得数
	GC = 0;			// 金リンゴの獲得数
	PC = 0;			// 毒リンゴの獲得数
}

Result::~Result()
{

}

/****************************************
* リンゴの獲得数を取得
*****************************************/
void Result::GetAppScore(Apple::AppScore* as)
{
	RC = as->r;
	BC = as->b;
	GC = as->g;
	PC = as->p;
}

/****************************************
* リザルト画面描画
*****************************************/
void Result::DrawResult(RankingData Ranking[], int& GameMode)
{
	Apple app;

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
	DrawFormatString(410, 180, 0x000000, "赤リンゴ : %3d コ\n",RC);
	DrawFormatString(410, 240, 0x000000, "青リンゴ : %3d コ\n",BC);
	DrawFormatString(410, 300, 0x000000, "金リンゴ : %3d コ\n",GC);
	DrawFormatString(410, 360, 0x000000, "毒リンゴ : %3d コ\n",PC);
	DrawFormatString(410, 500, 0x000000, "スコア   : %5d\n",app.GetScore());
}

/****************************************
* リザルト画像読込
*****************************************/
int Result::LoadResultImages(void)
{
	// 背景画面の読込
	if ((ResultBackImg = LoadGraph("images/result.png")) == -1) return -1;

	return 0;
}