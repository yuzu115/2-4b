#include "DxLib.h"
#include "Time.h"


/********************
*�萔�̐錾         *
********************/
const int TIMELIMIT = 3000;

/********************
*�ϐ��̐錾         *
********************/
int gStartTime;
int GameMode=0;

/********************
*�^�C������������   *
********************/
void GameInit(void)
{
	gStartTime = GetNowCount();
}
/********************
*�^�C���`��         *
********************/
void Main(int oldkey, int& gamemode)
{
	int time = TIMELIMIT *(GetNowCount() - gStartTime);
	
		if (time <= 0)
		{
			//GameMode = 7;
		}
}
