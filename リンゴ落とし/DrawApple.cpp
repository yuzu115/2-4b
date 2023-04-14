#include"DxLib.h"
#include"DrawApple.h"

/******************************************
* 定数の宣言
******************************************/
const int APPLE_MAX = 10;	//リンゴの最大生成数

/******************************************
* 構造体の宣言
******************************************/
struct APPLE {
	int flg;		//フラグ
	int type;		//種類
	int img;		//画像表示用
	int x, y, r;	//座標、半径
	int speed;		//落下速度
	int score;		//スコア加算
};

struct APPLE gApple[APPLE_MAX];
struct APPLE gApple00 = { TRUE,0,0,0,-40,45,3,0 };

int gAppleImg[4];

int AppleInit(void)
{
	if((gAppleImg[0] = 0xff0000) == -1)return -1;	//赤リンゴ
	if((gAppleImg[1] = 0x00ff00) == -1)return -1;	//青リンゴ
	if((gAppleImg[2] = 0xffff00) == -1)return -1;	//金リンゴ
	if((gAppleImg[3] = 0xff00ff) == -1)return -1;	//毒リンゴ
	for (int i = 0; i < APPLE_MAX; i++)
	{
		gApple[i].flg = FALSE;
	}
}

void DrawApple(void){

	AppleInit();

	for (int i = 0; i < APPLE_MAX; i++){
		if (gApple[i].flg == TRUE) {
			DrawCircle(gApple[i].x, gApple[i].y, gApple[i].r, gApple[i].img, TRUE);
			gApple[i].y += gApple[i].speed;

			if (gApple[i].y > 500) {
				gApple[i].flg = FALSE;
			}
			DrawFormatString(0, 0, 0x000000, "x:%d", gApple[i].x);
			DrawFormatString(0, 20, 0x000000, "y:%d", gApple[i].y);
			DrawFormatString(0, 40, 0x000000, "r:%d", gApple[i].r);
			DrawFormatString(0, 60, 0x000000, "speed:%d", gApple[i].speed);
			DrawFormatString(0, 80, 0x000000, "flg:%d", gApple[i].flg);

		}
	}

	CreateApple();

}

int CreateApple()
{
	for (int i = 0; i < APPLE_MAX; i++) {
		if (gApple[i].flg == FALSE) {
			gApple[i] = gApple00;
			gApple[i].type = GetRand(3);
			gApple[i].img = gAppleImg[gApple[i].type];
			gApple[i].x = GetRand(7) * 100 + 50;
			gApple[i].speed = gApple[i].type + gApple[i].speed * 3;

			return TRUE;
		}

		return FALSE;
	}
}