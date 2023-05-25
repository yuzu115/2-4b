#pragma once
#include "Ranking.h"
#include"DrawApple.h"

#ifndef RESULT_H__
#define RESULT_H__

class Result
{
private:
	int ResultBackImg;			// 背景画像
	int ResultWaitTime;			// 待ち時間
	int RC;						// 赤リンゴの獲得数
	int BC;						// 青リンゴの獲得数
	int GC;						// 金リンゴの獲得数
	int PC;						// 毒リンゴの獲得数

public:
	Result();													// コンストラクタ
	~Result();													// デストラクタ
	void GetAppScore(Apple::AppScore* as);						// リンゴの獲得数を取得してくる
	void DrawResult(RankingData Ranking[], int& GameMode);		// リザルト画面描画
	int LoadResultImages(void);									// リザルト画像読込
};

#endif // !RESULT_H__