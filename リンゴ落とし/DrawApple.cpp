#include"DxLib.h"
#include"DrawApple.h"

/******************************************
* 定数の宣言
******************************************/
const int APPLE_MAX = 10;	//リンゴの最大生成数
const int APPLE_TYPE=4;

/******************************************
* 構造体の宣言
******************************************/
struct AppleDate {
	int flg;		//フラグ
	int type;		//種類
	int img;		//画像表示用
	int x, y, r;	//座標、半径
	float speed;		//落下速度
	int score;		//スコア加算
	int color;		//色(仮)
};

struct AppleDate gApple[APPLE_MAX];

struct AppleDate gApple00 = { TRUE,0,0,0,-40,45,1,0 };

// これをいれたいよ
struct AppleDate gApple_Rd = {TRUE,0,0,0,-40,45,1,100,0xff0000};	//赤
struct AppleDate gApple_Br = {TRUE,1,0,0,-40,45,2,200,0x00ff00}; //青
struct AppleDate gApple_Gl = {TRUE,2,0,0,-40,45,3.5,500,0xffff00}; //金
struct AppleDate gApple_Po = {TRUE,3,0,0,-40,45,0.5,-750,0xff00ff}; //毒

struct AppleDate gAppleState[APPLE_TYPE];
int gRandApple;

int AppleSet(void)
{
	gAppleState[0] = gApple_Rd;
	gAppleState[1] = gApple_Br;
	gAppleState[2] = gApple_Gl;
	gAppleState[3] = gApple_Po;

	return 0;
}
	



void DrawApple(void){


	for (int i = 0; i < APPLE_MAX; i++){
		
		// リンゴの表示
		if (gApple[i].flg == TRUE) {
			DrawCircle(gApple[i].x, gApple[i].y, gApple[i].r, gApple[i].img, TRUE);
			gApple[i].y += gApple[i].speed;

			if (gApple[i].y > 1000) {
				gApple[i].flg = FALSE;
			}
			DrawFormatString(0, 0, 0x000000, "x:%d", gApple[i].x);
			DrawFormatString(0, 20, 0x000000, "y:%d", gApple[i].y);
			DrawFormatString(0, 40, 0x000000, "r:%d", gApple[i].r);
			DrawFormatString(0, 60, 0x000000, "flg:%d", gApple[i].flg);
			DrawFormatString(0, 80, 0x000000, "type:%d", gApple[i].type);

		}
	}

	CreateApple();

}


// リンゴの生成
int CreateApple()
{
	AppleSet();

	for (int i = 0; i < APPLE_MAX; i++) {
		if (gApple[i].flg == FALSE) {
			gApple[i] = gAppleState[gApple[i].type];
			gApple[i].type = RandApple();
			gApple[i].img = gApple[i].color;
			gApple[i].x = GetRand(7) * 125 + 50;
			gApple[i].speed = 1+1*gApple[i].speed;
			gApple[i].flg = TRUE;
			return TRUE;
		}
	}
	return FALSE;
}  


int RandApple()
{
	gRandApple = GetRand(100);

	for (int i = 0; i < APPLE_MAX;i++)
	{
		if (gRandApple <= 59)
		{
			return 0;
		}
		else if (gRandApple <=84 && gRandApple>=60)
		{
			return 1;
		}
		else if (gRandApple <= 94 && gRandApple>=84)
		{
			return 2;
		}
		else if (gRandApple <= 100 && gRandApple>=94)
		{
			return 3;
		}
	}
}