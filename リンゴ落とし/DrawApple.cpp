#include"DxLib.h"
#include"DrawApple.h"
#include"Player.h"

int gAppleImg[APPLE_TYPE];
int gRandApple;

//ƒŠƒ“ƒS‚Ì•Ï”
Apple::APPLE_DATE gApple[APPLE_MAX];

//ƒXƒe[ƒ^ƒXŠi”[•Ï”
Apple::APPLE_DATE gAppleState[APPLE_TYPE];

Apple::Apple()
{
	gAppleState[0] = gApple_Rd;
	gAppleState[1] = gApple_Bl;
	gAppleState[2] = gApple_Gl;
	gAppleState[3] = gApple_Po;

	
	gRandApple = 0;

}

Apple::~Apple()
{

}
/*
* ƒŠƒ“ƒS‚Ìƒf[ƒ^Ši”[
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
* ƒŠƒ“ƒS‚Ì•`‰æ
*/
void Apple::DrawApple(void){

	Player p;


	for (int i = 0; i < APPLE_MAX; i++){

		// ƒŠƒ“ƒS‚Ì•\¦
		if (gApple[i].flg == TRUE) {
			DrawRotaGraph(gApple[i].x, gApple[i].y,0.25 ,0, gApple[i].img,TRUE, TRUE);
			gApple[i].y +=  gApple[i].speed * 2;
			p.GetApple(&gApple[i]);

			//gApple‚ÌyÀ•W‚ª1000ˆÈ‰º‚É‚È‚Á‚½‚Æ‚«Á‹
			if (gApple[i].y > 1000) {
				gApple[i].flg = FALSE;
			}

			//“–‚½‚Á‚½‚çÁ‚¦‚éˆ—‚É‚µ‚½‚¢
			if (p.HitPlayer() == TRUE) {
				gApple[i].flg = FALSE;
			}
			
			DrawFormatString(0, 0, 0x000000, "speed:%f", gApple[i].speed);
			DrawFormatString(0, 20, 0x000000, "A:%d",gApple[i]);
			DrawFormatString(0, 40, 0x000000, "r:%d", gApple[i].r);
			DrawFormatString(0, 60, 0x000000, "flg:%d", gApple[i].flg);
			DrawFormatString(0, 80, 0x000000, "type:%d", gApple[i].type);


		}	
	}

	//¶¬ŠÖ”‚Ì“Ç‚İ‚İ
	Apple::CreateApple();

}

/**
* ƒŠƒ“ƒS‚Ì¶¬
**/
int Apple::CreateApple()
{
	for (int i = 0; i < APPLE_MAX; i++) {
		if (gApple[i].flg == FALSE) {
			gApple[i].type = RandApple();				//
			gApple[i] = gAppleState[gApple[i].type];	//ƒXƒe[ƒ^ƒX‚ÌŠi”[
			gApple[i].img = gAppleImg[gApple[i].type];
			gApple[i].x = GetRand(7) * 125 + 50;
			gApple[i].flg = TRUE;
			return TRUE;	//¬Œ÷
		}
	}
	return FALSE;	//¸”s
}  

/**
* ƒŠƒ“ƒS‚ÌoŒ»—¦
*/
int Apple::RandApple()
{
	gRandApple = GetRand(100);	//0`100‚Ü‚Å‚Ì—”‚ğæ“¾

	for (int i = 0; i < APPLE_MAX;i++)
	{
		//0`59ˆÈ‰º‚Ì”’l‚È‚çÔƒŠƒ“ƒS(–ß‚è’l:0)
		if (gRandApple <= 59)
		{
			return 0;
		}
		//60`84ˆÈ‰º‚Ì”’l‚È‚çÂƒŠƒ“ƒS(–ß‚è’l:1)
		else if (gRandApple <=84 && gRandApple>=60)
		{
			return 1;
		}
		//85`94ˆÈ‰º‚Ì”’l‚È‚ç‹àƒŠƒ“ƒS(–ß‚è’l:2)
		else if (gRandApple <= 94 && gRandApple>=84)
		{
			return 2;
		}
		//95`100ˆÈ‰º‚Ì”’l‚È‚ç“ÅƒŠƒ“ƒS(–ß‚è’l:3)
		else if (gRandApple <= 100 && gRandApple>=94)
		{
			return 3;
		}
	}
}


