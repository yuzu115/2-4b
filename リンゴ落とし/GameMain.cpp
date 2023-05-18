#include "DxLib.h"
#include "GameMain.h"


//•Ï”éŒ¾
int gBackImg;


/*****************
*ƒQ[ƒ€ƒƒCƒ“    *
*****************/
int LoadBackImg(void)
{
	if ((gBackImg = LoadGraph("images/title2.png")) == -1)return -1;
	return 0;
}

/*****************
*‰¼•\¦          *
*****************/
void DrawBack(void)
{
	LoadBackImg();
	DrawExtendGraph(0, 0, 1000, 720, gBackImg, TRUE);
}