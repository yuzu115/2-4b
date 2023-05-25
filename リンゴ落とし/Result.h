#pragma once
#include "Ranking.h"
#include"DrawApple.h"

#ifndef RESULT_H__
#define RESULT_H__

//リザルト画面のみで使う変数・関数の宣言をここに書きます

//画像変数もここに書いてください

/*****************************************
*　プロトタイプ宣言
******************************************/
void DrawResult(RankingData Ranking[],int& GameMode);		// リザルト画面描画
void GetAppScore(Apple::AppScore* as);
int LoadResultImages(void);			// リザルト画像読込

#endif // !RESULT_H__