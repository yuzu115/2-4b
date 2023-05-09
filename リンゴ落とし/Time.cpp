#include "DxLib.h"
#include "Time.h"


/********************
*定数の宣言         *
********************/
const int TIMELIMIT = 3000;

/********************
*変数の宣言         *
********************/
int gStartTime;
int GameMode=0;

/********************
*タイム初期化処理   *
********************/
void GameInit(void)
{
	gStartTime = GetNowCount();
}
/********************
*タイム描画         *
********************/
void Main(int oldkey, int& gamemode)
{
	int time = TIMELIMIT *(GetNowCount() - gStartTime);
	
		if (time <= 0)
		{
			//GameMode = 7;
		}
}
