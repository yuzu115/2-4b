#include "DxLib.h"
#include "Pause.h"

int gStartKeyFlg = FALSE;
int gFinishKeyFlg = FALSE;

/********************
*ポーズ画面遷移     *
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
		DrawString(350, 300, "--ポーズ画面--", 0xffffff);
	}

}

/*********************
*ゲームメイン画面遷移*
*********************/
void pausefinish(int oldkey, int gamemode)
{
	if (oldkey & PAD_INPUT_8)
	{
		
	}
}