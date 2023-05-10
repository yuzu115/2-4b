#include "DxLib.h"
#include "infomation.h"
#include "Title.h"

/****************************************
*　変数の宣言
*****************************************/
int TitleImg;			// タイトル画像
int AppleCursorImg;		// カーソル（赤リンゴ）画像

int menuNo = 0;			// 0：START　1：RANKING　2：HELP　3：END
int posY;				// カーソルのY座標

int CursorSound;	//カーソルサウンド
int MoveSound;		//画面遷移時になるサウンド

/****************************************
* タイトル画面描画
*****************************************/
int DrawTitle(void)
{
//nt DrawTitle(int g_KeyFlg,int& GameMode) {

	LoadTitleSounds();

	// タイトル画像の読込
	if ((TitleImg = LoadGraph("images/Title.png")) == -1) return -1;
	// カーソル（赤リンゴ）画像
	if ((AppleCursorImg = LoadGraph("images/RedApple.png")) == -1) return -1;

	// メニューカーソル移動処理
	if (input.Buttons[1] == 1 && Button_flg == FALSE) {
		Button_flg = TRUE;
		PlaySoundMem(CursorSound, DX_PLAYTYPE_BACK);
		if (++menuNo > 3) menuNo = 0;
	}
	if (input.Buttons[0] == 1 && Button_flg == FALSE) {
		Button_flg = TRUE;
		PlaySoundMem(CursorSound, DX_PLAYTYPE_BACK);
		if (--menuNo < 0) menuNo = 3;
	}
	if (input.Buttons[1] == 0 && input.Buttons[0] == 0 && input.Buttons[12] == 0) {
		Button_flg = FALSE;
	}

	// Aボタンでメニュー選択
	if (input.Buttons[12] == 1 && Button_flg == FALSE) {
		Button_flg = TRUE;
		PlaySoundMem(MoveSound, DX_PLAYTYPE_BACK);
		switch (menuNo) {
		case 0:
		//	GameMode = 1;			// INIT
			GameMode = 6;			// RESULT
			break;
		case 1:
			GameMode = 3;			// RANKING
			break;
		case 2:
			GameMode = 4;			// HELP
			break;
	 	case 3:
			GameMode = 7;			// END
			break;
		}
	}
	
	// タイトル画像の表示
	DrawGraph(0, 0, TitleImg, FALSE);

	// メニューカーソルの表示
	posY = menuNo * 100;

	// カーソル（赤リンゴ）を縮小描画
	DrawExtendGraph(790, 305 + posY, 880, 395 + posY, AppleCursorImg, TRUE);
	
	//// メニューカーソル（三角形）の表示
	//posY = menuNo * 100;
	//DrawTriangle(810, 325 + posY, 840, 345 + posY, 810, 365 + posY, 0xff0000, TRUE);

	//DrawFormatString(0, 0, 0xffffff, "menuNo %d", menuNo);

	return 0;

}


int LoadTitleSounds() {
	
	if ((CursorSound = LoadSoundMem("AppleSound/AppleSE/CursorMove.wav")) == -1)return -1;
	if ((MoveSound = LoadSoundMem("AppleSound/AppleSE/カーソル移動12.wav")) == -1)return -1;

}