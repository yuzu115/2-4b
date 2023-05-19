#pragma once

#ifndef END_H__
#define END_H__

//エンド画面のみで使う変数・関数の宣言をここに書きます

//画像変数もここに書いてください

/*****************************************
*　プロトタイプ宣言
******************************************/
void DrawEnd(int& GameMode, int& Count);		// エンド画面描画
int LoadEndImages(void);			// エンド画像読込

class End
{
private:
	int EndImg;					// エンド画像
	int EndWaitTime;			// 待ち時間
	int PosY;					// スクロール時のＹ座標

public:
	END();
	void DrawEnd(int& GameMode, int& Count);		// エンド画面描画
	int LoadEndImages(void);			// エンド画像読込

};

#endif // !END_H__