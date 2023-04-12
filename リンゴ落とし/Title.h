#pragma once

//タイトル画面のみで使う変数・関数の宣言をここに書きます

//画像変数もここに書いてください

int gTitleImg;				// タイトル画像
int gTitleFontImg;			// タイトルフォント画像

static int menuNo = 0;		// START、HELP、ENDいずれかの状態
int posY;					// カーソル移動

void DrawTitle(void);