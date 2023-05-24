#include"DxLib.h"
#include"DrawApple.h"
#include"Player.h"
#include"Pause.h"
#include"math.h"

/******************************************
* 定数の宣言
******************************************/
const int APPLE_MAX = 10;	//リンゴの最大生成数
const int APPLE_TYPE=4;		//リンゴの種類

/******************************************
* 構造体の宣言
******************************************/
struct AppleDate {
	int flg;		//フラグ
	int type;		//種類
	int img;		//画像表示用
	float x, y, r;	//座標、半径
	float speed;		//落下速度
	int score;		//スコア加算
	int color;		//色(仮)
};

//リンゴの変数
struct AppleDate gApple[APPLE_MAX];
struct AppleDate gApple2[APPLE_MAX];

//各リンゴのデータ
struct AppleDate gApple_Rd = {TRUE,0,0,0,-40,45,1,100,0xff0000};	//赤
struct AppleDate gApple_Br = {TRUE,1,0,0,-40,45,2,200,0x00ff00}; //青
struct AppleDate gApple_Gl = {TRUE,2,0,0,-40,45,3.5f,500,0xffff00}; //金
struct AppleDate gApple_Po = {TRUE,3,0,0,-40,45,0.5f,-750,0xff00ff}; //毒

//ステータス格納変数
struct AppleDate gAppleState[APPLE_TYPE];

//乱数格納変数
int gRandApple;

int a3, b3;
float c3;
float numi[APPLE_MAX];
int y;
int Aflg = 0;
int InitA = 0;

int apx[APPLE_MAX];
int apy[APPLE_MAX];
int apt[APPLE_MAX];
int apr[APPLE_MAX];

/**
* リンゴのデータ格納
*/
int AppleSet(void)
{
	gAppleState[0] = gApple_Rd;
	gAppleState[1] = gApple_Br;
	gAppleState[2] = gApple_Gl;
	gAppleState[3] = gApple_Po;

	return 0;
}
	
/**
* リンゴの描画
*/
void DrawApple(int& Pause_flg){


	for (int i = 0; i < APPLE_MAX; i++){
		
		// リンゴの表示
		if (gApple[i].flg == TRUE) {
			DrawCircle(gApple[i].x, gApple[i].y, gApple[i].r, gApple[i].img, TRUE);			

			if (Pause_flg == 0) {
				gApple[i].y += gApple[i].speed;
			}
			else
			{
				gApple[i].y = gApple[i].y;
				SetFontSize(20);
				DrawFormatString(490,350, 0x000000, "ポーズ中", gApple[i].speed);
			}


			//gAppleのy座標が1000以下になったとき消去
			if (gApple[i].y > 1000) {
				gApple[i].flg = FALSE;
			}
			DrawFormatString(0, 0, 0x000000, "speed:%f", gApple[i].speed);
			DrawFormatString(0, 20, 0x000000, "y:%d", gApple[i].y);
			DrawFormatString(0, 40, 0x000000, "r:%d", gApple[i].r);
			DrawFormatString(0, 60, 0x000000, "flg:%d", gApple[i].flg);
			DrawFormatString(0, 80, 0x000000, "type:%d", gApple[i].type);

			DrawFormatString(0, 200, 0x000000, "apr:%d", apr[i]);
			DrawFormatString(0, 220, 0x000000, "apt:%d", apt[i]);
			DrawFormatString(520, 400, 0x000000, "ｃ３＝%d", c3);

			



		}

		// リンゴの座標を引数として渡す
		GetApple(gApple[i].x,gApple[i].y,gApple[i].r);
		// プレイヤーとの当たり判定
		HitPlayer();
	}

	//生成関数の読み込み
	CreateApple();


	DrawFormatString(520, 420, 0x000000, "numi1＝%d", numi[0]);
	DrawFormatString(520, 440, 0x000000, "2＝%d", numi[1]);
	DrawFormatString(520, 460, 0x000000, "3＝%d", numi[2]);
	DrawFormatString(520, 480, 0x000000, "4＝%d", numi[3]);

}


