#include "DxLib.h"
#include "Pause.h"

int gStartKeyFlg = FALSE;
int gFinishKeyFlg = FALSE;
int gPauseCnt;
int gPauseFlg;

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
void pausefinish(int keyflg, int gamemode)
{
	if (keyflg & PAD_INPUT_8) {
		//gGameMode = MAIN;
	}
}