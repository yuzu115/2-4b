#include "DxLib.h"
#include "Pause.h"
#include "InputControl.h"

//int gStartKeyFlg = FALSE;
//int gFinishKeyFlg = FALSE;

/********************
*ポーズ画面遷移     *
********************/
void pause(int oldkey, int& gamemode)
{
	int flg = 0;
	//パッドキーを呼び出し
	if (InputControl::GetKeyDown(PAD_INPUT_8))
	{
		WaitKey();
		//画面への表示
		SetFontSize(100);
		DrawString(300, 300, "--ポーズ画面--", 0xffffff);
		flg = 1;

	}
}
