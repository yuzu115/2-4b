#pragma once
#include "Ranking.h"
#include"DrawApple.h"

#ifndef RESULT_H__
#define RESULT_H__

class Result
{
private:
	int ResultBackImg;			// ”wŒi‰æ‘œ
	int ResultWaitTime;			// ‘Ò‚¿ŠÔ
	int RC;						// ÔƒŠƒ“ƒS‚ÌŠl“¾”
	int BC;						// ÂƒŠƒ“ƒS‚ÌŠl“¾”
	int GC;						// ‹àƒŠƒ“ƒS‚ÌŠl“¾”
	int PC;						// “ÅƒŠƒ“ƒS‚ÌŠl“¾”

public:
	Result();													// ƒRƒ“ƒXƒgƒ‰ƒNƒ^
	~Result();													// ƒfƒXƒgƒ‰ƒNƒ^
	void GetAppScore(Apple::AppScore* as);						// ƒŠƒ“ƒS‚ÌŠl“¾”‚ğæ“¾‚µ‚Ä‚­‚é
	void DrawResult(RankingData Ranking[], int& GameMode);		// ƒŠƒUƒ‹ƒg‰æ–Ê•`‰æ
	int LoadResultImages(void);									// ƒŠƒUƒ‹ƒg‰æ‘œ“Ç
};

#endif // !RESULT_H__