#include "DxLib.h"
#include "Pause.h"

int gStartKeyFlg = FALSE;
int gFinishKeyFlg = FALSE;


/********************
*�|�[�Y��ʑJ��     *
********************/
void pause(int oldkey,int& gamemode)
{
	//�p�b�h�L�[���Ăяo��
	if (oldkey & PAD_INPUT_8) 
	{
		//�Ăяo���ꂽ�牺�̏����Ɉړ�
		gStartKeyFlg = TRUE;

	}
	if (gStartKeyFlg == TRUE)
	{
		//��ʂւ̕\��
		SetFontSize(100);
		DrawString(300, 300, "--�|�[�Y���--", 0xffffff);
	}

}

