#include "DxLib.h"
#include "Pause.h"

int gStartKeyFlg = FALSE;

/********************
*�|�[�Y��ʑJ��     *
********************/
void pause(void)
{
	if (keyflg & PAD_INPUT_8) 
	{
		gStartKeyFlg = TRUE;
	}
	if (gStartKeyFlg = TRUE) 
	{
		SetFontSize(100);
		DrawString(350, 300, "--�|�[�Y���--", 0xffffff);
	}
}