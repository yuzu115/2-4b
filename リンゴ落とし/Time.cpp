#include "DxLib.h"
#include "Time.h"

//�萔�̐錾
const int TIMELIMIT = 3000;

//�ϐ��̐錾
int gStartTime;

/********************
*�^�C���̏�����     *
********************/
void GameInit(void)
{
	//�Q�[���J�n���Ԃ̎擾
	gStartTime = GetNowCount();
}

/********************
*�^�C���̃��C��     *
********************/
void Main(int& gamemode)
{
	int time = TIMELIMIT * (GetNowCount() - gStartTime);
	if (time <= 0)
	{
		printf("�e�X�g");
	}
}