#pragma once

#ifndef RANKING_H__
#define RANKING_H__

//ランキング画面のみで使う変数・関数の宣言をここに書きます

//画像変数もここに書いてください

/*****************************************
*　マクロ定義
******************************************/
#define RANK_MAX (5)			// ランキングは上位5位まで
#define NAME_MAX (11)			// 名前のサイズ

/*****************************************
*　型定義
******************************************/
//ランキングデータ
typedef struct
{
	int no;						// 順位
	char name[NAME_MAX];		// 名前　10Byte
	long score;					// スコア
} RankingData;

/*****************************************
*　プロトタイプ宣言
******************************************/
//int DrawRanking(int g_KeyFlg, int& GameMode);		// ランキング画面描画処理
//int ReadRanking(void);								// ランキングデータの読込
//
////void InputRanking(int g_KeyFlg, int& GameMode);		// ランキング入力処理
//
//void SortRanking(void);			// ランキング並べ替え
//int SaveRanking(void);			// ランキングデータの保存
//
///*****************************************
//*　extern宣言
//******************************************/
////ランキングデータの変数宣言
//extern RankingData Ranking[RANK_MAX];			// RankingとResultで使用
//
#endif // !RANKING_H__