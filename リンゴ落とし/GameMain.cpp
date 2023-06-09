#include "DxLib.h"
#include "GameMain.h"


//変数宣言
int gBackImg;


/*****************
*ゲームメイン    *
*****************/
int LoadBackImg(void)
{
	if ((gBackImg = LoadGraph("images/title2.png")) == -1)return -1;
	return 0;
}

/*****************
*仮表示          *
*****************/
void DrawBack(void)
{
	LoadBackImg();
	DrawExtendGraph(0, 0, 1000, 720, gBackImg, TRUE);
}