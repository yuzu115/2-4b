#include "DxLib.h"
#include "Ranking.h"
#include "Keyboard.h"
#include"DrawApple.h"

/****************************************
*　変数の宣言
*****************************************/
int RankingImg;			// ランキング画像

int Ranking;

//ランキングデータの変数宣言
// RankingData Ranking[RANK_MAX];

/****************************************
* ランキング画面描画
*****************************************/
void DrawRanking(XINPUT_STATE input, RankingData Ranking[], int& Button_flg, int& GameMode)
{

	if (input.Buttons[XINPUT_BUTTON_A] == 0) {
		Button_flg = FALSE;
	}

	// Aボタンでスタート画面に戻る
	if (input.Buttons[XINPUT_BUTTON_A] == 1 && Button_flg == FALSE) {
		Button_flg = TRUE;
		GameMode = 0;		// TITLE
	}

	//ランキング画像表示
	DrawGraph(0, 0, RankingImg, FALSE);

	// ランキング一覧を表示
	SetFontSize(60);
	for (int i = 0; i < RANK_MAX; i++) {
		DrawFormatString(260, 180 + i * 85, 0x000000, "%2d %-10s %10d",
			Ranking[i].no, Ranking[i].name, Ranking[i].score);
	}

}

/***********************************************
 * ランキング並べ替え
 ***********************************************/
void SortRanking(RankingData Ranking[])
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
int  SaveRanking(RankingData Ranking[])
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
int ReadRanking(RankingData Ranking[])
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

/******************************************
* ランキング入力処理
******************************************/
void InputName(RankingData Ranking[],XINPUT_STATE input,int& GameMode,int& Button_flg)
{
	Apple app;
	
	if (KeyBoard_PushB(input, Ranking[RANK_MAX - 1].name, Button_flg) == 1)
	{
		Ranking[RANK_MAX - 1].score = app.GetScore();   // ランキングデータ10番目にスコアを登録
		SortRanking(Ranking);
		SaveRanking(Ranking);
		GameMode = 3;                                // ゲームモードの変更
	}
	else //入力完了していない時
	{
		KeyBoard_Draw();                             //キーボードの描画
		KeyBoard_Update(input,Button_flg);                        //キーボードの更新・操作
	}

}


/*************************************
 * ランキング画像読込
 *************************************/
int LoadRankingImages(void)
{
	// ランキング画像の読込
	if ((RankingImg = LoadGraph("images/ranking.png")) == -1) return -1;

	return 0;
}