#include"DxLib.h"
#include"DrawApple.h"
#include"Player.h"
#include"math.h"
#include"Result.h"


int gAppleImg[APPLE_TYPE];
int gRandApple;
int Score;
int Count;

int Count_R;
int Count_B;
int Count_Go;
int Count_Po;

int a3, b3;
float c3;
float numi[APPLE_MAX];
float numi2[APPLE_MAX];
int y;
int Aflg = 0;
int Aflg2 = 0;
int InitA = 0;


int apx[APPLE_MAX];
int apy[APPLE_MAX];
int apt[APPLE_MAX];
int apr[APPLE_MAX];

int apx2[APPLE_MAX];
int apy2[APPLE_MAX];
int apt2[APPLE_MAX];
int apr2[APPLE_MAX];


//リンゴの変数
Apple::APPLE_DATA gApple[APPLE_MAX];
Apple::APPLE_DATA gTest[APPLE_MAX];

//ステータス格納変数
Apple::APPLE_DATA gAppleState[APPLE_TYPE];


/*
* コンストラクタ
*/
Apple::Apple()
{
	gScore.r = 0;
	gScore.b = 0;
	gScore.g = 0;
	gScore.p = 0;
	
	gAppleState[0] = gApple_Rd;
	gAppleState[1] = gApple_Bl;
	gAppleState[2] = gApple_Gl;
	gAppleState[3] = gApple_Po;

	
	gRandApple = 0;

}
/*
* デストラクタ
*/
Apple::~Apple()
{

}

/*
* リンゴのデータ格納
*/
int Apple::AppleSet(void)
{
	
	if ((gAppleImg[0] = LoadGraph("images/Apple_Red.png")) == -1)return -1;
	if ((gAppleImg[1] = LoadGraph("images/Apple_Blue.png")) == -1)return -1;
	if ((gAppleImg[2] = LoadGraph("images/Apple_Gold.png")) == -1)return -1;
	if((gAppleImg[3] = LoadGraph("images/Apple_Poison.png")) == -1)return -1;

	return 0;
}
	
/**
* リンゴの描画
*/
void Apple::DrawApple(int&Pause_flg){

	Player p;	
	Apple ap;
	Result result;

	//生成関数の読み込み
	Apple::CreateApple();

	for (int i = 0; i < APPLE_MAX; i++){

		// リンゴの表示
		if (gApple[i].flg == TRUE) {

			

			DrawRotaGraph(gApple[i].x, gApple[i].y, 0.25, 0, gApple[i].img, TRUE, TRUE);
			DrawCircle(gTest[i].x, gTest[i].y, gTest[i].r, 0x0000ff, TRUE);
			DrawFormatString(gApple[i].x, gApple[i].y, 0xffffff, "%d", i);
			DrawFormatString(gTest[i].x, gTest[i].y, 0xffffff, "%d", i);

			gApple[i].y += gApple[i].speed;
			gTest[i].y += gTest[i].speed;

			p.GetApple(&gApple[i]);
			result.GetAppScore(&gScore);

			//gAppleのy座標が1000以下になったとき消去
			if (gApple[i].y > 1000) {
				gApple[i].flg = FALSE;
			}

			//当たったら消える処理
			if (p.HitPlayer() == TRUE) {
				gApple[i].flg = FALSE;


				Score += gApple[i].score;
				if (Score < 0) {
					Score = 0;
				}

				if (gApple[i].type == 0)	gScore.r++;
				if (gApple[i].type == 1) 	gScore.b++;
				if (gApple[i].type == 2) 	gScore.g++;
				if (gApple[i].type == 3) {
					gScore.p++;
				}

			}
			
			DrawFormatString(0, 0, 0x000000, "Score:%d",Score);
			DrawFormatString(0, 20, 0x000000, "Red:%d", Count_R);
			DrawFormatString(0, 40, 0x000000, "Blue:%d", Count_B);
			DrawFormatString(0, 60, 0x000000, "Gold:%d", Count_Go);
			DrawFormatString(0, 80, 0x000000, "Count:%d", Count);


		}	
	}	
}

/**
* リンゴの生成
**/
int Apple::CreateApple()
{
	for (int i = 0; i < APPLE_MAX; i++) {
		if (gApple[i].flg == FALSE) {
			gApple[i] = gAppleState[RandApple()];	//ステータスの格納
			gApple[i].img = gAppleImg[gApple[i].type];
			gApple[i].x = GetRand(6) * 125 + 50;
			gApple[i].flg = TRUE;			
			

			for (int j = 0; j < APPLE_MAX; j++) {

				if (gApple[i].type == apt[j]) {

					a3 = apx[j] - gApple[i].x;
					b3 = apy[j] - gApple[i].y;
					c3 = sqrt(a3 * a3 + b3 * b3);

					//被ってた場合
					if (gApple[i].x == apx[j] && c3 <= gApple[i].r + apr[j] + 40) {
						numi[i] = 1;
						Aflg = 1;
					}
				}

				if (gApple[i].type == apt2[j])
				{

					a3 = apx2[j] - gApple[i].x;
					b3 = apy2[j] - gApple[i].y;
					c3 = sqrt(a3 * a3 + b3 * b3);

					//被ってた場合
					if (gApple[i].x == apx2[j] && c3 <= gApple[i].r + apr2[j] + 40)
					{
						Aflg = 1;
						numi2[i] = 1;
					}
				}

			}


			if (Aflg == 1) {
				Aflg = 0;
				//numi
				for (int i = 0; i < APPLE_MAX; i++) {
					if (numi[i] != 0) {

						gApple[i].flg = FALSE;

					}
					numi[i] = 0;


					if (numi2[i] != 0) {

						gApple[i].flg = FALSE;
					}
					numi2[i] = 0;
				}
			}


			apx[i] = gApple[i].x;
			apy[i] = gApple[i].y;
			apt[i] = gApple[i].type;
			apr[i] = gApple[i].r;

			return TRUE;	//成功

		}
	}

	for (int i = 0; i < APPLE_MAX; i++) {
		apx2[i] = gApple[i].x;
		apy2[i] = gApple[i].y;
		apt2[i] = gApple[i].type;
		apx[i] = 0;
		apy[i] = 0;
		apt[i] = 0;

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

int Apple::GetScore() {
	return Score;
}