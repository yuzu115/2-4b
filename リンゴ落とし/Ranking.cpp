#include "DxLib.h"
#include "infomation.h"
#include "Ranking.h"

/****************************************
*　定数の宣言
*****************************************/
//const int RANK_MAX = 5;			// ランキングは上位5位まで

/****************************************
*　変数の宣言
*****************************************/
int RankingImg;			// ランキング画像

//ランキングデータの変数宣言
 RankingData Ranking[RANK_MAX];

/****************************************
* ランキング画面描画処理
*****************************************/
int DrawRanking(void)
{
	// ランキング画像の読込
	if ((RankingImg = LoadGraph("images/Back.png")) == -1) return -1;

	ReadRanking();		//ランキングデータの読込

	//// スペースキーでメニューに戻る
	//if (g_KeyFlg & PAD_INPUT_A) GameMode = 0;		// タイトル画面へ

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

	return 0;
}

///*****************************************
//*　ランキング入力(名前入力)処理
//******************************************/
//void InputName(int g_KeyFlg, int& GameMode)
//{
//	// ランキング画像表示
//	DrawGraph(0, 0, RankingImg, FALSE);
//
//	// フォントサイズ
//	SetFontSize(16);
//
//	// 名前の入力指示文字列の描画
//	DrawString(80, 150, "ランキングに登録します", 0xFFFFFF);
//	DrawString(80, 170, "名前を英字で入力してください", 0xFFFFFF);
//
//	// 名前の入力
//	DrawString(80, 200, ">", 0xFFFFFF);
//	DrawBox(90, 195, 200, 220, 0x000055, TRUE);
//	if (KeyInputSingleCharString(90, 200, 10, Ranking[RANK_MAX - 1].name, FALSE) == 1) {
//		Ranking[RANK_MAX - 1].score = g_Score;			// ランキングデータの10番目にスコアを登録
//		SortRanking();									// ランキング並べ替え
//		SaveRanking();									// ランキングデータの保存
//		GameMode = 3;							// ゲームモードの変更
//	}
//
//}

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

/***********************************************
 * ランキングデータの保存
 ***********************************************/
int  SaveRanking(void)
{
	FILE* fp;
#pragma warning(disable:4996)

	// ファイルオープン
	if ((fp = fopen("dat/rankingdata.txt", "w")) == NULL) {
		/* エラー処理 */
		printf("Ranking Data Error\n");
		return -1;
	}

	// ランキングデータ分配列データを書き込む
	for (int i = 0; i < RANK_MAX; i++) {
		fprintf(fp, "%2d %10s %10d\n", Ranking[i].no, Ranking[i].name, Ranking[i].score);
	}

	//ファイルクローズ
	fclose(fp);

	return 0;
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
