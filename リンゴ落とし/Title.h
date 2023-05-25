#pragma once

#ifndef TITLE_H__
#define TITLE_H__

//タイトル画面のみで使う変数・関数の宣言をここに書きます

//画像変数もここに書いてください

/*****************************************
*　プロトタイプ宣言
******************************************/
void DrawTitle(XINPUT_STATE input, int& Button_flg, int& GameMode);		// タイトル画面描画
int LoadTitleImages(void);		// タイトル画像読込

class Title
{
private:
	int TitleImg;			// タイトル画像
	int AppleCursorImg;		// カーソル（赤リンゴ）画像
	int menuNo;			// 0：START　1：RANKING　2：HELP　3：END
	int posY;				// カーソルのY座標

public:
	Title();									// コンストラクタ
	~Title();									// デストラク
	void DrawTitle(XINPUT_STATE input, int& button_flg, int& gameMode);		// タイトル画面描画
	int LoadTitleImages(void);		// タイトル画像読込
};

#endif // !TITLE_H__