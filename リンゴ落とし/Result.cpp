#include "DxLib.h"
#include "Resalt.h"

//�ϐ��̐錾
int gStartkeyflg = FALSE;

/********************
*���U���g��ʕ\��   *
********************/
void Resalt(int oldkey,int&gamemode)
{
	if (oldkey & KEY_INPUT_Z)
	{
		gStartkeyflg = TRUE;
	}
	if (gStartkeyflg == TRUE)
	{
		SetFontSize(90);
		DrawString(300, 300, "�e�X�g�\���@�^�C��", 0xffff00);
	}
}