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

	////リンゴの変数
	//APPLE_DATE gApple[APPLE_MAX];

	////各リンゴのデータ
	//APPLE_DATE gApple_Rd = { TRUE,0,0,0,-40,45,1,100,1.1f };	//赤
	//APPLE_DATE gApple_Bl = { TRUE,1,0,0,-40,45,2,200,1.1f }; //青
	//APPLE_DATE gApple_Gl = { TRUE,2,0,0,-40,45,3.5f,500,1.1f }; //金
	//APPLE_DATE gApple_Po = { TRUE,3,0,0,-40,45,0.5f,-750,0.9f }; //毒

private:


};

#endif