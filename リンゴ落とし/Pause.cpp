#include "DxLib.h"
#include "Pause.h"

int gStartKeyFlg = FALSE;
int gFinishKeyFlg = FALSE;

/********************
*�|�[�Y��ʑJ��     *
********************/
void pause(int oldkey,int gamemode)
{
	if (oldkey & PAD_INPUT_8) 
	{
		gStartKeyFlg = TRUE;
	}
	if (gStartKeyFlg == TRUE)
	{
		SetFontSize(100);
		DrawString(300, 300, "--�|�[�Y���--", 0xffffff);
	}

}

/*********************
*�Q�[�����C����ʑJ��*
*********************/
void pausefinish(int oldkey, int gamemode)
{
	if (oldkey & PAD_INPUT_8)
	{
		gFinishKeyFlg = TRUE;
	}
	if (gFinishKeyFlg == TRUE)
	{
		SetFontSize(100);
		DrawString(300, 300, "�|�[�Y��ʏI��", 0xffffff);
	}

}