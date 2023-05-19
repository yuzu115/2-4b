#include "DxLib.h"
#include "Title.h"
#include "InputControl.h"

/****************************************
*　変数の宣言
*****************************************/
int TitleImg;			// タイトル画像
int AppleCursorImg;		// カーソル（赤リンゴ）画像

int menuNo = 0;			// 0：START　1：RANKING　2：HELP　3：END
int posY;				// カーソルのY座標

TITLE::TITLE()
{
	TitleImg = 0;			// タイトル画像
	AppleCursorImg = 0;		// カーソル（赤リンゴ）画像
	menuNo = 0;			// 0：START　1：RANKING　2：HELP　3：END
	posY = 0;				// カーソルのY座標
}

TITLE::~TITLE()
{

}

void TITLE::DrawTitle(XINPUT_STATE input, int& Button_flg, int& GameMode)
{
	LoadTitleImages();		// タイトル画像読込

	// メニューカーソル移動処理
	if (input.ThumbLY < 128 && Button_flg == FALSE) {
		Button_flg = TRUE;
		if (++menuNo > 3) menuNo = 0;
	}
	if (input.ThumbLY > 128 && Button_flg == FALSE) {
		Button_flg = TRUE;
		if (--menuNo < 0) menuNo = 3;
	}
	if (input.ThumbLY == 128 && input.Buttons[XINPUT_BUTTON_A] == 0) {
		Button_flg = FALSE;
	}

	// Aボタンでメニュー選択
	if (input.Buttons[XINPUT_BUTTON_A] == 1 && Button_flg == FALSE) {
		Button_flg = TRUE;

		switch (menuNo) {
		case 0:
			GameMode = 1;			// INIT
			//GameMode = 6;			// RESULT
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

}


/****************************************
* タイトル画面描画
*****************************************/
void DrawTitle(int& GameMode)
{
	LoadTitleImages();		// タイトル画像読込

		// タイトル画像の表示
	DrawGraph(0, 0, TitleImg, FALSE);

	// カーソルを上に移動
	if (InputControl::GetStick())
	{
		if (--menuNo < 0) menuNo = 3;
	}
	InputControl::ChangeFlg();

	InputControl::DrawFlg();

	//// カーソルを下に移動
	//if (InputControl::GetStick())
	//{
	//	if (--menuNo < 0) menuNo = 3;
	//}

	//// メニューカーソル移動処理
	//if (input.ThumbLY < 128 && Button_flg == FALSE) {
	//	Button_flg = TRUE;
	//	if (++menuNo > 3) menuNo = 0;
	//}
	//if (input.ThumbLY > 128 && Button_flg == FALSE) {
	//	Button_flg = TRUE;
	//	if (--menuNo < 0) menuNo = 3;
	//}
	//if (input.ThumbLY == 128 && input.Buttons[XINPUT_BUTTON_A] == 0) {
	//	Button_flg = FALSE;
	//}

	//// Aボタンでメニュー選択
	//if (input.Buttons[XINPUT_BUTTON_A] == 1 && Button_flg == FALSE) {
	//	Button_flg = TRUE;

	//	switch (menuNo) {
	//	case 0:
	//		GameMode = 1;			// INIT
	//		//GameMode = 6;			// RESULT
	//		break;
	//	case 1:
	//		GameMode = 3;			// RANKING
	//		break;
	//	case 2:
	//		GameMode = 4;			// HELP
	//		break;
	// 	case 3:
	//		GameMode = 7;			// END
	//		break;
	//	}
	//}
	
	// タイトル画像の表示
	//DrawGraph(0, 0, TitleImg, FALSE);

	// メニューカーソルの表示
	posY = menuNo * 100;

	// カーソル（赤リンゴ）を縮小描画
	DrawExtendGraph(790, 305 + posY, 880, 395 + posY, AppleCursorImg, TRUE);
	
	//// メニューカーソル（三角形）の表示
	//posY = menuNo * 100;
	//DrawTriangle(810, 325 + posY, 840, 345 + posY, 810, 365 + posY, 0xff0000, TRUE);

	//DrawFormatString(0, 0, 0xffffff, "menuNo %d", menuNo);

}

/****************************************
* タイトル画面描画
*****************************************/
//void DrawTitle(XINPUT_STATE input, int& Button_flg, int& GameMode)
//{
//	LoadTitleImages();		// タイトル画像読込
//
//	// メニューカーソル移動処理
//	if (input.ThumbLY < 128 && Button_flg == FALSE) {
//		Button_flg = TRUE;
//		if (++menuNo > 3) menuNo = 0;
//	}
//	if (input.ThumbLY > 128 && Button_flg == FALSE) {
//		Button_flg = TRUE;
//		if (--menuNo < 0) menuNo = 3;
//	}
//	if (input.ThumbLY == 128 && input.Buttons[XINPUT_BUTTON_A] == 0) {
//		Button_flg = FALSE;
//	}
//
//	// Aボタンでメニュー選択
//	if (input.Buttons[XINPUT_BUTTON_A] == 1 && Button_flg == FALSE) {
//		Button_flg = TRUE;
//
//		switch (menuNo) {
//		case 0:
//			GameMode = 1;			// INIT
//			//GameMode = 6;			// RESULT
//			break;
//		case 1:
//			GameMode = 3;			// RANKING
//			break;
//		case 2:
//			GameMode = 4;			// HELP
//			break;
//		case 3:
//			GameMode = 7;			// END
//			break;
//		}
//	}
//
//	// タイトル画像の表示
//	DrawGraph(0, 0, TitleImg, FALSE);
//
//	// メニューカーソルの表示
//	posY = menuNo * 100;
//
//	// カーソル（赤リンゴ）を縮小描画
//	DrawExtendGraph(790, 305 + posY, 880, 395 + posY, AppleCursorImg, TRUE);
//
//	//// メニューカーソル（三角形）の表示
//	//posY = menuNo * 100;
//	//DrawTriangle(810, 325 + posY, 840, 345 + posY, 810, 365 + posY, 0xff0000, TRUE);
//
//	//DrawFormatString(0, 0, 0xffffff, "menuNo %d", menuNo);
//
//}

/****************************************
* タイトル画像読込
*****************************************/
int LoadTitleImages(void)
{
	// タイトル画像の読込
	if ((TitleImg = LoadGraph("images/title.png")) == -1) return -1;
	// カーソル（赤リンゴ）画像
	if ((AppleCursorImg = LoadGraph("images/redapple.png")) == -1) return -1;

	return 0;
}