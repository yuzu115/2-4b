#include "DxLib.h"
#include "Title.h"

Title::Title()
{
	TitleImg = 0;			// タイトル画像
	AppleCursorImg = 0;		// カーソル（赤リンゴ）画像
	menuNo = 0;			// 0：START　1：RANKING　2：HELP　3：END
	posY = 0;				// カーソルのY座標
}

Title::~Title()
{

}

/****************************************
* タイトル画面描画
*****************************************/
void Title::DrawTitle(XINPUT_STATE input, int& button_flg, int& gameMode)
{
	LoadTitleImages();		// タイトル画像読込

	// メニューカーソル移動処理
	if (input.ThumbLY < 128 && button_flg == FALSE) {
		button_flg = TRUE;
		if (++menuNo > 3) menuNo = 0;
	}
	if (input.ThumbLY > 128 && button_flg == FALSE) {
		button_flg = TRUE;
		if (--menuNo < 0) menuNo = 3;
	}
	if (input.ThumbLY == 128 && input.Buttons[XINPUT_BUTTON_A] == 0) {
		button_flg = FALSE;
	}

	// Aボタンでメニュー選択
	if (input.Buttons[XINPUT_BUTTON_A] == 1 && button_flg == FALSE) {
		button_flg = TRUE;

		switch (menuNo) {
		case 0:
			gameMode = 1;			// INIT
			//GameMode = 6;			// RESULT
			break;
		case 1:
			gameMode = 3;			// RANKING
			break;
		case 2:
			gameMode = 4;			// HELP
			break;
		case 3:
			gameMode = 7;			// END
			break;
		}
	}

	// タイトル画像の表示
	DrawGraph(0, 0, TitleImg, FALSE);

	// メニューカーソルの表示
	posY = menuNo * 100;

	// カーソル（赤リンゴ）を縮小描画
	DrawExtendGraph(790, 305 + posY, 880, 395 + posY, AppleCursorImg, TRUE);
}

/****************************************
* タイトル画像読込
*****************************************/
int Title::LoadTitleImages(void)
{
	// タイトル画像の読込
	if ((TitleImg = LoadGraph("images/title.png")) == -1) return -1;
	// カーソル（赤リンゴ）画像
	if ((AppleCursorImg = LoadGraph("images/redapple.png")) == -1) return -1;

	return 0;
}