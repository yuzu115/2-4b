#include "DxLib.h"
#include "Pause.h"
#include "InputControl.h"

//int gStartKeyFlg = FALSE;
//int gFinishKeyFlg = FALSE;

/********************
*�|�[�Y��ʑJ��     *
********************/
void pause(int oldkey, int& gamemode)
{
	int flg = 0;
	//�p�b�h�L�[���Ăяo��
	if (InputControl::GetKeyDown(PAD_INPUT_8))
	{
		WaitKey();
		//��ʂւ̕\��
		SetFontSize(100);
		DrawString(300, 300, "--�|�[�Y���--", 0xffffff);
		flg = 1;

	}
}
