#pragma once
#ifndef APPLE_H__
#define APPLE_H__

/******************************************
* 定数の宣言
******************************************/
const int APPLE_MAX = 10;	//リンゴの最大生成数
const int APPLE_TYPE = 4;		//リンゴの種類
const int APPLE_SIZE = 400;

/******************************************
* 構造体の宣言
******************************************/
//struct APPLE_DATE {
//	int flg;		//フラグ
//	int type;		//種類
//	int img;		//画像表示用
//	float x, y, r;		//座標、半径
//	float speed;		//落下速度
//	int score;		//スコア加算
//	float size;		//当たり判定の倍率
//};

/******************************************
 * 関数のプロトタイプ宣言
 ******************************************/
int AppleSet(void);
void DrawApple(void);
int RandApple(void);

class Apple
{
public:
	//リンゴの生成
	static int CreateApple(void);

	struct APPLE_DATE {
		int flg;		//フラグ
		int type;		//種類
		int img;		//画像表示用
		float x, y, r;		//座標、半径
		float speed;		//落下速度
		int score;		//スコア加算
		float size;		//当たり判定の倍率
	};

private:

};

#endif