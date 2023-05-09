#include "DxLib.h"
#include "Time.h"

//定数の宣言
const int TIMELIMIT = 3000;

//変数の宣言
int gStartTime;

/********************
*タイムの初期化     *
********************/
void GameInit(void)
{
	//ゲーム開始時間の取得
	gStartTime = GetNowCount();
}

/********************
*タイムのメイン     *
********************/
void Main(int& gamemode)
{
	int time = TIMELIMIT * (GetNowCount() - gStartTime);
	if (time <= 0)
	{
		printf("テスト");
	}
}