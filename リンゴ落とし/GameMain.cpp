#include "DxLib.h"
#include "GameMain.h"


//�ϐ��錾
int gBackImg;


/*****************
*�Q�[�����C��    *
*****************/
int LoadBackImg(void)
{
	if ((gBackImg = LoadGraph("images/title2.png")) == -1)return -1;
	return 0;
}

/*****************
*���\��          *
*****************/
void DrawBack(void)
{
	LoadBackImg();
	DrawExtendGraph(0, 0, 1000, 720, gBackImg, TRUE);
}