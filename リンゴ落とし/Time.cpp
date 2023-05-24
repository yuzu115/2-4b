#include "DxLib.h"
#include "Time.h"

//定数の宣言
const int TIMELIMIT = 3000;

//変数の宣言
int gStartTime;

/********************
*タイムの初期化     *
********************/
void TimeInit(void)
{
	//ゲーム開始時間の取得
	gStartTime = GetNowCount();
}

/********************
*タイムのメイン     *
********************/
void Time(int gamemode)
{
	TimeInit();
	DrawBox(0, 0, 1280, 720, 0xd3d3d3, TRUE);
	int time = TIMELIMIT * (GetNowCount() - gStartTime);
	if (time <= 0)
	{
		DrawBox(0, 0, 1280, 720, 0xd3d3d3, TRUE);
	}
}

