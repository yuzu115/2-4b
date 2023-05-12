#include"DxLib.h"
#include"Score.h"
#include"Player.h"

int gScore = 0;	//スコア用変数
int gCount = 0;	//カウント変数

int a, b, c, d;
int score;
int flg;

void PlayerScore()
{
	if (flg == TRUE)
	{
		gScore += score;
		gCount++;
	}
	DrawFormatString(250, 0, 0xff0000, "score:%d", gScore);
	DrawFormatString(250, 20, 0xff0000, "count:%d", gCount);
}
