#pragma once

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


class Apple
{

private:

	

public:


	////リンゴの変数
	//struct APPLE_DATE gApple[APPLE_MAX];

	////各リンゴのデータ
	//APPLE_DATE gApple_Rd = { TRUE,0,0,0,-40,45,1,100,1.1f };	//赤
	//APPLE_DATE gApple_Bl = { TRUE,1,0,0,-40,45,2,200,1.1f }; //青
	//APPLE_DATE gApple_Gl = { TRUE,2,0,0,-40,45,3.5f,500,1.1f }; //金
	//APPLE_DATE gApple_Po = { TRUE,3,0,0,-40,45,0.5f,-750,0.9f }; //毒

	////ステータス格納変数
	//APPLE_DATE gAppleState[APPLE_TYPE];

	////画像変数
	//int gAppleImg[APPLE_TYPE];
	////乱数用変数
	//int gRandApple;


	//リンゴの生成
	int CreateApple(void);
	int AppleSet(void);
	void DrawApple(void);
	int RandApple(void);

};
