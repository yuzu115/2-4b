#include"DxLib.h"
#include"DrawApple.h"
#include"Player.h"

#define APPLE_MAX  10	//リンゴの最大生成数
#define APPLE_TYPE  4		//リンゴの種類
#define APPLE_SIZE  400

struct APPLE_DATE {
	int flg;		//フラグ
	int type;		//種類
	int img;		//画像表示用
	float x, y, r;		//座標、半径
	float speed;		//落下速度
	int score;		//スコア加算
	float size;		//当たり判定の倍率
};
//リンゴの変数
struct APPLE_DATE gApple[APPLE_MAX];

//各リンゴのデータ
struct APPLE_DATE gApple_Rd = { TRUE,0,0,0,-40,45,1,100,1.1f };	//赤
struct APPLE_DATE gApple_Bl = { TRUE,1,0,0,-40,45,2,200,1.1f }; //青
struct APPLE_DATE gApple_Gl = { TRUE,2,0,0,-40,45,3.5f,500,1.1f }; //金
struct APPLE_DATE gApple_Po = { TRUE,3,0,0,-40,45,0.5f,-750,0.9f }; //毒

//ステータス格納変数
struct APPLE_DATE gAppleState[APPLE_TYPE];


int gAppleImg[APPLE_TYPE];
int gRandApple;


/*
* リンゴのデータ格納
*/
int Apple::AppleSet(void)
{
	
	gAppleState[0] = gApple_Rd;
	gAppleState[1] = gApple_Bl;
	gAppleState[2] = gApple_Gl;
	gAppleState[3] = gApple_Po;

	if ((gAppleImg[0] = LoadGraph("images/Apple_Red.png")) == -1)return -1;
	if ((gAppleImg[1] = LoadGraph("images/Apple_Blue.png")) == -1)return -1;
	if ((gAppleImg[2] = LoadGraph("images/Apple_Gold.png")) == -1)return -1;
	if((gAppleImg[3] = LoadGraph("images/Apple_Poison.png")) == -1)return -1;

	return 0;
}
	
/**
* リンゴの描画
*/
void Apple::DrawApple(void){

	DrawRotaGraph(100, 100, 0.25, 0, gAppleImg[0], TRUE, TRUE);

	for (int i = 0; i < APPLE_MAX; i++){
		
		//リンゴのスコアデータを渡す
		//GetDate(gApple[i].score);
		// プレイヤーとの当たり判定
		//PlayerScore();

		// リンゴの表示
		if (gApple[i].flg == TRUE) {
			DrawRotaGraph(gApple[i].x, gApple[i].y,0.25 ,0, gApple[i].img,TRUE, TRUE);
			gApple[i].y +=  gApple[i].speed * 2;


			//gAppleのy座標が1000以下になったとき消去
			if (gApple[i].y > 1000) {
				gApple[i].flg = FALSE;
			}

			//当たったら消える処理にしたい
			/*if (HitPlayer(&gApple[i], &gPlayer) == TRUE) {
				gApple[i].flg = FALSE;
			}
			*/

			DrawFormatString(0, 0, 0x000000, "speed:%f", gApple[i].speed);
			DrawFormatString(0, 20, 0x000000, "A:%d",gApple[i]);
			DrawFormatString(0, 40, 0x000000, "r:%d", gApple[i].r);
			DrawFormatString(0, 60, 0x000000, "flg:%d", gApple[i].flg);
			DrawFormatString(0, 80, 0x000000, "type:%d", gApple[i].type);


		}	
	}

	//生成関数の読み込み
	Apple::CreateApple();

}

/**
* リンゴの生成
**/
int Apple::CreateApple()
{
	for (int i = 0; i < APPLE_MAX; i++) {
		if (gApple[i].flg == FALSE) {
			gApple[i].type = RandApple();				//
			gApple[i] = gAppleState[gApple[i].type];	//ステータスの格納
			gApple[i].img = gAppleImg[gApple[i].type];
			gApple[i].x = GetRand(7) * 125 + 50;
			gApple[i].flg = TRUE;
			return TRUE;	//成功
		}
	}
	return FALSE;	//失敗
}  

/**
* リンゴの出現率
*/
int Apple::RandApple()
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


