#pragma once
#include "Ranking.h"
#include"DrawApple.h"

#ifndef RESULT_H__
#define RESULT_H__

/*****************************************
*　プロトタイプ宣言
******************************************/
void GetAppScore(Apple::AppScore* as);						// リンゴの獲得数を取得してくる
void DrawResult(RankingData Ranking[], int& GameMode);		// リザルト画面描画
int LoadResultImages(void);									// リザルト画像読込

#endif // !RESULT_H__