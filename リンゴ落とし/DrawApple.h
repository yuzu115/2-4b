#pragma once

#define APPLE_MAX  10	//リンゴの最大生成数
#define APPLE_TYPE  4		//リンゴの種類
#define APPLE_SIZE  400

class Apple
{
public:
	struct APPLE_DATA {
		int flg;		//フラグ
		int type;		//種類
		int img;		//画像表示用
		float x, y, r;		//座標、半径
		float speed;		//落下速度
		int score;		//スコア加算
		float size;		//当たり判定の倍率
	};

	/******************************************
	* 関数のプロトタイプ宣言
	 ******************************************/
	Apple();
	~Apple();
	//リンゴの生成
	int CreateApple(void);
	int AppleSet(void);
	void DrawApple(void);
	int RandApple(void);
	void AppleHit(APPLE_DATA* a);

private:
	//各リンゴのデータ
	APPLE_DATA gApple_Rd = { FALSE,0,0,0,-40,45,1,100,1.1f };	//赤
	APPLE_DATA gApple_Bl = { FALSE,1,0,0,-40,45,2,200,1.1f }; //青
	APPLE_DATA gApple_Gl = { FALSE,2,0,0,-40,45,3.5f,500,1.1f }; //金
	APPLE_DATA gApple_Po = { FALSE,3,0,0,-40,45,0.5f,-750,0.9f }; //毒
};
