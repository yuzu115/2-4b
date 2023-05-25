#pragma once

#ifndef END_H__
#define END_H__

class End
{
private:
	int EndImg;					// エンド画像
	int EndWaitTime;			// 待ち時間
	int PosY;					// スクロール時のＹ座標

public:
	End();								// コンストラクタ	
	~End();								// デストラクタ
	void DrawEnd(int& gameMode);		// エンド画面描画
	int LoadEndImages(void);			// エンド画像読込
};

#endif // !END_H__