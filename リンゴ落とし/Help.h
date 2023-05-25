#pragma once

#ifndef  HELP_H__
#define  HELP_H__

//ヘルプ画面のみで使う変数・関数の宣言をここに書きます

//画像変数もここに書いてください

/*****************************************
*　プロトタイプ宣言
******************************************/
void DrawHelp(XINPUT_STATE input, int& Button_flg, int& GameMode);		// ヘルプ画面描画
int LoadHelpImages(void);			// ヘルプ画像読込

#endif // ! HELP_H__