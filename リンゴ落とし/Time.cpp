#include "DxLib.h"
#include "Time.h"

//�萔�̐錾
const int TIMELIMIT = 3000;

//�ϐ��̐錾
int gStartTime;

/********************
*�^�C���̏�����     *
********************/
void TimeInit(void)
{
	//�Q�[���J�n���Ԃ̎擾
	gStartTime = GetNowCount();
}

/********************
*�^�C���̃��C��     *
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