/**
* リンゴの生成
**/
int CreateApple()
{
	//ステータスの読み込み
	AppleSet();

	for (int i = 0; i < APPLE_MAX; i++) {

		if (gApple[i].flg == FALSE) {

		

			gApple[i] = gAppleState[RandApple()];	//ステータスの格納

			gApple[i].img = gApple[i].color;
			gApple[i].x = GetRand(6) * 125 + 50;

		

			gApple[i].speed = gApple[i].speed;
			gApple[i].flg = TRUE;



			if (InitA == 0) {
				InitA = 1;
				apx[i] = gApple[i].x;
				apy[i] = gApple[i].y;
				apt[i] = gApple[i].type;
				apr[i] = gApple[i].r;
			}

			for (int j = 0; j < i; j++) {
				if (gApple[i].type == apt[j]) {

					//DrawString(490, 370, "iiiiiii", 0x000000);
					a3 = apx[j] - gApple[i].x;
					b3 = apy[j] - gApple[i].y;
					c3 = sqrt(a3 * a3 + b3 * b3);
					
					//被ってた場合typeを変更する気持ち
					if (gApple[i].x == apx[j] && c3 <= gApple[i].r+apr[j] && b3<= gApple[i].r + apr[j]) {

						//gAppleの中の使ってる値に別の値が入ってきてしまうから変わっちゃう説
						/*gApple[i].img = 0x000000;
						gApple[j].img = 0x00ffff;*/
						numi[i] = i;

						DrawString(490, 390, "aaaaaa", 0x000000);
						Aflg = 1;
					}
				}
			}
			
			if (Aflg == 1) {
				Aflg = 0;
				for (int i = 0; i < APPLE_MAX; i++) {
					if (numi[i] == 0) {

					}
					else {
						gApple[0].x += 10;
						gApple[0].img = 0x00ffff;
					}
					numi[i] = 0;
				}
			}

			DrawFormatString(0, 240, 0x000000, "x:%d", gApple[0].x);
			WaitTimer(100);
			apx[i] = gApple[i].x;
			apy[i] = gApple[i].y;
			apt[i] = gApple[i].type;
			apr[i] = gApple[i].r;

			
			return TRUE;
		}
	}

	//for (int i = 0; i < APPLE_MAX; i++) {
	//	if (gApple[i].flg == FALSE) {

	//		//for (int j = 1; j < i; j++) {
	//		//	if (apt[i] == apt[j]) {

	//		//		DrawString(490, 370, "iiiiiii", 0x000000);
	//		//		a3 = apx[i] - apx[j];
	//		//		b3 = apy[i] - apy[j];
	//		//		c3 = sqrt(a3 * a3 + b3 * b3);
	//		//		if (apx[i] == apx[j] && c3 <= apr[j]) {
	//		//			gApple[j].r += 5;
	//		//			DrawString(490, 390, "aaaaaa", 0x000000);
	//		//			Aflg = 1;
	//		//		}
	//		//	}
	//		//}
	//	}
	//}
	

	return FALSE;
}  

/**
* リンゴの出現率
*/
int RandApple()
{
	gRandApple = GetRand(100);	//0～100までの乱数を取得

	for (int i = 0; i < APPLE_MAX;i++)
	{
		//0～59以下の数値なら赤リンゴ(戻り値:0)
		if (gRandApple <= 59)
		{
			return 0;
		}
		//60～84以下の数値なら青リンゴ(戻り値:1)
		else if (gRandApple <=84 && gRandApple>=60)
		{
			return 1;
		}
		//85～94以下の数値なら金リンゴ(戻り値:2)
		else if (gRandApple <= 94 && gRandApple>=84)
		{
			return 2;
		}
		//95～100以下の数値なら毒リンゴ(戻り値:3)
		else if (gRandApple <= 100 && gRandApple>=94)
		{
			return 3;
		}
	}
}


