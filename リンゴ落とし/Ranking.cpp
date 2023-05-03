#include "Ranking.h"

/****************************************
*　定数の宣言
*****************************************/
const int RANK_MAX = 5;			// ランキングは5位まで

/****************************************
*　変数の宣言
*****************************************/
int RankingImg;			// ランキング画像

//ランキングデータの変数宣言
struct RankingData Ranking[RANK_MAX];

/*****************************************
*　画像読込
******************************************/
int LoadImages(void)
{
	// ランキング画像の読込
	if ((RankingImg = LoadGraph("images/Back.png")) == -1) return -1;
	
	return 0;
}

/****************************************
* ランキング画面描画処理
*****************************************/
void DrawRanking(int g_KeyFlg, int& GameMode)
{
	LoadImages();
	ReadRanking();		//ランキングデータの読込

	// スペースキーでメニューに戻る
	if (g_KeyFlg & PAD_INPUT_A) GameMode = 0;		// タイトル画面へ

	//ランキング画像表示
	DrawGraph(0, 0, RankingImg, FALSE);

	// ランキング一覧を表示
	SetFontSize(90);
	for (int i = 0; i < RANK_MAX; i++) {
		DrawFormatString(80, 170 + i * 85, 0x000000, "%2d %-10s %10d",
			Ranking[i].no, Ranking[i].name, Ranking[i].score);
	}

	SetFontSize(100);
	DrawFormatString(400, 50, 0x000000, "ランキング");

	SetFontSize(30);
	DrawFormatString(600, 650, 0x000000, "A：タイトル");

}

/*************************************
 * ランキングデータ読み込み
 *************************************/
int ReadRanking(void)
{
	FILE* fp;
#pragma warning(disable:4996)

	//ファイルオープン
	if ((fp = fopen("dat/rankingdata.txt", "r")) == NULL) {
		//エラー処理
		printf("Ranking Data Error\n");
		return -1;
	}

	//ランキングデータ配分列データを読み込む
	for (int i = 0; i < RANK_MAX; i++) {
		int dammy = fscanf(fp, "%2d %10s %10d", &Ranking[i].no, Ranking[i].name, &Ranking[i].score);
	}

	//ファイルクローズ
	fclose(fp);

	return 0;
}

/***********************************************
 * ランキング並べ替え
 ***********************************************/
void SortRanking(void)
{
	int i, j;
	RankingData work;

	// 選択法ソート
	for (i = 0; i < RANK_MAX - 1; i++) {
		for (j = i + 1; j < RANK_MAX; j++) {
			if (Ranking[i].score <= Ranking[j].score) {
				work = Ranking[i];
				Ranking[i] = Ranking[j];
				Ranking[j] = work;
			}
		}
	}

	// 順位付け
	for (i = 0; i < RANK_MAX; i++) {
		Ranking[i].no = 1;
	}
	// 得点が同じ場合は、同じ順位とする
	// 同順位があった場合の次の順位はデータ個数が加算された順位とする
	for (i = 0; i < RANK_MAX - 1; i++) {
		for (j = i + 1; j < RANK_MAX; j++) {
			if (Ranking[i].score > Ranking[j].score) {
				Ranking[j].no++;
			}
		}
	}

}
