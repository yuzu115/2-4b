#pragma once

#define APPLE_MAX  10	//リンゴの最大生成数
#define APPLE_TYPE  4		//リンゴの種類
#define APPLE_SIZE  400

///******************************************
//* 構造体の宣言
//******************************************/
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

/*
class Apple_Date
{
public:
	int flg;		//フラグ
	int type;		//種類
	int img;		//画像表示用
	float x, y, r;		//座標、半径
	float speed;		//落下速度
	int score;		//スコア加算
	float size;		//当たり判定の倍率
};
*/

class Apple
{
private:
	int gApple[APPLE_MAX];
	int gAppleImg[APPLE_TYPE];

public:

	struct APPLE_DATE {
		int flg;		//フラグ
		int type;		//種類
		int img;		//画像表示用
		float x, y, r;		//座標、半径
		float speed;		//落下速度
		int score;		//スコア加算
		float size;		//当たり判定の倍率
	};

	int gRandApple;

	//リンゴの生成
	int CreateApple(void);
	int AppleSet(void);
	void DrawApple(void);
	int RandApple(void);

};
