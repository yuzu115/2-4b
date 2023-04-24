#pragma once
#include"DxLib.h"

//タイトル画面のみで使う変数・関数の宣言をここに書きます

//画像変数もここに書いてください

int TitleImg;				// タイトル画像
int TitleFontImg;			// タイトルフォント画像

static int menuNo = 0;		// START、HELP、ENDいずれかの状態
int posY;					// カーソルの座標Y

void DrawTitle(void);