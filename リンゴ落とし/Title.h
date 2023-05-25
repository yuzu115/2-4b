#pragma once

#ifndef TITLE_H__
#define TITLE_H__

class Title
{
private:
	int TitleImg;			// タイトル画像
	int AppleCursorImg;		// カーソル（赤リンゴ）画像
	int menuNo;				// 0：START　1：RANKING　2：HELP　3：END
	int posY;				// カーソルのY座標

public:
	Title();									// コンストラクタ
	~Title();									// デストラク
	void DrawTitle(XINPUT_STATE input, int& button_flg, int& gameMode);		// タイトル画面描画
	int LoadTitleImages(void);		// タイトル画像読込
};

#endif // !TITLE_H__