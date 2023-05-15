#include "DxLib.h"
#include "Resalt.h"

//変数の宣言
int gStartkeyflg = FALSE;

/********************
*リザルト画面表示   *
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
		DrawString(300, 300, "テスト表示　タイム", 0xffff00);
	}
}