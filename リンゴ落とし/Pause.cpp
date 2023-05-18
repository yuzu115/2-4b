#include "DxLib.h"
#include "Pause.h"

int gStartKeyFlg = FALSE;
int gFinishKeyFlg = FALSE;

/********************
*ポーズ画面遷移     *
********************/
void pause(int oldkey,int& gamemode)
{
	int flg=0;
	//パッドキーを呼び出し
	if (oldkey & PAD_INPUT_8) 
	{
		//呼び出されたら下の処理に移動
		gStartKeyFlg = TRUE;

	}
	if (gStartKeyFlg == TRUE)
	{
		//画面への表示
		SetFontSize(100);
		DrawString(300, 300, "--ポーズ画面--", 0xffffff);
		flg = 1;
		WaitKey();
	}


	if (gStartKeyFlg == TRUE&&flg==1)
	{
		if (oldkey & PAD_INPUT_8)
		{
			gamemode = 2;
		}
	}

}

