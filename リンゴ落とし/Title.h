#pragma once
#include"DxLib.h"

//タイトル画面のみで使う変数・関数の宣言をここに書きます

//画像変数もここに書いてください

/*****************************************
*　プロトタイプ宣言
******************************************/
void DrawTitle(XINPUT_STATE input, int& Button_flg, int& GameMode);		// タイトル画面描画
int LoadTitleImages(void);		// タイトル画像読込

void DrawTitle(void);