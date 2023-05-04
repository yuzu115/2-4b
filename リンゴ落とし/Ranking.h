#pragma once
#include "DxLib.h"

//ランキング画面のみで使う変数・関数の宣言をここに書きます

//画像変数もここに書いてください

/*****************************************
*　構造体
******************************************/
//ランキングデータ構造体
struct RankingData {
	int no;
	char name[11];			// 10Byte
	long score;
};

int LoadImages(void);			// 画像読込
void DrawRanking(int g_KeyFlg, int& GameMode);		// ランキング画面描画処理
int ReadRanking(void);			// ランキングデータの読込

//void InputRanking(int g_KeyFlg, int& GameMode);			// ランキング入力処理

void SortRanking(void);			// ランキング並べ替え
int SaveRanking(void);			// ランキングデータの保存