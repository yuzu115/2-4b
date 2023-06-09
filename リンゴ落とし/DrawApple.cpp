#include"DxLib.h"
#include"DrawApple.h"
#include"Player.h"
#include"Resalt.h"

int gAppleImg[APPLE_TYPE];
int gRandApple;

int Score;
int Count;

int Count_R;
int Count_B;
int Count_Go;
int Count_Po;


//リンゴの変数
Apple::APPLE_DATA gApple[APPLE_MAX];

//ステータス格納変数
Apple::APPLE_DATA gAppleState[APPLE_TYPE];


/*
* コンストラクタ
*/
Apple::Apple()
{
	
	gAppleState[0] = gApple_Rd;
	gAppleState[1] = gApple_Bl;
	gAppleState[2] = gApple_Gl;
	gAppleState[3] = gApple_Po;

	
	gRandApple = 0;

	gScore.r = 0;
	gScore.b = 0;
	gScore.g = 0;
	gScore.p = 0;

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
void Apple::DrawApple(void){

	Player p;	
	Apple ap;

	//生成関数の読み込み
	Apple::CreateApple();

	for (int i = 0; i < APPLE_MAX; i++){

		// リンゴの表示
		if (gApple[i].flg == TRUE) {

			

			DrawRotaGraph(gApple[i].x, gApple[i].y,0.25 ,0, gApple[i].img,TRUE, TRUE);
			//DrawCircle(gApple[i].x, gApple[i].y, gApple[i].r, 0xffffff, TRUE);
			gApple[i].y +=  gApple[i].speed ;
	

			p.GetApple(&gApple[i]);
			GetAppScore(&gScore);

			//gAppleのy座標が1000以下になったとき消去
			if (gApple[i].y > 1000) {
				gApple[i].flg = FALSE;
			}

			//当たったら消える処理にしたい
			if (p.HitPlayer() == TRUE) {
				gApple[i].flg = FALSE;

				Score += gApple[i].score;


				if (gApple[i].type == 0)	gScore.r++;
				if (gApple[i].type == 1) 	gScore.b++;
				if (gApple[i].type == 2) 	gScore.g++;
				if (gApple[i].type == 3)	gScore.p++;

			}

			
			
			DrawFormatString(0, 0, 0x000000, "Score:%d",Score);
			DrawFormatString(0, 20, 0x000000, "Red:%d", gScore.r);
			DrawFormatString(0, 40, 0x000000, "Blue:%d", gScore.b);
			DrawFormatString(0, 60, 0x000000, "Gold:%d", gScore.g);
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

			for (int j = 0; j < APPLE_MAX; j++)
			{
				if (i == j)continue;
				
				if (gApple[i].x == gApple[j].x && gApple[i].type == gApple[i].type)
				{
					if (gApple[i].y < gApple[j].r * 2) {
						gApple[i].y -= 100;
					}
					
				}

			}

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
	gRandApple = GetRand(100);	//0〜100までの乱数を取得

	for (int i = 0; i < APPLE_MAX;i++)
	{
		//0〜59以下の数値なら赤リンゴ(戻り値:0)
		if (gRandApple <= 59)
		{
			return 0;
		}
		//60〜84以下の数値なら青リンゴ(戻り値:1)
		else if (gRandApple <=84 && gRandApple>=60)
		{
			return 1;
		}
		//85〜94以下の数値なら金リンゴ(戻り値:2)
		else if (gRandApple <= 94 && gRandApple>=84)
		{
			return 2;
		}
		//95〜100以下の数値なら毒リンゴ(戻り値:3)
		else if (gRandApple <= 100 && gRandApple>=94)
		{
			return 3;
		}
	}
}

int Apple::GetScore()
{
	return Score;
}
